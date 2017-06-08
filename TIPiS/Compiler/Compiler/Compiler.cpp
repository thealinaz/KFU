//1.2.2
#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	char a[15];
	int n, i;
	cin >> a;
	if (a[0] >= 'A' & a[0] <= 'Z') {
		if ((a[1] >= 'A' & a[1] <= 'Z') || (a[1] >= '1' & a[1] <= '9')) {
			if (a[2] == ':' & a[3] == '=') {
				if ((a[4] == '(') || ((a[1] >= 'A' & a[1] <= 'Z') && (a[1] >= '1' & a[1] <= '9'))) {
					if ((a[5] == '+') || (a[5] == '-')) {
						for (i = 6;i<10;i++)
							if (a[i] >= '0' & a[i] <= '9')
								continue;
						if (a[11] == ',') {
							for (i = 12;i <= 16;i++)
								if (a[i] >= '0' & a[i] <= '9')
									continue;
							if (a[17] == ',') {
								for (i = 18;i <= 22;i++)
									if (a[i]<'0' | a[i]>'9') {
										cout << "it isn't' correct";
										return 0;
									}
							} else 
								cout << "you've forgotten ','";
							if (a[23] == ')')
								cout << (a[24] == ';' ? "it's correct!" : "You've forgotten ';'");
							else cout << "it isn't correct.You've forgotten ')'";
						} else 
							cout << "it isn't correct.You've forgotten ','";
					} else 
						cout << "it isn't correct.You've forgotten '+' or '-'";
				} else 
					cout << "it isn't correct.You've forgotten '(' or you haven't entered word or number";
			} else
				cout << "it isn't correct.You've forgotten ':' or '=' ";
		} else 
			cout << "it isn't correct.You haven't entered a word or a number'";
	} else
		cout << "it isn't correct.You haven't entered a word'";
	cout << endl;
	system("pause");
}