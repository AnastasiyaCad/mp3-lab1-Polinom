#ifndef __UNARRAY_H__
#define __UNARRAY_H__

#include"TPolinom.h"
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;
const int MAXSIZEARR = 1000;
typedef string TKey;
template <class T1, class T2>
class TUnArray
{
	struct line
	{
		T1 key;
		// int
		T2 data;
		line(T1 _k = {}, T2 _data = {})
		{
			key = _k;
			data = _data;
		}
	};
	line *Polinom;
	int size;
	int Num; // количество записей
	int LastItem; // 0 -не перемещен последний, 1 - перемещен
	
public:
	TUnArray()
	{
		size = MAXSIZE;
		Polinom = new line[size];
		Num = 0;
		LastItem = 0;
	}
	TUnArray(int _size)
	{
		if ((_size < 1) || (_size > MAXSIZE))
			throw "size";
		size = _size;
		Polinom = new line[size];
		Num = 0;
		LastItem = 0;
	}

	bool TUnArray::Proverka(int _size)
	{
		if ((_size < 1) || (_size > MAXSIZE))
		{
			throw "ERROR!!!";
		}
	}

	//пустота
	bool IsEmpty()
	{
		return Num == 0;
	}
	//заполнена
	bool IsFull()
	{
		return Num == MAXSIZE;
	}
	//найти
	int ToFindUnArr(T1 _k)
	{
		if (!IsEmpty())
		{
			for (int i = 0; i < Num; i++)
			{
				if (Polinom[i].key == _k)
				{
					return i;
				}
			}
			return -1; //запись не найдена
		}
		return -2; // таблица пуста, введите полином
	}

	T2 GetData(int i)
	{
		return Polinom[i].data;
	}

	T1 GetKey(int i)
	{
		return Polinom[i].key;
	}

/*	Polinom ToFindUnArr2(int it) // в мейне
	{
		if (it < 0)
		{
			count << "Такой записи не существует";
			throw "Polinom doesn`t exist";
		}
		else
		{
			return Polinom[i].data;
		}
	}*/
	//вставить
	void ToInsertUnArr(T1 _k, T1 _p) //+polinom  TXT
	{
		if (!IsFull())
		{
			if (LastItem == 0)
			{
				line P;
				P.key = _k;
				P.data = _p;
				Num++;
				Polinom[Num] = P;
			}
			if (LastItem == 1)
			{
				line P;
				P.key = _k;
				P.data = _p;
				Polinom[Num] = P;
			}
		}
		else
			throw "Is Fuuk in ToInsertUnArr";
	}

	T1 EnterToDelete()
	{
		T1 name;
		//count << "Удалите старую запись";
		//count << "Введите имя полинома";
		cin >> name;
		return name;
	}

	void ToDeleteUnArr(T1 _k)
	{
		int i = ToFindUnArr(_k);
		if (i > -1)
		{
			if (i != Num) //с этим ли сравниввать? массив то с 0, подумай
			{
				Polinom[i].key = Polinom[Num].Key;
				Polinom[i].data = Polinom[Num].data;
				LastItem = 1;
			}
			else
			{
				LastItem = 1;
			}

		}
		else throw "UsArr is emply";
	}
	//удалить
};

#endif