#include"TList.h"
#include"TPolinom.h"

TPolinom::TPolinom(const TPolinom & pl)
{
	this->startpolinom = pl.startpolinom;
	this->Polinom = pl.Polinom;
}

int TPolinom::GetDegree(char p)
{
	if (int(p) > 49 && int(p) < 58)
		return int(p - 48);
	else return 1;
}

void TPolinom::ToMonom()
{
	int c = 0;
	string tmp;
	//Monom m = {};
	Monom m;
	TList<Monom>::iterator it;
	bool sing = true;
	for (int i = 0; i < startpolinom.size(); i++)
	{
		m = {};
		if (startpolinom[i] == '+')
		{
			sing = true;
			i++;
		}
		else if (startpolinom[i] == '-')
		{
			sing = false;
			i++;
		}
		if (!IsOperation(startpolinom[i]) && !XYZ(startpolinom[i]))
		{
			while (!XYZ(startpolinom[i]) && i != startpolinom.size() && !IsOperation(startpolinom[i]))
			{
				tmp += startpolinom[i];
				i++;
			}
			m.koef = atof(tmp.c_str());
			tmp = "";
			if (!sing)
				m.koef = m.koef*(-1);
		}
		c = i;
		if (XYZ(startpolinom[i]))
		{
			int degree;
			int x = 0, y = 0, z = 0;
			while (!IsOperation(startpolinom[i]) && i != startpolinom.size())
			{
				switch (startpolinom[i]) {
				case 'x':
				{
					string tmpx;
					i++;
					while (!IsOperation(startpolinom[i]) && i != startpolinom.size() && !XYZ(startpolinom[i]))
					{
						tmpx += startpolinom[i];
					//	x = GetDegree(startpolinom[i + 1]);
						i++;
					}
					x = atoi(tmpx.c_str());
					break;
				}
				case 'y':
				{
					string tmpy;
					i++;
					while (!IsOperation(startpolinom[i]) && i != startpolinom.size() && !XYZ(startpolinom[i]))
					{
						tmpy += startpolinom[i];
						//	x = GetDegree(startpolinom[i + 1]);
						i++;
					}
					y = atoi(tmpy.c_str());
					break;
				}
				case 'z':
				{
					string tmpz;
					i++;
					while (!IsOperation(startpolinom[i]) && i != startpolinom.size() && !XYZ(startpolinom[i]))
					{
						tmpz += startpolinom[i];
						//	x = GetDegree(startpolinom[i + 1]);
						i++;
					}
					z = atoi(tmpz.c_str());
					break;
				}
				default:
				{
					i++;
					break; //
				}
				}
			}
			i--;
			degree = x * 10000 + y * 100 + z; // 10^2 100 
			m.name = startpolinom.substr(c, i - c + 1);
			m.degree = degree;

		}
		if (Polinom.Empty())
		{
			Polinom.Push(m);
			continue;
		}
		for (it = Polinom.Begin(); it != Polinom.End(); it++) // it
		{
			if (m.degree == it->data.degree)
			{
				it->data.koef = it->data.koef + m.koef;
				if (it->data.koef == 0)
					Polinom.Erase(it);
				break;
			}
			if (m.degree > it->data.degree)
			{
				Polinom.Insert(it, m); // ins
				break;
			}
		}
		if (it == Polinom.End())
		{
			Polinom.Push(m);
		}
	}
}

int TPolinom::DegreePr(char op)
{
	if (op == 'x')
		return 1;
	if (op == 'y')
		return 2;
	if (op == 'z')
		return 3;
	return 0;
}

bool TPolinom::IsOperation(char elem)
{
	return (elem == '+' || elem == '-') ? true : false;
}

bool TPolinom::XYZ(char op)
{
	if ((op == 'x') || (op == 'y') || (op == 'z'))
		return true;
	else
		return false;
}
bool TPolinom::Operand(char op)
{
	for (char i = '0'; i <= '9'; i++)
		if (op == i)
			return true;
	if (op == '.')
		return true;
	return false;
}

bool TPolinom::Proverka(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (!Operand(str[i]) || (!XYZ(str[i])) || (!IsOperation(str[i])))
		{
			throw "ERROR!!!";
		}
	}

}

int TPolinom::Calculate(int _x, int _y, int _z)
{
	int res = 0;
	for (auto it = Polinom.Begin(); it != Polinom.End(); it++)
	{
		int x = it->data.degree / 10000;
		int y = (it->data.degree / 100) % 100;
		int z = it->data.degree % 100;
		res += (pow(_x, x) * pow(_y, y) * pow(_z, z)) * it->data.koef;
	}
	return res;
}

TPolinom TPolinom::operator+(TPolinom & pl)
{
	if (this->Polinom.Empty() || pl.Polinom.Empty())
		throw "ERROR!!";
	TPolinom main, side, result;
	TList<Monom>::iterator it1, it2;
	if (this->Polinom.GetSize() >= pl.Polinom.GetSize())
	{
		main = *this;
		side = pl;
		it1 = this->Polinom.Begin();
		it2 = pl.Polinom.Begin();
	}
	else
	{
		main = pl;
		side = *this;
		it1 = pl.Polinom.Begin();
		it2 = this->Polinom.Begin();
	}
	for (it1; it1 != main.Polinom.End();)
	{
		if (it1->data.degree == it2->data.degree)
		{
			if ((it1->data.koef + it2->data.koef) != 0)
				result.Polinom.Push(*(it1)+*(it2));
			++it1; ++it2;
		}
		else if (it1->data.degree > it2->data.degree)
		{
			result.Polinom.Push(*it1);
			++it1;
		}
		else if (it1->data.degree < it2->data.degree)
		{
			result.Polinom.Push(*it2);
			++it2;
		}
	}
	while (it2 != side.Polinom.End())
	{
		result.Polinom.Push(*it2);
		++it2;
	}
	return result;
}
TPolinom TPolinom::operator-(TPolinom & pl)
{
	if (this->Polinom.Empty() || pl.Polinom.Empty())
		throw "ERROR!!";
	TPolinom main, side, result;
	TList<Monom>::iterator it1, it2;
	if (this->Polinom.GetSize() >= pl.Polinom.GetSize())
	{
		main = *this;
		side = pl;
		it1 = this->Polinom.Begin();
		it2 = pl.Polinom.Begin();
	}
	else
	{
		main = pl;
		side = *this;
		it1 = pl.Polinom.Begin();
		it2 = this->Polinom.Begin();
	}
	for (it1; it1 != main.Polinom.End();)
	{
		if (it1->data.degree == it2->data.degree)
		{
			if ((it1->data.koef - it2->data.koef) != 0)
				result.Polinom.Push(*(it1)-*(it2));
			++it1; ++it2;
		}
		else if (it1->data.degree > it2->data.degree)
		{
			result.Polinom.Push(*it1);
			++it1;
		}
		else if (it1->data.degree < it2->data.degree)
		{
			result.Polinom.Push(*it2);
			++it2;
		}
	}
	while (it2 != side.Polinom.End())
	{
		result.Polinom.Push(*it2);
		++it2;
	}
	return result;
}
TPolinom & TPolinom::operator=(const TPolinom & pl)
{
	this->Polinom = pl.Polinom;
	this->startpolinom = pl.startpolinom;
	return *this;
}
bool TPolinom::operator==(const TPolinom & pl)const
{
	if (this->startpolinom == pl.startpolinom)
		return true;
	else return false;
}

bool TPolinom::operator!=(const TPolinom & pl)const
{
	return !(this->startpolinom == pl.startpolinom);
}
ostream & operator<<(ostream & os, TPolinom & pl)
{
	if (pl.Polinom.Empty())
		os << pl.startpolinom;
	else
	{
		for (auto it = pl.Polinom.Begin(); it != pl.Polinom.End(); ++it)
		{
			if (it != pl.Polinom.Begin() && it->data.koef > 0)
				os << '+';
			if (it->data.koef != 1)
				os << it->data.koef;
			os << it->data.name;
		}
	}
	return os;
}
istream & operator>>(istream & is, TPolinom & pl)
{
	is >> pl.startpolinom;
	return is;
}

TPolinom TPolinom::operator*(TPolinom & pl)
{
	if (this->Polinom.Empty() || pl.Polinom.Empty())
		throw "ERROR!!";
	TPolinom main, side, result;
	TList<Monom>::iterator it1, it2;
	if (this->Polinom.GetSize() >= pl.Polinom.GetSize())
	{
		main = *this;
		side = pl;
		it1 = this->Polinom.Begin();
		it2 = pl.Polinom.Begin();
	}
	else
	{
		main = pl;
		side = *this;
		it1 = pl.Polinom.Begin();
		it2 = this->Polinom.Begin();
	}
	for (it1; it1 != main.Polinom.End();)
	{
		for (it2; it2 != main.Polinom.End();)
		{
			if ((it1->data.koef * it2->data.koef) != 0)
				result.Polinom.Push(*(it1) * *(it2));
			++it2;
		}
		++it1;
	}
	return result;
}