#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include "Node.h"
using namespace std;
//Using formula-based representation can make the space too wasteful.So,choose the linked.
//主要学习了在private中添加函数 
//template <class T,class K> BST;
template <class T> 
class BinaryTree
{
//	friend BST<T,K>;
	public:
		BinaryTree();
		~BinaryTree(){};
	
		//遍历--时间复杂度T(n) 
		void Preorder(void (*visit)(Node<T>*visitNode));
		void Inorder(void (*visit)(Node<T>*visitNode));
		void Postorder(void (*visit)(Node<T>*visitNode));
		void Levelorder();
		
		//判断二叉树是否为空 
		bool isEmpty();
		//返回根节点的data给x 
		bool Root(T &x);
		//计算二叉树的结点数--起初名称为CountNode 
		int Size();
		//计算二叉树的高度--起初名称为CountHeight 
		int Height();
		
		Node<T>* returnRoot();
		//构建二叉树 
		void MakeTree(const T &data,BinaryTree<T> &left,BinaryTree<T> &right);
		//拆毁二叉树 
		void BreakTree(T &data,BinaryTree<T> &left,BinaryTree<T> &right);
		
		BinaryTree<T>& PreAndIn(vector<T> input_1,vector<T> input_2,int begin_1,int end_1,int begin_2,int end_2);
		
	private:
		Node<T> *root;
		//表示遍历时进行到的节点以及对该节点visit时的操作 
		void Preorder(void (*visit)(Node<T>* visitNode),Node<T> *current);
		void Inorder(void (*visit)(Node<T>* visitNode),Node<T> *current);
		void Postorder(void (*visit)(Node<T>* visitNode),Node<T> *current);
		
		//在程序测试中如果使用这些方法需要获得根节点(private)，因此需要将其放在内部，再添加一个Height()和Size()函数 
		int Height(Node<T> *current); 
		int Size(Node<T> *current);
};

template <class T>
BinaryTree<T>::BinaryTree()
{
	root = 0;
}

template <class T>
void BinaryTree<T>::Preorder(void (*visit)(Node<T>*visitNode))
{
	Preorder(visit,root);
}

template <class T>
void BinaryTree<T>::Inorder(void (*visit)(Node<T>*visitNode))
{
	Inorder(visit,root);
}

template <class T>
void BinaryTree<T>::Postorder(void (*visit)(Node<T>*visitNode))
{
	Postorder(visit,root);
}

template <class T>
void BinaryTree<T>::Preorder(void (*visit)(Node<T>*visitNode),Node<T> *current)
{
	if(current)
	{
		visit(current);
		Preorder(visit,current->leftChild);
		Preorder(visit,current->rightChild);
	}
		
}

template <class T>
void BinaryTree<T>::Inorder(void (*visit)(Node<T>*visitNode),Node<T> *current)
{
	if(current)
	{
		Inorder(visit,current->leftChild);
		visit(current);
		Inorder(visit,current->rightChild);
	}
	
}

template <class T>
void BinaryTree<T>::Postorder(void (*visit)(Node<T>*visitNode),Node<T> *current)
{
	if(current)
	{	
		Postorder(visit,current->leftChild);
		Postorder(visit,current->rightChild);
		visit(current);
	}

}

template <class T>
void BinaryTree<T>::MakeTree(const T &data,BinaryTree<T> &left,BinaryTree<T> &right)
{
	root = new Node<T>(data);
//	cout<<root->data<<endl;
	root->leftChild = left.root;
	root->rightChild = right.root;
	
	//分别让指向left和right的指针变为0，即只有从根节点才可以访问它们
	left.root = right.root = 0; 
}

template <class T>
Node<T>* BinaryTree<T>::returnRoot()
{
	return this->root;
}

//input1表示前序遍历，input2表示中序遍历，begin1和end1表示当前要处理的前序遍历的范围，本质即为当前子树的前序遍历
//同理，begin2和end2表示当前子树的中序遍历 
template <class T>
BinaryTree<T>& BinaryTree<T>::PreAndIn(vector<T> input_1,vector<T> input_2,int begin_1,int end_1,int begin_2,int end_2)
{
	if(end_1-begin_1 == 0)
	{
		BinaryTree<T>* temp = new BinaryTree<T>;
		return *temp;
	}
	int L,R;
	for(int i=begin_2;i<end_2;i++)
	{
		if(input_1[begin_1]==input_2[i])
		{
			L = i-begin_2;
			R = end_2-i-1;
			break;
		}
	}
	BinaryTree<T> left = PreAndIn(input_1,input_2,begin_1+1,begin_1+L+1,begin_2,begin_2+L);
	BinaryTree<T> right = PreAndIn(input_1,input_2,end_1-R,end_1,end_2-R,end_2);
	
	this->MakeTree(input_1[begin_1],left,right);
	return *this;
}

template <class T>
int BinaryTree<T>::Size(Node<T> *current)
{
	if(current)
	{
		return countNode(current->leftChild)+countNode(current->rightChild)+1;
	}else
	{
		return 0;
	}
}

template <class T>
int BinaryTree<T>::Size()
{
	return Size(root);
}
template <class T>
int BinaryTree<T>::Height(Node<T>*current)
{
	if(current)
	{
		return max(1+countHeight(current->leftChild),1+countHeight(current->rightChild));
	}else
	{
		return 0;
	}
}

template <class T>
int BinaryTree<T>::Height()
{
	return Height(root);
}
#endif
