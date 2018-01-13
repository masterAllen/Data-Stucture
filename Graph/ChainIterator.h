#ifndef CHAINITERATOR_H_
#define CHAINITERATOR_H_
#include <iostream>
#include <cstring>
#include <string>
#include "Chain.h"

using namespace std;

template <class T>
class ChainIterator
{
	public:
		T* Intialize(Chain<T> &input)
		{
			current = input.first;
			if(current)
				return &(current->data);
		}
		
		T* Next()
		{
			current = current->link;
			if(current)
				return &(current->data);
		}
	private:
		ChainNode<T> *current;
};
#endif
