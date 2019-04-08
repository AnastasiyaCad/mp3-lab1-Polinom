#pragma once
#include<iostream>

//template <class T>
class TMonom {
	int Coeff;       
	int Index[3];       
	TMonom *pNext;    
public:
	TMonom(int cf, int arr[]) {
		Coeff = cf;
		for (int i = 0; i < 3; i++) {
			Index[i] = arr[i];
		}
		this->pNext = nullptr;
	}
	void SetCoeff(int cf) {
		Coeff = cf;
	}
	void SetIndex(int arr[]) {
		for (int i = 0; i < 3; i++) {
			Index[i] = arr[i];
		}
	}
	void SetIndex(int num, int ind) {
	
		Index[num] = ind;
	}
	int GetCoeff() {
		return Coeff;
	}
	int GetIndex(int num) {
		/*for (int i = 0; i < 3; i++) 
		{
			if (i == num) {
				return Index[i];
			}
		}*/
		int tmp = Index[num];
		return tmp;
	}
	int GetIndex()
	{
		int tmp = 0;
		for(int i = 0; i < 3; i++)
		{
			tmp *= 10;
			tmp += Index[i];
		}
		return tmp;
	}
	int* GetMasIndex()
	{
		return Index;
	}

	TMonom& operator=(const TMonom &mp) {
		Coeff = mp.Coeff;
		for (int i = 0; i < 3; i++) {
			Index[i] = mp.Index[i];
		}
		return *this;
	}

	void SetNext(TMonom *ptr) {
		pNext = ptr;
	}

	TMonom* GetNext() {
		return pNext;
	}
};
