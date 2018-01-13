#ifndef LINEARLIST_H_
#define LINEARLIST_H_

#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include "xcept.h"
using namespace std;

template<class T>
class LinearList
{
	public:
		LinearList(int MaxSize=10);
		~LinearList()
		{
			delete [] element;
			//删除指针应该这样做 
		}		
		bool isEmpty() const
		{
			return length==0;
		}
		int Length() const
		{
			return length;
		}
		T Find(int k) const;
 
		int ReturnPos(const T& x);
 
		LinearList<T>& Delete(int k);
	
		LinearList<T>& Insert(int k,const T& x);
		
		LinearList<T>& Append(const T& x);
	
		void Output(ostream& os) const;
	private:
		//lenght-->real 
		int length;
		//size-->数组大小 
		int MaxSize;
		T *element;
		
};

template<class T>
LinearList<T>::LinearList(int MaxListSize)
{
	MaxSize = MaxListSize;
	element = new T[MaxSize];
	length = 0;
}

template<class T>
T LinearList<T>::Find(int k) const
{
	if(k<1||k>length)	throw OutOfBounds();
	T x = element[k-1];
	return x;
}

template<class T>
int LinearList<T>::ReturnPos(const T& x)
{
	for(int i=0;i<length;i++)
	{
		if(x = element[i])
			return ++i;
	}
	
	return -1;
}

template<class T>
LinearList<T>& LinearList<T>::Delete(int k)
{
	if(k<1||k>length)
	{
		throw OutOfBounds();
	}
	
	for(int i=k;i<length;i++)
	{
		element[i-1] = element[i];
	}
	
	return *this;
}

template<class T>
LinearList<T>& LinearList<T>::Insert(int k,const T& x)
{
	if(k<0||k>length) throw OutOfBounds();
	if(length==MaxSize)	throw NoMem();
	for(int i=length-1;i>=k;i--)
	{
		element[i+1] = element[i];
	}
	
	element[k] = x;
	length++;
	return *this;
}

template <class T>
LinearList<T>& LinearList<T>::Append(const T &x)
{
	if(length==MaxSize) throw NoMem();
	element[length] = x;
	length++;
	
	return *this;
}
template<class T>
void LinearList<T>::Output(ostream& out) const
{
	for(int i=0;i<length;i++)
	{
		out<<element[i]<<" ";
	}
}

template<class T>
ostream& operator<<(ostream& out,const LinearList<T>& x)
{
	x.Output(out);
	return out;
}
#endif
