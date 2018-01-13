#ifndef MINHEAP_H_
#define MINHEAP_H_
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include "HeapNode.h"
using namespace std;
template <class T>
class MinHeap 
{
	public:
		MinHeap();
		MinHeap(T &data);
		MinHeap(HeapNode<T> *root);
		~MinHeap(){};
		
		MinHeap<T>& Insert(const T &data);
		T& Delete();
		
		void Initialize(T *input,int n);
		
		//输出堆，因为二叉树不好直接输出，因此输出它们的遍历 
		void PreOutput();
		void InfixOutput();
		void PostOutput();
		
		void Print();
		HeapNode<T>* Root(){return root;}
	private:
		HeapNode<T> *root;
		void PreOrder(HeapNode<T> *current,void (*visit)(HeapNode<T> *temp));
		void PostOrder(HeapNode<T> *current,void (*visit)(HeapNode<T> *temp));
		void InOrder(HeapNode<T> *current,void (*visit)(HeapNode<T> *temp));
		void print(HeapNode<T> *current,int pre);
		static void Output(HeapNode<T> *current);
};

template <class T>
MinHeap<T>::MinHeap()
{
	root = 0;
}

template <class T>
MinHeap<T>::MinHeap(T &d)
{
	root = new HeapNode<T>(d);
}

template <class T>
MinHeap<T>::MinHeap(HeapNode<T> *r)
{
	root = r;
}
template <class T>
MinHeap<T>& MinHeap<T>::Insert(const T &data)
{
	//要插入的节点
	HeapNode<T> *x = new HeapNode<T>(data);
	
	//增加一个队列，用于层次遍历(LevelOrder) 
	queue<HeapNode<T>* > Q;
	Q.push(root);
	if(!root)
	{
		root = x;
		return *this;
	}
	HeapNode<T> *current = Q.front();
	while(current)
	{ 
		if(!current->leftChild)
		{
			current->leftChild = x;
			x->father = current;
		}else if(!current->rightChild)
		{
			current->rightChild = x;
			x->father = current;
		}else
		{
			Q.push(current->leftChild);
			Q.push(current->rightChild);
			
			//进行队列的下一个元素
			Q.pop();
		 	current = Q.front();
		 	continue;
		}
		
		//进行到这一步说明要插入的节点已经插入了
		current = x;
		while(current->father && current->data < current->father->data)
		{
			//与父亲交换位置
			T temp = current->father->data;
			current->father->data = current->data;
			current->data = temp; 
		} 
		break;
	}
	
	return *this;
}

template <class T>
T& MinHeap<T>::Delete()
{
//	if(root==NULL)	return ;
	T data = root->data;
	if(!root->leftChild)
	{
		root = 0;
		return data;
	}	
	//先找出最后一个节点
	queue<HeapNode<T>* > Q;
	Q.push(root);
	
	HeapNode<T> *previous = root;
	HeapNode<T> *current = root;
	while(current)
	{
		//如果没有左节点，则说明是queue上一个元素的右节点是最后一个 
		if(!current->leftChild)
		{
			HeapNode<T> *right = previous->rightChild;
			root->data = right->data;
			//previous->rightChild->father = 0;
			//有个疑问：左边这个式子指的是右节点的father属性，还是指的是右节点的father对象？
			right->father = 0;
			previous->rightChild = 0;
			delete right; 
		}else if(!current->rightChild)
		{
			//如果没有右节点，则说明是queue当前元素的左节点是最后一个
			HeapNode<T> *left = current->leftChild;
			root->data = left->data;
			left->father = 0;
			current->leftChild = 0;
			delete left; 
		}else
		{
			Q.push(current->leftChild);
			Q.push(current->rightChild);
			
			previous = current;
			Q.pop();
			current = Q.front();
			
			continue;
		}
		
		//最后从根节点开始交换数值即可
		current = root;
		while(current->leftChild)
		{
			//为了简洁，设置一个变量，0表示不换，1表示与左节点换，2表示与右节点换 
			int swap = 0;
			//如果没有右节点，直接与左节点比较 
			if(!current->rightChild)
			{
				//如果比左节点大，交换 
				if(current->data > current->leftChild->data)	swap = 1;
			}else
			{
				//左节点比右节点大，与右节点比较，否则与左节点比较 
				if(current->leftChild->data > current->rightChild->data)
				{
					if(current->data > current->rightChild->data)	swap = 2;
				}else
				{
					if(current->data > current->leftChild->data)	swap = 1;
				}
			}
			
			if(swap==1)
			{
				T temp = current->leftChild->data;
				current->leftChild->data = current->data;
				current->data = temp;
				
				current = current->leftChild;
			}else if(swap==2)
			{
				T temp = current->rightChild->data;
				current->rightChild->data = current->data;
				current->data = temp;
				
				current = current->rightChild;
			}else 
			{
				break;
			}
		}
		break;
	}
	return data;
}

template <class T>
void MinHeap<T>::Initialize(T *input,int n)
{
	//首先根据input数组初始化一个二叉树
	queue<HeapNode<T>* > Q;
	stack<HeapNode<T>* > S;
	root = new HeapNode<T>(input[0]);
	Q.push(root);
	HeapNode<T> *current = Q.front();

	int left = 1;//left表示要插入的节点是否应该插在current的左边 
	for(int i=1;i<n;i++)
	{
		//要插入的节点 
		HeapNode<T> *x = new HeapNode<T>(input[i]);
		Q.push(x);
		
		int temp_current = current->data;
		int temp_x = x->data;
		if(left)
		{
			S.push(current);
			current->leftChild = x;
			x->father = current;
			
			left = 0;
		}else
		{
			current->rightChild = x;
			x->father = current;
			
			left = 1;
			//current已经插满，进行下一个节点 

			Q.pop();
			current = Q.front();
		
		}
	} 
	
	//构建完毕，从current开始判断是否交换变量
	current = S.top();
	while(current)
	{
		while(current->leftChild || current->rightChild)
		{
			int swap = 0;
			//如果没有右节点，直接与左节点比较 
			if(!current->rightChild)
			{
				//如果比左节点大，交换 
				if(current->data > current->leftChild->data)	swap = 1;
			}else
			{
				//左节点比右节点大，与左节点比较，否则与右节点比较 
				if(current->leftChild->data < current->rightChild->data)
				{
					if(current->data > current->leftChild->data)	swap = 1;
				}else
				{
					if(current->data > current->rightChild->data)	swap = 2;
				}
			}
			
			if(swap==1)
			{
				T temp = current->leftChild->data;
				current->leftChild->data = current->data;
				current->data = temp;
				
				current = current->leftChild;
			}else if(swap==2)
			{
				T temp = current->rightChild->data;
				current->rightChild->data = current->data;
				current->data = temp;
				
				current = current->rightChild;
			}else 
			{
				
				break;
			}
		}
		
		S.pop();
		if(S.size())
			current = S.top();
		else 
			current = 0;
	}	
}

template <class T>
void MinHeap<T>::PreOrder(HeapNode<T> *current,void (*visit)(HeapNode<T> *temp) )
{
	if(current)
	{
		visit(current);
		PreOrder(current->leftChild,visit);
		PreOrder(current->rightChild,visit);
	}
}

template <class T>
void MinHeap<T>::InOrder(HeapNode<T> *current,void (*visit)(HeapNode<T> *temp))
{
	if(current)
	{
		InOrder(current->leftChild,visit);
		visit(current);
		InOrder(current->rightChild,visit);
	}
}

template <class T>
void MinHeap<T>::PostOrder(HeapNode<T> *current,void(*visit)(HeapNode<T> *temp))
{
	if(current)
	{
		PostOrder(current->leftChild,visit);
		PostOrder(current->rightChild,visit);
		visit(current);
	}
}

template <class T>
void MinHeap<T>::Output(HeapNode<T> *current)
{
	cout<<current->data<<" ";
}

template <class T>
void MinHeap<T>::PostOutput()
{
	PostOrder(root,Output);
}

template <class T>
void MinHeap<T>::InfixOutput()
{
	InOrder(root,Output);
}

template <class T>
void MinHeap<T>::PreOutput()
{
	PreOrder(root,Output);
}

template <class T>
void MinHeap<T>::print(HeapNode<T> *current,int pre)
{
	if(current)
	{
		for(int i=0;i<pre;i++)
		{
			cout<<"--";
		}
		cout<<current->data<<endl;
		print(current->leftChild,pre+1);
		print(current->rightChild,pre+1);
	}
}

template <class T>
void MinHeap<T>::Print()
{
	print(root,1);
}

#endif
