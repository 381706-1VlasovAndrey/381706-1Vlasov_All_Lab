#pragma once
#include <iostream>
#include "ExceptionsLib.h"

using namespace std;

template <class T>
class TStack
{
protected:
  int size; 
  int top;  
  T* mas;  
public:
  TStack(int _size = 0);            
  TStack(TStack<T> &a);         
  virtual ~TStack();
  T Get();                  
  void Put(T e);                
  int GetSize();
  bool IsFull();
  bool IsEmpty();               
  void Print();             

  int operator!=(const TStack<T>& stack) const; 
  int operator==(const TStack<T>& stack) const;
  TStack& operator=(const TStack<T>& stack);
};

template <class T>
TStack<T>::TStack(int _size)
{
  if (_size < 0)
	throw MyException("Wrong stack size");
if (_size == 0)
  {
	size = 0;
	top = 0;
	mas = NULL;
  }
	else
	{
	  size = _size;
	  top = 0;
	  mas = new T[size];
	  for (int i = 0; i < size; i++)
	    mas[i] = 0;
	}
}

template <class T>
TStack<T>::TStack(TStack<T>& a)
{
  size = a.size;
  top = a.top;
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
TStack <T>::~TStack()
{
  top = 0;
  size = 0;
  delete[] mas;
}

template <class T>
int TStack<T>::GetSize()
{
  return size;
}

template <class T>
T TStack<T>::Get()
{
  if (IsEmpty())
	throw MyException("Stack is empty");
  top--;
  return mas[top];
}

template <class T>
void TStack<T>::Put(T e)
{
  if (IsFull())
	throw MyException("Stack is full");
  else
	{
	mas[top] = e;
	top++;
	}
}

template <class T>
bool TStack<T>::IsFull()
{
  if (top > size - 1)
	return 1;
  return 0;
}

template <class T>
bool TStack<T>::IsEmpty()
{
  if (top == 0)
	return 1;
  return 0;
}

template <class T>
void TStack<T>::Print()
{
  cout << "Stack: ";
  for (int i = top - 1; i >= 0; i--)
	cout << mas[i] << " ";
}

template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& s)
{
  if (this != &s)
  {
    delete[] mas;
	top = s.top;
	size = s.size;
	mas = new T[size];
	for (int i = 0; i < size; i++)
	  mas[i] = s.mas[i];
  }
  return *this;
}

template <class T>
int TStack<T>::operator==(const TStack<T>& s) const
{
  if (top != s.size)
	return 0;
  if (size != s.top)
	return 0;
  for (int i = 0; i < top; i++)
    if (mas[i] != s.mas[i])
	  return 0;
  return 1;
}

template <class T>
int TStack<T>::operator!=(const TStack<T>& s) const
{
  return !(*this == s);
}