#ifndef HEAPNODE_H_
#define HEAPNODE_H_
#include <iostream>
#include <cstring>

using namespace std;

template <class T> class MaxHeap;
template <class T> class MinHeap;
template <class T>
class HeapNode
{
	friend MaxHeap<T>;
	friend MinHeap<T>;
	public:
		HeapNode();
		HeapNode(const T &data);
		HeapNode(const T &data,HeapNode<T> *leftChild,HeapNode<T> *rightChild);
	private:
		T data;
		HeapNode<T> *father;
		HeapNode<T> *leftChild;
		HeapNode<T> *rightChild;
}; 

template <class T>
HeapNode<T>::HeapNode(const T &d)
{
	data = d;
	father = 0;
	leftChild = 0;
	rightChild = 0;
}

template <class T>
HeapNode<T>::HeapNode(const T&d,HeapNode<T> *l,HeapNode<T> *r)
{
	data = d;
	leftChild = l;
	rightChild = r;
	father = 0;
	
	l->father = this;
	r->father = this;
}
#endif
