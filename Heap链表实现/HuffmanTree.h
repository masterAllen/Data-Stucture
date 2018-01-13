#ifndef HUFFMANTREE_H_
#define HUFFMANTREE_H_

#include <iostream>
#include <cstring>
#include <string>
#include "HuffmanNode.h"
#include "HeapNode.h"
#include "MinHeap.h"

using namespace std;

class HuffmanTree
{
	public:
		HuffmanTree();
		HuffmanTree(HuffmanNode *root);
		void CreateTree(char *str,int *num,int n);
		
		void Print();
	private:
		HuffmanNode *root;
		void print(HuffmanNode *current,string pre);
};

HuffmanTree::HuffmanTree()
{
	root = 0;
}
HuffmanTree::HuffmanTree(HuffmanNode *r)
{
	this->root = r;
}

void HuffmanTree::CreateTree(char *str,int *num,int n)
{
	MinHeap<HuffmanNode> heap;
	for(int i=0;i<n;i++)
	{
		HuffmanNode *temp = new HuffmanNode(str[i],num[i]);
		heap.Insert(*temp);
	}
	
	while(heap.Root())
	{
		HuffmanNode *first = &(heap.Delete());
		HuffmanNode *second = &(heap.Delete());
		
		//HuffmanNode first =...
		//&first-->前后一样 
//		HuffmanNode temp = heap.Delete();
//		HuffmanNode *first = new HuffmanNode(temp);
//		temp = heap.Delete();
//		HuffmanNode *second = new HuffmanNode(temp);
//		
		int freq = (first)->freq + (second)->freq;
		HuffmanNode *input = new HuffmanNode('#',freq);
		
		input->left = first;		
		input->right = second;
		
		if(!heap.Root())
		{
			heap.Insert(*input);
			break;
		}
		
		heap.Insert(*input);
	}
	
	HuffmanNode temp = heap.Delete();
	root = new HuffmanNode(temp);
}

void HuffmanTree::Print()
{
	print(root,"");
}

void HuffmanTree::print(HuffmanNode *current,string pre)
{
	if(!current) return;
	
	if(current->str != '#')
	{
		cout<<current->str<<":"<<pre<<endl;
	}
	
	print(current->left,pre+"1");
	print(current->right,pre+"0");
}

//template <class T>
//HuffmanTree::HuffmanTree(char* str,int *num,int n)
//{
//	queue<HeapNode<T> *> Q;
//	queue<HeapNode<T> *> Q1;
//	Initialize(input,n);
//	for(int i=1;i<=n;i++)
//	{
//		HeapNode<T> *temp = new HeapNode<T>(Delete());
//		Q.push(temp);
//	}
//	
//	while(!Q.empty() || !Q1.empty())
//	{
//		HeapNode<T> *first,*second;
//		if(Q.empty())
//		{
//			first = Q1.front();
//			Q1.pop();
//		}else if(Q1.empty())
//		{
//			first = Q.front();
//			Q.pop();
//		}else if(Q.front()->data < Q1.front()->data)
//		{
//			first = Q.front();
//			Q.pop();
//		}else 
//		{
//			first = Q1.front();
//			Q1.pop();
//		}
//		if(Q.empty())
//		{
//			second = Q1.front();
//			Q1.pop();
//		}else if(Q1.empty())
//		{
//			second = Q.front();
//			Q.pop();
//		}else if(Q.front()->data < Q1.front()->data)
//		{
//			second = Q.front();
//			Q.pop();
//		}else 
//		{
//			second = Q1.front();
//			Q1.pop();
//		}
//		
//		T data = first->data+second->data;
//		HeapNode<T> *temp = new HeapNode<T>(data,first,second);	
//		if(Q1.empty() && Q.empty())
//		{
//			Q1.push(temp);	
//			break;	
//		}
//		Q1.push(temp);
//	}
//	
//	HeapNode<T> *root = Q1.front();
//	MinHeap<T> *result = new MinHeap<T>(root);
//	
//	return *result;
//}

#endif
