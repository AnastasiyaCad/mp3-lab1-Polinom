/*#include <iostream>
//#include <string>
#include "polinom.h"

using namespace std;

void main() {
	int p;
	int p1[] = {5, 4, 3};
	int p2[] = { 4, 2, 1 };
	int p3[] = { 2, 1, 1 };
	int p4[] = { 5, 4, 3 };
	int p5[] = { 4, 2, 1 };
	int p6[] = { 4, 3, 2 };
	int p7[] = { 1, 1, 1 };
	TPolinom *pol1 = new TPolinom();
	TPolinom *pol2 = new TPolinom();
	TPolinom *pol4 = new TPolinom();
	pol1->SetCurrent(6, p1);
	pol1->SetCurrent(-3, p2);
	pol1->SetCurrent(7, p3);
	pol2->SetCurrent(6, p4);
	pol2->SetCurrent(10, p5);
	pol4->SetCurrent(3, p6);
	pol4->SetCurrent(-5, p7);

	TPolinom *pol3 = new TPolinom();
	*pol3 = *pol1 + *pol2;
	pol1->Show();
	cout << "+";
	pol2->Show();
	cout << "=";
	pol3->Show();
	cout << '\n';

	*pol3 = *pol1 - *pol2;
	pol1->Show();
	cout << "-";
	pol2->Show();
	cout << "=";
	pol3->Show();
	cout << '\n';

	*pol3 = *pol1 * *pol2;
	pol1->Show();
	cout << "-";
	pol2->Show();
	cout << "=";
	pol3->Show();
	cout << '\n';

	cout << "(";
	pol1->Show();
	cout << ")' = ";
	*pol3 = pol3->F(*pol1);
	pol3->Show();
	cout << '\n';

	cout << "f(";
	pol2->Show();
	cout << ")dx = ";
	*pol3 = pol3->f(*pol2);
	pol3->Show();
	cout << '\n';


	pol1->Show();
	cout << "/";
	pol2->Show();
	cout << "=";
	*pol3 = *pol2 / *pol4;
	pol3->Show();
	cout << '\n';

	cin >> p;
}*/