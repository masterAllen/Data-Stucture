#ifndef NODE_H_
#define NODE_H_
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

template <class T> class BinaryTree;
template <class T>
class Node
{
	friend BinaryTree<T>;
	public:
		Node();
		Node(const T& data);
		Node(T &data,Node<T> &left,Node<T>&right);

		T returnData()
		{
			return data;
		}
	private:
		Node<T> *leftChild;
		Node<T> *rightChild;
		T data;
};

template <class T>
Node<T>::Node()
{
	data = 0;
	leftChild = rightChild = 0;
}

template <class T>
Node<T>::Node(const T &d)
{
	data = d;
	leftChild = rightChild = 0;
}

template <class T>
Node<T>::Node(T &d,Node<T> &left,Node<T> &right)
{
	data = d;
	leftChild = left;
	rightChild = right;
}

#endif
