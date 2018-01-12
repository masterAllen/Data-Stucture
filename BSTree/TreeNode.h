#ifndef TREENODE_H_
#define TREENODE_H_
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

template <class T> class BinaryTree;
template <class K,class E> class BST;
template <class T>
class TreeNode
{
	friend BinaryTree<T>;
	//只好把key值肯定当初int来写 
	friend BST<int,T>;
	public:
		TreeNode();
		TreeNode(const T& data);
		TreeNode(T &data,TreeNode<T> &left,TreeNode<T>&right);

		T returnData()
		{
			return data;
		}
	private:
		TreeNode<T> *leftChild;
		TreeNode<T> *rightChild;
		T data;
		int height;
};

template <class T>
TreeNode<T>::TreeNode()
{
	data = 0;
	leftChild = rightChild = 0;
	height = 0;
}

template <class T>
TreeNode<T>::TreeNode(const T &d)
{
	data = d;
	leftChild = rightChild = 0;
	height = 0;
}

template <class T>
TreeNode<T>::TreeNode(T &d,TreeNode<T> &left,TreeNode<T> &right)
{
	data = d;
	leftChild = left;
	rightChild = right;
	height = 0;
}

#endif
