#ifndef HBLTNODE_H_
#define HBLTNODE_H_
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

template <class T> class MaxHBLT;

template <class T>
class HBLTNode
{
	friend MaxHBLT<T>;
	public:
		HBLTNode();
		HBLTNode(const T& data);
		HBLTNode(const T& data,int s);
	private:
		T data;
		int s;
		
		HBLTNode<T> *left;
		HBLTNode<T> *right;
};

template <class T>
HBLTNode<T>::HBLTNode()
{
	data = 0;
	s = 0;
	left = right = 0;
}

template <class T>
HBLTNode<T>::HBLTNode(const T& d)
{
	data = d;
	s = 1;
	left = right = 0;
}

template <class T>
HBLTNode<T>::HBLTNode(const T& d,int temp)
{
	data = d;
	s = temp;
	left = right = 0;
}
#endif
