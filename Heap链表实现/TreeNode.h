#ifndef TREENODE_H_
#define TREENODE_H_
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

template <class T>
class TreeNode
{
	public:
		TreeNode();
		TreeNode(const T& data);
		TreeNode(T &data,TreeNode<T> &left,TreeNode<T>&right);

		T Data()
		{
			return data;
		}
	private:
		TreeNode<T> *leftChild;
		TreeNode<T> *rightChild;
		T data;
};

template <class T>
TreeNode<T>::TreeNode()
{
	data = 0;
	leftChild = rightChild = 0;
}

template <class T>
TreeNode<T>::TreeNode(const T &d)
{
	data = d;
	leftChild = rightChild = 0;
}

template <class T>
TreeNode<T>::TreeNode(T &d,TreeNode<T> &left,TreeNode<T> &right)
{
	data = d;
	leftChild = left;
	rightChild = right;
}

#endif
