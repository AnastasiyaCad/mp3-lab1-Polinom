#pragma once
//#include<iterator>
#include"monom.h"
#include<iostream>
using namespace std;

//template <class T>
class TPolinom
{
private:
	TMonom *pFirst;         //указатель на первое звено списка
	TMonom *pLast;          //указатель на последнее звено списка
	int ListLen;          //количество звеньев в списке

public:
	TPolinom() {
		this->ListLen = 0;
	}

	TPolinom(TMonom *fr, int ln) {
		this->pFirst = fr;
		//this->pLast = ls;
		this->ListLen = ln;
	}

	TMonom* GetFirst() {
		return pFirst;
	}

	TMonom* GetLast() {
		return pLast;
	}

	int GetLen() {
		return ListLen;
	}

	void SetLast(TMonom *p) {
		pLast = p;
	}

	void SetLen(int p) {
		ListLen = p;
	}

	friend TPolinom operator+(const TPolinom& pol1, const TPolinom& pol2) {
		TPolinom *pRes = new TPolinom();
		TMonom *p1, *p2;
		bool pr;
		p1 = pol1.pFirst;
		for (int i = 0; i < pol1.ListLen; i++) {
			p2 = pol2.pFirst;
			pr = true;
			for (int j = 0; j < pol2.ListLen; j++) {
				//for(int k = 0; k < 3; k++){
				int ind1 = p1->GetIndex();
				int ind2 = p2->GetIndex();
				if (ind1 == ind2) {
					pRes->SetCurrent(p1->GetCoeff() + p2->GetCoeff(), p1->GetMasIndex());
					pr = false;
				}
				p2 = p2->GetNext();
			}
			if (pr) {

				pRes->SetCurrent(p1->GetCoeff(), p1->GetMasIndex());
			}
			p1 = p1->GetNext();
		}
		return *pRes;
	}

	friend TPolinom operator-(const TPolinom& pol1, const TPolinom& pol2) {
		TPolinom *pRes = new TPolinom();
		TMonom *p1, *p2;
		bool pr;
		p1 = pol1.pFirst;
		for (int i = 0; i < pol1.ListLen; i++) {
			p2 = pol2.pFirst;
			pr = true;
			for (int j = 0; j < pol2.ListLen; j++) {
				int ind1 = p1->GetIndex();
				int ind2 = p2->GetIndex();
				if (ind1 == ind2) {
					pRes->SetCurrent(p1->GetCoeff() - p2->GetCoeff(), p1->GetMasIndex());
					pr = false;
				}
				p2 = p2->GetNext();
			}
			if (pr) {

				pRes->SetCurrent(p1->GetCoeff(), p1->GetMasIndex());
			}
			p1 = p1->GetNext();
		}
		return *pRes;
	}

	friend TPolinom operator*(const TPolinom& pol1, const TPolinom& pol2) {
		TPolinom *pRes = new TPolinom();
		TMonom *p1, *p2;
		p1 = pol1.pFirst;
		int ind3[3];
		for (int i = 0; i < pol1.ListLen; i++)
		{
			p2 = pol2.pFirst;
			for (int j = 0; j < pol2.ListLen; j++)
			{
				for (int k = 0; k < 3; k++) {
					int ind1 = p1->GetIndex(k);
					int ind2 = p2->GetIndex(k);
					ind3[k] = ind1 + ind2;
				}
				pRes->SetCurrent(p1->GetCoeff() * p2->GetCoeff(), ind3);
				p2 = p2->GetNext();
			}
			p1 = p1->GetNext();
		}
		return *pRes;
	}

	friend TPolinom operator/(const TPolinom& pol1, const TPolinom& pol2) {
		TPolinom *pRes = new TPolinom();
		TPolinom *mp = new TPolinom();
		TMonom *p1, *p2, *r, *m;
		p2 = pol2.pFirst;
		p1 = pol1.pFirst;
		r = pRes->pFirst;
		m = mp->pFirst;
		int ind3[3];
		//for (int i = 0; i < pol1.ListLen; i++)
		int pr1 = p1->GetIndex(0);
		int pr5 = p1->GetIndex(2);
		int pr3 = p1->GetIndex(1);
		int pr2 = p2->GetIndex(0);
		
		int pr4 = p2->GetIndex(1);
		
		int pr6 = p2->GetIndex(2);
		while ((pr1 > pr2) || (pr3 > pr4) || (pr5 > pr6))
		{
			
		/*	if ((p1->GetIndex(0) < p2->GetIndex(0)) || (p1->GetIndex(1) < p2->GetIndex(1)) || (p1->GetIndex(2) < p2->GetIndex(2)))
			{
				break;
			}*/
			for (int k = 0; k < 3; k++) {
				int tmp1 = p1->GetIndex(k);
				int tmp2 = p2->GetIndex(k);
				ind3[k] = tmp1 - tmp2;
			}
			pRes->SetCurrent(p1->GetCoeff() / p2->GetCoeff(), ind3);
			/*m = r;
			r = r->GetNext();*/
			for(int j =0; j < pol2.ListLen; j++)
			{
				for (int i = 0; i < 3; i++) {
					m->SetIndex(i, p2->GetIndex(i) + r->GetIndex(i));
				}
				m->SetCoeff(p2->GetIndex(j) * m->GetIndex(j));
				mp->SetCurrent(m->GetCoeff(), m->GetMasIndex());
			}
			for (int j = 0; j < pol2.ListLen; j++) {
				int ind1 = p1->GetIndex(j);
				int ind2 = p2->GetIndex(j);
				if (ind1 == ind2) {
					pRes->SetCurrent(p1->GetCoeff() - p2->GetCoeff(), p1->GetMasIndex());
				//	pr = false;
				}
				p2 = p2->GetNext();
			}
			p1 = p1->GetNext();
		}
		return *pRes;
	}

	TPolinom& F(const TPolinom& pol)
	{
		TPolinom *pRes = new TPolinom();
		TMonom *p, *r;
		p = pol.pFirst;
		r = pRes->pFirst;
		int coef;
		for(int i = 0; i < pol.ListLen; i++)
		{
			coef = p->GetCoeff();
			coef *= p->GetIndex(0);
			int* tmp = p->GetMasIndex();
			for (int j = 0; j < 3; j++)
			{
				if (j == 0)
				{
					tmp[j] = p->GetIndex(j) - 1;
				}
			}
			pRes->SetCurrent(coef, tmp);
			
		   // r->SetIndex(tmp);
			p = p->GetNext();
			//r = r->GetNext();
		}
		return *pRes;
	}

	TPolinom& f(const TPolinom& pol)
	{
		TPolinom *pRes = new TPolinom();
		TMonom *p;
		p = pol.pFirst;
		int coef;
		for (int i = 0; i < pol.ListLen; i++)
		{
			coef = p->GetCoeff();
			//coef /= p->GetIndex(0);
			p->SetIndex(0, p->GetIndex(0) + 1);
			pRes->SetCurrent(coef = coef / p->GetIndex(0), p->GetMasIndex());
			p = p->GetNext();
		}
		return *pRes;
	}

	TPolinom& operator=(const TPolinom& pol) {
		this->Clean();
		pFirst = pol.pFirst;
		pLast = pol.pLast;
		ListLen = pol.ListLen;
		return *this;
	}

	void Clean() {
		if (GetLen() > 0) {
			TMonom *tmp;
			tmp = pFirst;
			TMonom *pNext;
			for (int i = 0; i < ListLen; i++) {
				pNext = tmp->GetNext();
				delete tmp;
				tmp = pNext;
			}
			this->pFirst = nullptr;
			this->pLast = nullptr;
			this->ListLen = 0;
		}
	}

	void Show() {
		TMonom *tmp;
		tmp = pFirst;
		bool pr = true;
		for (int i = 0; i < ListLen; i++) {
			if ((tmp->GetCoeff() != 0)) {
				if ((tmp->GetCoeff() > 0) && (!pr)) {
					cout << '+';
				}
				cout << tmp->GetCoeff();
				cout << 'x' << '^' << tmp->GetIndex(0);
				cout << 'y' << '^' << tmp->GetIndex(1);
				cout << 'z' << '^' << tmp->GetIndex(2);

				pr = false;
			}
			tmp = tmp->GetNext();
		}
	}

	void SetCurrent(int coeff, int index[]) {
		TMonom *p = new TMonom(coeff, index);
		TMonom *tmp;
		if (ListLen == 0) {
			pFirst = p;
			pLast = p;
		}
		else {
			pLast->SetNext(p);
			pLast = p;
		}
		ListLen++;
	}
};


