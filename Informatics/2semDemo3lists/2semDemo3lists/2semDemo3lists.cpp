#include "stdafx.h"
#include <iostream>
using namespace std;


struct node
{
	int data;
	node* next;
};

bool empty_list(node *top)
{
	return top == NULL;
}


void push_list(node* &top, int data) {
	node* temp = new node;
	temp->data = data;
	temp->next = NULL;
	if (!top) {
		top = temp;
	}
	else {
		temp->next = top;
		top = temp;
	}
}

void create_list(node* &top, int t) {
	int data;
	top = NULL;
	for (int i = 0; i < t; i++) {
		cout << "\tdata = ";
		cin >> data;
		push_list(top, data);
	}
}

void create_array_of_lists(node** tops, int l) {
	int n;
	for (int i = 0; i < l; i++)
	{
		cout << "Enter list size: ";
		cin >> n;
		create_list(tops[i], n);
	}
}

void show_list(node* top) {
	node* p = top;
	while (p->next)
	{
		cout << p->data << "->";
		p = p->next;
	}
	cout << p->data;
}

void show_array_of_list(node** tops, int l) 
{
	for (int i = 0; i < l; i++)
	{
		cout << "List[" << i + 1 << "]: ";
		if (!empty_list(tops[i]))
			show_list(tops[i]);
		else cout << "empty";
		cout << "\n";
	}
}

bool prime(int x) {
	bool f = true;
	if (x <= 1) return false;
	if (x == 2) return true;
	for (int i = 2; i <= sqrt(x) && f; i++)
		if (x % i == 0) f = false;
	return f;
}

int max_list(node* top) {
	int max = top->data;
	node* p = top;
	while (p)
	{
		if (p->data > max)
			max = p->data;
		p = p->next;
	}
	return max;
}

int sum_max_list(node** tops, int l)
{
	int sum = 0;
	for (int i = 0; i < l; i++)
	{
		sum += max_list(tops[i]);
	}
	return sum;
}

int sum_prime_list(node** tops, int l) 
{
	int sum = 0;
	for (int i = 0; i < l; i++)
	{
		while (!empty_list(tops[i])) 
		{
			if (prime(tops[i]->data)) sum += tops[i]->data;
			tops[i] = tops[i]->next;
		}
	}
	return sum;
}

bool EA(node** tops, int l)
{
	bool f = true;
	bool t = false;
	for (int i = 0; i < l && !t; i++) 
	{
		f = true;
		node* p = tops[i];
		while (p && f) 
		{
			if (p->data <= 0) f = false;
			p = p->next;
		}
		t = f;
	}
	return t;
}


int main()
{
	int l;
	node** arr_list;
	cout << "Enter size of array of lists: "; cin >> l;
	arr_list = new node*[l];

	create_array_of_lists(arr_list, l);

	show_array_of_list(arr_list, l);

	if (EA(arr_list, l))
		cout << "\nMax " << sum_max_list(arr_list, l);
	else
		cout << "\nPrime " << sum_prime_list(arr_list, l);
	system("pause");
}