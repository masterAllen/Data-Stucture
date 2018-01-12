#ifndef BST_H_
#define BST_H_
#include <iostream>
#include <cstring>
#include <string>
#include "BinaryTree.h"
using namespace std;


template <class K,class E>
class BST : public BinaryTree<E>
{
	public:
		BST() : BinaryTree<E>(){};
		//找到key值为K的节点，找不到则返回null 
		TreeNode<E>& Find(const K& k);
		//把key值为K的找到，返回给一个E 
		bool Search(const K& k,E& e);
		//插入e 
		BST<K,E>& Insert(const E& e);
		//根据key值删除节点 
		BST<K,E>& Delete(const K&k,E &e);
		
};

template <class K,class E>
TreeNode<E>& BST<K,E>::Find(const K& k)
{
	TreeNode<E> *current = this->root;
	//需要重写!=方法 
	while(current->data != k)
	{
		if(current->data < k)
		{
			current = current->rightChild;
		}else
		{
			current = current->leftChild;
		}
		
		if(!current) return NULL;
	}
	
	return current;
}

template <class K,class E>
bool BST<K,E>::Search(const K& k,E& e)
{
	TreeNode<E> *current = Find(k);
	if(current)
	{
		e = current->data;
		return true;
	} 
	return false;
}

template <class K,class E>
BST<K,E>& BST<K,E>::Insert(const E& e)
{
	//重写赋值方法 
	K key = e;
	TreeNode<E> *current = this->root;
	
	if(!current) 
	{
		this->root = new TreeNode<E>(e);
		return *this;
	}
	while(true)
	{
		if(current->data < key)
		{
			if(current->rightChild)
			{
				current = current->rightChild;
			}else
			{
				current->rightChild = new TreeNode<E>(e);
				break;
			}
		}else
		{
			if(current->leftChild)
			{
				current = current->leftChild;
			}else
			{
				current->leftChild = new TreeNode<E>(e);
				break;
			}
		}
	} 
	
	return *this;
}

template <class K,class E>
BST<K,E>& BST<K,E>::Delete(const K& k,E& e)
{
	TreeNode<E> *current = this->root;
	TreeNode<E> *previous = current;
	while(current && current->data!=k)
	{
		previous = current;
		if(current->data < k)
		{
			current = current->rightChild;
		}else
		{
			current = current->leftChild;
		}
	}
	
	e = current->data;
	//异常处理，这里是找不到这样的key 
	//if(!current)

	//要删除的点是叶子节点，直接删掉即可. 
	if(!current->leftChild && !current->rightChild)
	{
		//直接current是否可行?current = 0 
		if(current == previous->rightChild)
			previous->rightChild = 0;
		else
			previous->leftChild = 0;
			
		delete current;
	}else if(current->leftChild && current->rightChild)
	{
		//找到左子树最右的节点 
		TreeNode<E> *temp_father = current->leftChild;
		TreeNode<E> *temp_child = current->leftChild;
		
		while(temp_child->rightChild)
		{
			temp_father = temp_child;
			temp_child = temp_child->rightChild;
		}
		
		current->data = temp_child->data;

		temp_father->rightChild = temp_child->leftChild;
		temp_child->leftChild = 0;
		
		if(temp_father==temp_child) current->leftChild = temp_father->leftChild;
		delete temp_child;
	}else if(current->leftChild)
	{
		if(current == previous->rightChild)
			previous->rightChild = current->leftChild;
		else
			previous->leftChild = current->leftChild;
			
		delete current;
	}else
	{
		if(current == previous->leftChild)
			previous->leftChild = current->rightChild;
		else
			previous->rightChild = current->rightChild;
			
		delete current;
	}
	
	return *this;
}

#endif
