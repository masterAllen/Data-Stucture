#ifndef LINKEDBASE_H_
#define LINKEDBASE_H_

#include <iostream>
#include <cstring>
#include <string>
#include "chain.h"
using namespace std;

//链表实现：加权有向图-->加权无向图，无权有向图-->无权无向图 
template <class T>
class LinkedBase
{
	public:
		LinkedBase(int vertice = 10);
		~LinkedBase(){}
		
		int Edges(){return e;}
		int Vertices(){return n;}

		int InDegree(int i);
	protected:
		int n;
		int e;
		Chain<T> *chain;
};

template <class T>
LinkedBase<T>::LinkedBase(int vertice)
{
	n = vertice;
	e = 0;
	chain = new Chain<T> [n+1];//chain[0]不用 
}

template <class T>
int LinkedBase<T>::InDegree(int i)
{
	return chain[i]->Length();
}
#endif
