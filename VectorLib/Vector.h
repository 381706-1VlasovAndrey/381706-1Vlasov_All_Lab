#pragma once
#include <iostream>
#include "ExceptionsLib.h"

using namespace std;

template <class T>
class TVector
{
protected:
  T *mas;     
  int size;      
public:
  TVector(int _size = 0);
  TVector(const TVector &a);
  virtual ~TVector();
  int GetSize() const;                      
  virtual T& operator[](int i);           
  bool operator==(const TVector &a) const;      
  bool operator!=(const TVector &a) const;      
  virtual TVector& operator=(const TVector &a); 
  TVector operator+(const T &e);   
  TVector operator-(const T &e);   
  TVector operator*(const T &e);   
  TVector operator+(const TVector &a);     
  TVector operator-(const TVector &a);     
  T operator*(const TVector &a);           
  template <class T1>
  friend istream& operator>>(istream &istr, TVector<T1> &a);
  template <class T1>
  friend ostream& operator<<(ostream &ostr, const TVector<T1> &a);
};

template <class T>
TVector<T>::TVector(int _size)
{
  if (_size < 0)
	throw MyException("Wrong vector size");
  else
    if (_size == 0)
	{
	  size = _size;
	  mas = NULL;
	}
    else
	{
	  size = _size;
	  mas = new T[size];
	  for (int i = 0; i < size; i++)
		mas[i] = 0;
	}
}

template <class T>
TVector<T>::TVector(const TVector<T> &a)
{
  size = a.size;
  if (size == 0)
	mas = NULL;
  else
  {
	mas = new T[size];
	for (int i = 0; i < size; i++)
	  mas[i] = a.mas[i];
  }
} 

template<class T>
TVector<T>::~TVector()
{
  if (size > 0)
  {
	size = 0;
	delete[] vec;
	mas = NULL;
  }
} 

template <class T>
int TVector<T>::GetSize() const
{
  return size;
}

template <class T>
T& TVector<T>::operator[](int i)
{
  if (i >= 0 && i < size)
	return mas[i];
  else
	throw MyException("Wrong index");
} 

template <class T>
bool TVector<T>::operator==(const TVector &a) const
{
  if (size != a.size)
	return 0;
  else
	for (int i = 0; i < size; i++)
	  if (mas[i] != a.mas[i])
	  {
		return 0;
	  }
  return 1;
} 

template <class T>
bool TVector<T>::operator!=(const TVector &a) const
{
  return !(*this == a);
} 

template <class T>
TVector<T>& TVector<T>::operator=(const TVector &a)
{
  if (this != &a)
  {
	delete[] mas;
	size = a.size;
	mas = new T[size];
	for (int i = 0; i < size; i++)
	  mas[i] = a.mas[i];
  }
  return *this;
} 

template <class T>
TVector<T> TVector<T>::operator+(const T &e)
{
  TVector<T> res(*this);
  for (int i = 0; i < size; i++)
	res.mas[i] += e;
  return res;
} 

template <class T>
TVector<T> TVector<T>::operator-(const T &e)
{
  TVector<T> res(*this);
  for (int i = 0; i < size; i++)
	res.mas[i] -= e;
  return res;
} 

template <class T>
TVector<T> TVector<T>::operator*(const T &e)
{
  TVector<T> res(*this);
  for (int i = 0; i < size; i++)
	res.mas[i] = res.mas[i] * e;
  return res;
} 

template <class T>
TVector<T> TVector<T>::operator+(const TVector<T> &a)
{
  if (size != a.size)
	throw MyException("Different size operand");
  TVector<T> rez(*this);
  for (int i = 0; i < size; i++)
	rez[i] = (*this)[i] + a.mas[i];
  return rez;
} 

template <class T>
TVector<T> TVector<T>::operator-(const TVector<T> &a)
{
  if (size != a.size)
	throw MyException("Different size operand");
  TVector<T> rez(*this);
  for (int i = 0; i < size; i++)
	rez[i] = (*this)[i] - a.mas[i];
  return rez;
} 

template <class T>
T TVector<T>::operator*(const TVector<T> &a)
{
  if (size != a.size)
	throw MyException("Different size operand");
  int rez = 0;
  for (int i = 0; i < size; i++)
	rez += mas[i] * a.mas[i];
  return rez;
} 

template <class T>
istream& operator>>(istream &istr, TVector<T> &a)
{
  for (int i = 0; i < a.size; i++)
	istr >> a.mas[i];
  return istr;
}

template <class T>
ostream& operator<<(ostream &ostr, const TVector<T> &a)
{
  cout << "Vector: ( ";
  for (int i = 0; i < a.size; i++)
	ostr << a.mas[i] << ' ';
  cout << ")";
  return ostr;
}