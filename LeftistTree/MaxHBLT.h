#ifndef MAXHBLT_H_
#define MAXHBLT_H_
#include <iostream>
#include <cstring>
#include <string>
#include "HBLTNode.h"
using namespace std;

template <class T>
class MaxHBLT
{
	public:
		MaxHBLT();
		~MaxHBLT(){};
		
		MaxHBLT<T>& Insert(const T& x);
		MaxHBLT<T>& Delete(T& x);
		void Initialize(T* input,int n);
		void Meld(MaxHBLT<T> &other);
		void Print();
	private:
		HBLTNode<T> *root;
		HBLTNode<T>* Meld(HBLTNode<T> *A,HBLTNode<T> *B);
		void print(HBLTNode<T> *current,int pre);
};

template <class T>
MaxHBLT<T>::MaxHBLT()
{
	root = 0;
}

template <class T>
HBLTNode<T>* MaxHBLT<T>::Meld(HBLTNode<T> *A,HBLTNode<T> *B)
{
	if(!A) return B;
	if(!B) return A;
	
	if(A->data > B->data)
	{
		HBLTNode<T> *A_left = A->left;
		HBLTNode<T> *A_right = A->right;
		
		HBLTNode<T> *temp_B = Meld(A_right,B);
		
		//如果左边为空，则s(A)必为1，并且得到的右边值移到左边 
		if(!A_left)
		{
			A->left = temp_B;
			A->right = 0;
			A->s= 1;
		}else if(!temp_B)
		{
			A->left = A_left;
			A->right = 0;
			A->s= 1;			
		}else if(temp_B->s > A_left->s)
		{
//			int temp_1 = A_left->data;
//			int temp_3 = temp_B->data;
			A->left = temp_B;
			A->right = A_left;
			A->s = A_left->s+1;
		}else
		{
			A->left = A_left;
			A->right = temp_B;
			A->s = temp_B->s+1;
		}
		
		return A;
	}else
	{
		HBLTNode<T> *B_left = B->left;
		HBLTNode<T> *B_right = B->right;
		
		HBLTNode<T> *temp_A = Meld(B_right,A);
		
		if(!B_left)
		{
			B->left = temp_A;
			B->right = 0;
			B->s = 1; 
		}else if(!temp_A)
		{
			B->left = B_left;
			B->right = 0;
			B->s = 1;
		}else if(temp_A->s > B_left->s)
		{
			B->left = temp_A;
			B->right = B_left;
			B->s = B_left->s + 1;
		}else
		{
			B->left = B_left;
			B->right = temp_A;
			B->s = temp_A->s + 1;
		}
		
		return B;
	}
}

template <class T>
void MaxHBLT<T>::Meld(MaxHBLT<T>& other)
{
	root = Meld(root,other.root);
}


template <class T>
MaxHBLT<T>& MaxHBLT<T>::Insert(const T& x)
{
	HBLTNode<T> *temp = new HBLTNode<T>(x);
	
	root = Meld(root,temp);
	return *this;
}

template <class T>
MaxHBLT<T>& MaxHBLT<T>::Delete(T& x)
{
	HBLTNode<T> *left = root->leftChild;
	HBLTNode<T> *right = root->rightChild;
	
	Meld(left,right);
	return *this;
}

template <class T>
void MaxHBLT<T>::print(HBLTNode<T> *current,int pre)
{
	if(current)
	{
		for(int i=0;i<pre;i++)
		{
			cout<<"--";
		}
		cout<<current->data<<" "<<current->s<<endl;
		
		print(current->left,pre+1);
		print(current->right,pre+1); 
	}
}

template <class T>
void MaxHBLT<T>::Print()
{
	cout<<root->s<<endl;
	print(root,1);
}

template <class T>
void MaxHBLT<T>::Initialize(T *input,int n)
{
	for(int i=0;i<n;i++)
	{
		Insert(input[i]);
	}
}
#endif
