// 2semDemo1binary.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

struct application
{
	char fio[40];
	int age;
	char edu;
	int kitchen[4];
	int experience;
	int one_place_period;
	int number_change_work;
	int dismiss_from_office;
};

int main()
{
	ifstream in("Kazan_restaurant.txt");
	ofstream out("Pretendent.bin", ios::binary);

	if (!in)
	{
		cout << "Can't open file!" << endl;
		exit(-1);
	}

	application x, a[100];
	int i = 0;
	while (in >> x.fio >> x.age >> x.edu >> x.kitchen[0] >> x.kitchen[1] >> x.kitchen[2] >> x.kitchen[3]
		>> x.experience >> x.one_place_period >> x.number_change_work >> x.dismiss_from_office)
	{
		if ((x.age <= 50) && (x.edu == '1' || x.edu == '2') && (x.kitchen[0] || x.kitchen[1]) && (x.experience >= 5)
			&& (x.one_place_period * 2 >= x.experience) && (x.number_change_work <= 1) && (x.number_change_work <= 5))
		{
			a[i] = x;
			i++;
		}
	}
	in.close();
	int j, k = i + 1;

	//order
	for (i = 0; i <= k - 1; i++)
		for (j = 0; j <= k - 1; j++)
			if (a[i].experience < a[j].experience)
			{
				x = a[i];
				a[i] = a[j];
				a[j] = x;
			}

	cout << "Enter number of vacant seats: ";
	int n;
	cin >> n;

	if (k < n)
	{
		cout << "Predentents less than necessary!";
		exit(1);
	}

	for (i = 0; i < n; i++)
		out.write((char*)&a[i], sizeof(struct application));
	out.close();

	ifstream in_bin("Pretendent.bin", ios::binary);

	bool b = false;
	for (i = 0; i < n; i++)
	{
		in_bin.read((char*)&x, sizeof(struct application));
		if ((x.age <= 45) && (x.edu == '2') && (x.experience >= 15)
			&& (x.dismiss_from_office == 0) && (x.number_change_work <= 2))
		{
			b = true;
			cout << x.fio << ' ' << x.age << endl;
		}
	}
	in_bin.close();
	if (!b)
		cout << "There are no such" << endl;
	system("pause");
	return 0;
}
