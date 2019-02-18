#pragma once
#include "Stack.h"

using namespace std;

template <class T>
class TQueue : public TStack<T>
{
protected:
  int start;             
  int count;             
public:
  TQueue(int _size = 0);     
  TQueue(TQueue <T> &a); 
  virtual ~TQueue();     
  void Put(T e);         
  T Get();               
  bool IsFull();          
  bool IsEmpty();        
  void Print();
};

template <class T>
TQueue<T>::TQueue(int _size) : TStack<T>(_size)
{
  start = 0;
  count = 0;
}

template <class T>
TQueue<T>::TQueue(TQueue<T> &a) : TStack<T>(a)
{
  start = a.start;
  count = a.count;
}

template <class T>
TQueue<T>::~TQueue()
{
  count = 0;
  start = 0;
}

template <class T>
void TQueue<T>::Put(T e)
{
  if (IsFull())
	throw MyException("Queue is full");
  else
	{
	TStack<T>::Put(e);
    TStack<T>::top = TStack<T>::top % TStack<T>::size;
	count++;
	}
}

template <class T>
T TQueue<T>::Get()
{
  if (IsEmpty())
	throw MyException("Queue is empty");
  else
	{
	T temp = TStack<T>::mas[start];
	start = (start + 1) % TStack<T>::size;
	count--;
	return temp;
	}
}

template <class T>
bool TQueue<T>::IsFull()
{
  if (count == TStack<T>::size)
	return 1;
  return 0;
}

template <class T>
bool TQueue<T>::IsEmpty()
{
  if (count == 0)
	return 1;
  return 0;
}

template<class T>
void TQueue<T>::Print()
{
  cout << "Stack: ";
  for (int i = start; i < TStack<T>::top; i = (i + 1) % TStack<T>::size)
	cout << TStack<T>::mas[i] << " ";
}