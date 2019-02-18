#pragma once
#include "Vector.h"

using namespace std;

template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
  TMatrix(int _size = 10);
  TMatrix(const TMatrix &a);
  TMatrix(const TVector<TVector<T> > &a);
  virtual ~TMatrix();
  T GetDet();
  bool operator==(const TMatrix &a) const;    
  bool operator!=(const TMatrix &a) const;      
  TMatrix& operator=(const TMatrix &a);         
  TMatrix operator+(const TMatrix &a);          
  TMatrix operator-(const TMatrix &a);          
  TMatrix<T> operator*(const TMatrix<T> &a);    
  TMatrix<T> operator/(const TMatrix<T> &a);    
  template <class T2>
  friend istream& operator>>(istream &istr, TMatrix<T2> &a);
  template <class T2>
  friend ostream& operator<<(ostream &ostr, const TMatrix<T2> &a);
};

template <class T>
TMatrix<T>::TMatrix(int _size) :TVector<TVector<T> >(_size)
{
  if (_size <= 0 )
	throw MyException("Wrong matrix size");
  for (int i = 0; i < _size; i++)
	this->mas[i] = TVector<T>(i + 1);
}

template <class T>
TMatrix<T>::TMatrix(const TMatrix<T> &a) :TVector<TVector<T> >(a)
{
}

template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T> > &a) : TVector<TVector<T> >(a)
{
}

template <class T>
TMatrix<T>::~TMatrix()
{
}

template <class T>
T TMatrix<T>::GetDet()
{
  T det = 1;
  for (int i = 0; i < TMatrix<T>::size; i++)
  {
	det = det * (*this)[i][i];
  }
  return det;
}

template <class T >
bool TMatrix<T>::operator==(const TMatrix<T> &a) const
{
  return TVector<TVector<T> >::operator==(a);
} 

template <class T>
bool TMatrix<T>::operator!=(const TMatrix<T> &a) const
{
  return TVector<TVector<T> >::operator!=(a);
} 

template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &a)
{
  TVector<TVector<T> >::operator=(a);
  return *this;
}

template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &a)
{
  if (this->size != a.size)
	throw MyException("Different size operand");
  else
	return TVector<TVector<T> >::operator+(a);
}

template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &a)
{
  if (this->size != a.size)
	throw MyException("Different size operand");
  else
	return TVector<TVector<T> >::operator-(a);
}

template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T> &a)
{
  if (this->size != a.size)
	throw MyException("Different size operand");
  TMatrix <T> temp(this->size);
  for (int i = 0; i < this->size; i++)
	for (int j = 0; j <= i; j++) 
	  for (int k = 0; k < i - j + 1; k++)
		temp[i][j] +=this->mas[i][k + j] * a.mas[k + j][j];
  return temp;
}

template <class T>
TMatrix<T> TMatrix<T>::operator/(const TMatrix<T> &a)
{
  if (this->size != a.size)
	throw MyException("Wrong size operand");
  T det = this->GetDet();
  if ((det < 0.000001) && (det > -0.000001))
	throw MyException("Determinant = 0");
  TMatrix<T> copyA(*this);
  TMatrix<T> rez(TMatrix<T>::size);
  for (int i = 0; i < rez.size; i++) 
  {
	rez[i][i] = 1;
	T t = copyA[i][i];
	for (int j = 0; j <= i; j++) 
	{
	  copyA[i][j] = copyA[i][j] / t;
	  rez[i][j] = rez[i][j] / t; 
	}
  }

  for (int j = 0; j < rez.size - 1; j++)
  {
	for (int i = j + 1; i < rez.size; i++)
	{
	  for (int k = 0; k <= j; k++)
		rez[i][k] = rez[i][k] - copyA[i][j] * rez[j][k];
	}
  }
  return ((*this)*rez);
}

template <class T2>
istream& operator>>(istream &istr, TMatrix<T2> &a)
{
  for (int i = 0; i < a.size; i++)
	for (int j = 0; j <= i; j++)
	  istr >> a.mas[i][j];
  return istr;
}

template <class T2>
ostream & operator<<(ostream &ostr, const TMatrix<T2> &a)
{
  cout << "Matrix: ( ";
  for (int i = 0; i < a.size; i++) 
  {
	for (int j = 0; j <= i; j++) {
	  ostr << a.mas[i][j] << "\t";
	}
	ostr << endl;
  }
  return ostr;
}