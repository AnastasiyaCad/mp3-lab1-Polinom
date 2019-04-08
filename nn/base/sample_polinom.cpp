#include <iostream>
#include <string>
#include <list>
//#include"polinom.h"
#include "TPolinom.h"
#include "HeArr.h"
#include "postfix.h"

using namespace std;

int main()
{
	string expression1, expression2;
	double res;

	setlocale(LC_ALL, "Russian");
/*	TPolinom mypl2, mypl1;
	cout << "Enter first polynomial: ";
	cin >> mypl1;
	cout << "Enter second polynomial: ";
	cin >> mypl2;
	TPolinom mypl3;
	//TPolinom mypl1(expression1);
	cout << "E";
	//TPolinom mypl2("x9y9+xy+1"), mypl1("x8y8+x3y3+xy+27"), mypl3;
	mypl1.ToMonom();
	//	cout << "E";
		//cout << mypl1;
	mypl2.ToMonom();
	cout << "E";

	cout << mypl3;
	cout << "E";
	cout << mypl2 + mypl1;*/

	cout << "Выбор таблицы \n"; 
	cout << "1- массив неупорядоченный \n";
	cout << "2 - массив упорядоченный \n";
	cout << "3 - список \n";
	cout << "4 - дерево \n";
	cout << "5 - хеш-таблица 1 \n";
	cout << "6 - хеш-таблица 2 \n";
	int t1;
	cin >> t1;
	switch (t1)
	{
	case 1:
	{
		cout << "Введите размер таблицы: \n"; //
		int size;
		cin >> size;
		if ((size > 100) || (size < 1))
		{
			cout << "Размер таблицы выходит за диапазон";
			throw "ERROR SIZE";
		}
		TUnArray tabl(size);
		TPolinom mypl1;
		cout << "Введите имя полинома (целые числа): \n"; //
		int name;
		cin >> name;
		int t;
		/*t = tabl.ProverkaName2(name);
		while (t == 0)
		{
			cout << "Имя занято\n";
			cout << "Введите имя полинома (целые числа): \n"; //
			cin >> name;
			t = tabl.ProverkaName2(name);
		}*/
		cout << "Введите полином: \n";
		cin >> mypl1;
		mypl1.ToMonom();
		tabl.ToInsertUnArr(name, mypl1);
		tabl.Enter();

		cout << "0 - Операции с полиномом \n";
		cout << "1 - Добавить полином \n";
		cout << "2 - Производная от полинома \n";
		cout << "3 - Интеграл от полинома \n";
		int tmp;
		cin >> tmp;
		switch (tmp)
		{
		case(0):
		{
			if (!tabl.GetNum())
			{
				cout << "Недостаточно полиномов \n";
				TPolinom mypl3;
				cout << "Введите имя полинома (целые числа): \n"; //
				int name;
				cin >> name;
				cout << "Введите полином: \n";
				cin >> mypl3;
				mypl3.ToMonom();
				tabl.ToInsertUnArr(name, mypl3);
				tabl.Enter();
			}
	
			tabl.Enter();
			cout << "Введите выражение вида a+b, где a и b - имена полинома \n";
			cout << "Доступные операции: +, -, *, /, % \n";
			cout << "\n";
			cout << "Введите значение \n";
			string tr;
			cin >> tr;
			TPostfix p(tr);
			p.ToPostfix();
			cout << "Результат: \n";
			int ik = p.Calculate22(tabl);
			cout << tabl.ToFindUnArr2(ik);
			break;
		}
		case(1):
		{
			int tm = tmp;
			while (tm == 1)
			{
				TPolinom mypl2;
				cout << "Введите имя полинома (целые числа): \n"; //
				int name1;
				cin >> name1;
				/*int tm;
				tm = tabl.ProverkaName(name1);
				while (tm == 0)
				{
					cout << "Имя занято\n";
					cout << "Введите имя полинома (целые числа): \n"; //
					cin >> name1;
					tm = tabl.ProverkaName(name1);
				}*/
				t = tabl.ProverkaName2(name1);
				while (t == 0)
				{
					cout << "Имя занято\n";
					cout << "Введите имя полинома (целые числа): \n"; //
					cin >> name1;
					t = tabl.ProverkaName2(name1);
				}
				cout << "Введите полином: \n";
				cin >> mypl2;
				mypl2.ToMonom();
				tabl.ToInsertUnArr(name1, mypl2);
				tabl.Enter();

				cout << "Ввести еще полином? 0 - нет, 1 - да \n";
				cin >> tm;
			}
			break;
		}
		case 2:
		{
			TPolinom mypl2;
			cout << "Enter name polynomial: \n";
			int name;
			cin >> name;
			cout << "Enter polynomial: \n";
			cin >> mypl2;
			mypl2.ToMonom();
			tabl.ToInsertUnArr(name, mypl2);

			tabl.Enter();

			cout << "Введите значение \n";
			string tr;
			cin >> tr;
			TPostfix p(tr);
			p.ToPostfix();
			cout << "Результат: \n";
			int ik = p.Calculate22(tabl);
			cout << tabl.ToFindUnArr2(ik);
			break;
		}
		default:
		{

		}
		}
		//хотим еще?
		//1 - да. 0 - нет
		// если нет, то какие манипуляции
		// завершение 
		//вывод всего

	/*	cout << "Enter name: \n";
		int i;
		cin >> i;
		int u = tabl.ToFindUnArr(i);
		cout << u;
		TPolinom m2;
		m2 = tabl.GetData(u);
		cout << m2;*/
		break;
	}
	case 2:
	{
		break;
	}
	case 3:
	{		break;
	}
	case 4:
	{		break;
	}
	case 5:
	{		break;
	}
	case 6:
	{		break;
	}
	default: break;
	}
/*
	int s1;
	cout << "1 - add polynomials \n"; // ввод полинома
	cout << "2 - subtract polynomials \n";
	cout << "3 - calculate polynomial \n";
	cin >> s1;
	switch (s1)
	{
	case 1:
	{
		TPolinom mypl2, mypl1;
		cout << "Enter first polynomial: ";
		cin >> mypl1;
		cout << "Enter second polynomial: ";
		cin >> mypl2;
		mypl1.ToMonom();
		mypl2.ToMonom();
		cout << mypl1 + mypl2 << "\n";
		break;
	}
	case 2:
	{
		TPolinom mypl2, mypl1;
		cout << "Enter first polynomial: ";
		cin >> mypl1;
		cout << "Enter second polynomial: ";
		cin >> mypl2;
		mypl1.ToMonom();
		mypl2.ToMonom();
		cout << mypl1 - mypl2 << "\n";
		break;
	}
	case 3:
	{
		TPolinom p;
		cout << "Enter polynomial: ";
		cin >> p;
		int x, y, z;
		cout << "Enter x: \n";
		cin >> x;
		cout << "Enter y: \n";
		cin >> y;
		cout << "Enter z: \n";
		cin >> z;
		p.ToMonom();
		cout << p.Calculate(x, y, z) << "\n";
		break;
	}
	}*/
	return 0;
}
