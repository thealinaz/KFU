//1.2.1
#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

void create(ifstream& in, bool** matrix);
void show(ofstream& out, bool** matrix, int n);
void show(ofstream& out, int* vector, int n);
void show(ofstream& out, bool* vector, int n);
void toVector(bool** matrix, int* notSortedVector, int n);
void order(int* notSorted, int* sorted, int n);
bool condition1(int certainVector, bool** matrix, bool* minSupportSet, int n);
bool condition2(int certainVector, bool** matrix, bool* minSupportSet, int n);

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	cout << "Enter number of vertexex:";
	int n, i, j;
	cin >> n;

	bool** matrix = new bool*[n];
	for (i = 0; i < n; i++)
		matrix[i] = new bool[n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			matrix[i][j] = false;

	if (!in) {
		cout << "Can not open file" << endl;
		exit(-1);
	}
	create(in, matrix);
	in.close();
	show(out, matrix, n);

	int* notSortedVector = new int[n];
	int* sortedVector = new int[n];
	for (i = 0; i < n; i++) {
		notSortedVector[i] = 0;
		sortedVector[i] = 0;
	}

	toVector(matrix, notSortedVector, n);

	out << "Vector:\n";
	show(out, notSortedVector, n);
	order(notSortedVector, sortedVector, n);
	out << "Ordered vector:\n";
	show(out, sortedVector, n);

	bool* minSupportSet = new bool[n];
	for (i = 0; i < n; i++)
		minSupportSet[i] = true;

	for (i = 0; i < n; i++)
		if (condition1(sortedVector[i], matrix, minSupportSet, n)
			|| condition1(sortedVector[i], matrix, minSupportSet, n))
			minSupportSet[sortedVector[i]] = true;
		else
			minSupportSet[sortedVector[i]] = false;
	out << "Minimal support set:\n";
	show(out, minSupportSet, n);

	system("pause");
	return 0;
}

void create(ifstream& in, bool** matrix)
{
	int a, b;
	while (in) {
		in >> a >> b;
		matrix[a][b] = true;
		matrix[b][a] = true;
	}
}

void show(ofstream& out, bool** matrix, int n)
{
	out << "Adjacency matrix:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			out << matrix[i][j] << ' ';
		out << endl;
	}
	out << endl;
}

void show(ofstream& out, int* vector, int n)
{
	out << "{ ";
	for (int i = 0; i < n; i++)
		out << vector[i] << ' ';
	out << "}\n\n";
}

void show(ofstream& out, bool* vector, int n)
{
	out << "{ ";
	for (int i = 0; i < n; i++)
		out << vector[i] << ' ';
	out << "}\n\n";
}

void toVector(bool** matrix, int* vector, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (matrix[i][j]) vector[i]++;
}

void order(int* notSorted, int* sorted, int n)
{
	int* help = new int[n + 1];
	for (int i = 0; i < n; i++)
		help[i] = notSorted[i];
	help[n] = n;
	for (int i = 0; i < n; i++) {
		int min = n;
		for (int j = 0; j < n; j++)
			if (help[j] < help[min]) min = j;
		sorted[i] = min;
		help[min] = n;
	}
}

bool condition1(int certainVector, bool** matrix, bool* minSupportSet, int n)
{
	bool flag = true;
	for (int j = 0; j < n; j++) {
		if (matrix[certainVector][j] && minSupportSet[j]) {
			flag = false;
			break;
		}
	}
	return flag;
}

bool condition2(int certainVector, bool** matrix, bool* minSupportSet, int n)
{
	bool flag = false;
	for (int y = 0; y < n; y++) {
		if (matrix[certainVector][y] && !minSupportSet[y]) {
			flag = true;
			for (int j = 0; j < n; j++)
				if (matrix[y][j] && minSupportSet[j] && (j != certainVector))
					flag = false;
			if (flag) break;
		}
	}
	return flag;
}