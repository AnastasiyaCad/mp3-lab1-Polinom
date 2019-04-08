#ifndef __UNARRAY_H__
#define __UNARRAY_H__

#include"TPolinom.h"
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;
const int MAXSIZEARR = 1000;
typedef string TKey;

class TUnArray
{
	struct line
	{
		int key;
		TPolinom data;
		line(int _k = {}, TPolinom _data = {})
		{
			key = _k;
			data = _data;
		}
		line& operator=(line &tmp)
		{
			data = tmp.data;
			key = tmp.key;
			return *this;
		}
	};
	line *Polinom;
	int size;
	int Num; // индекс последнего занятого
	int LastItem; // 0 -не перемещен последний, 1 - перемещен

public:
	friend class TPostfix;
	TUnArray()
	{
		size = MAXSIZE;
		Polinom = new line[size];
		Num = -1;
		LastItem = 0;
	}
	TUnArray(int _size)
	{
		size = _size;
		if ((size < 1) || (size > MAXSIZE))
			throw "size";
		Polinom = new line[size];
		Num = -1;
		LastItem = 0;
	}

	bool TUnArray::GetNum()
	{
		return Num >= 2;
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
		return Num == -1;
	}
	//заполнена
	bool IsFull()
	{
		return Num == size - 1;
	}
	//найти
	int ToFindUnArr(int _k)
	{
		if (!IsEmpty())
		{
			for (int i = 0; i < Num + 1; i++)
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

	TPolinom ToFindUnArr2(int _k)
	{
		if (!IsEmpty())
		{
			for (int i = 0; i < Num + 1; i++)
			{
				if (Polinom[i].key == _k)
				{
					return Polinom[i].data;
				}
			}
		}
	}

	TPolinom GetData(int i)
	{
		return Polinom[i].data;
	}

	int GetKey(int i)
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
	void ToInsertUnArr(int _k, TPolinom _p) //+polinom  TXT
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

	void Enter()
	{
		for (int i = 0; i <= Num; i++)
		{
			cout << Polinom[i].key << "  |  " << Polinom[i].data << "\n";
		}
	}

	void ToDeleteUnArr(int _k)
	{
		int i = ToFindUnArr(_k);
		if (i > -1)
		{
			if (i != Num) //с этим ли сравниввать? массив то с 0, подумай
			{
				Polinom[i].key = Polinom[Num].key;
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

	// провера на имя
	bool ProverkaName(int _k)
	{
		for (int i = 0; i < Num; i++)
		{
			if (GetKey(i) == _k)
			{
				return 0;
			}
		}
		return 1;

	
	}

	bool ProverkaName2(int _k)
	{
		return ToFindUnArr(_k) == -1;
	}
};

#endif