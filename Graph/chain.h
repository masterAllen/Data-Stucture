#ifndef CHAIN_H_
#define CHAIN_H_

#include "xcept.h"
#include "chainnode.h"
#include <iostream>
using namespace std;

template <class T> class ChainIterator;

template<class T>
class Chain
{
	friend ChainIterator<T>;

	public:
		Chain()
		{
			//表示一个空指针，http://www.cnblogs.com/fly1988happy/archive/2012/04/16/2452021.html 
			first = 0; 
		}
		~Chain();
		bool IsEmpty() const
		{
			return first==0;
		}
		int Length() const;
		//Find----找到链表第k个元素中，在返回true，不在返回false，同时将第k个元素的value赋给data 
		//复杂度为 O(k) 
		bool Find(int k,T& data) const;
		//Search----找到data在元素中位置，不在返回-1 
		//复杂度为 T(n) 
		int Search(T& data) const;
		//Delte----将data设为第k个元素的value，并删掉它 
		//复杂度为 O(k) 
		Chain<T>& Delete(int k,T& data);
		//Delete--上述函数根据位置删除，下述函数根据数据删除 
		//复杂度为 T(n) 
		Chain<T>& Delete(T& data); 
		//Insert-----在第k个元素后插入data 
		//复杂度为 O(k) 
		Chain<T>& Insert(int k,T& data);

		//Output----输出函数 
		void Output(ostream& out) const;
		//Erase----将链表全部清除 
		//复杂度为 O(n) 
		void Erase();
		//Append----在链表最后插入一个元素 
		//复杂度为 O(n) 
		Chain<T>& Append(const T&x);
		ChainNode<T>* First();
	private:
		ChainNode<T>* first;
		//first是指向第一个元素的指针 
		int MaxSize;
};

template<class T>
Chain<T>::~Chain()
{
	ChainNode<T>* next;
	while(first)
	{
		next = first->link; 
		delete first;
		//delete 要删除的对象必须是new出来的 
		first = next;
	}
}

template<class T>
int Chain<T>::Length() const
{
	ChainNode<T>* current = first;
	int length=0;
	while(current)
	{
		current = current->link;
		length++;
	}
	
	return length;
}

template<class T>
bool Chain<T>::Find(int k,T& data) const
{
	
	if(k<1)	return false;
	//这句一开始没有想到。。。
	
	ChainNode<T>* current = first;
	
	k--;
	while(current&&k)
	{
		k--;
		current = current->link;
	}
	
	if(k)	return false;
	
	data = current->data; 
	return true;
}

template<class T>
int Chain<T>::Search(T& data) const
{
	ChainNode<T>* current = first;
	//这里有没有*有什么不同-----指针呀，肯定是指针与指针相对 
	int index = 1; 
	while(current)
	{
		if(current->data == data)
		{
			return index;
		}
		current = current->link;
		index++;	
	}
	
	return 0;
}

template<class T>
Chain<T>& Chain<T>::Insert(int k,T& data)
{
	if(k<1)	throw OutOfBounds(); 
	ChainNode<T>* current = first;
	
	ChainNode<T>* insertNode = new ChainNode<T>;
	insertNode->link = 0;
	//为什么null就不对---null也是对的，但是要大写 
	insertNode->data = data;
	
	if(k==1)
	{
		insertNode->link = first;
		first = insertNode;
	}else
	{
		for(int i=1;i<k&&current;i++)
		{
			current = current->link;
		}
	
		if(!current) throw OutOfBounds();
		
		//为什么可以这样，那这样之前的first不会也改变吗？ 
		insertNode->link = current->link;
		current->link = insertNode;
		
	}
	
	return *this;
	//记住这个return的样式 
}

template<class T>
Chain<T>& Chain<T>::Delete(int k,T& data)
{
	if(k<1)	throw OutOfBounds();
	
	if(k==1)
	{
		data = first->data;
		ChainNode<T> *current = first->link;
		delete first;
		first = current;
		
	}else
	{
		ChainNode<T>* current = first;
		ChainNode<T>* previous = first;
		for(int i=1;i<k-1&&previous;i++)
		{
			previous = previous->link;
		}
		
		current = previous->link;

		if(!current)	throw OutOfBounds();
		previous->link = current->link;
		data = current->data;
		delete current;
		
	}
	
	return *this;
}

template <class T>
Chain<T>& Chain<T>::Delete(T &d)
{
	ChainNode<T>* current = first;
	ChainNode<T>* previous = first;
	while(current)
	{
		if(current->data == d)
		{
			previous->link = current->link;
			current->link = 0;
			delete current;
			return *this;
		}
		previous = current;
		current = current->link;
	}
	
	cout<<"删除失败"<<endl;
	return *this;
}

template <class T>
void Chain<T>::Erase()
{
	ChainNode<T>* current = first;
	while(current)
	{
		current = first->link;
		delete first;
		first = current;
	}
}

template<class T>
Chain<T>& Chain<T>::Append(const T& data)
{
	if(!first)
	{
	//	first->data = data;
		ChainNode<T>* insertNode = new ChainNode<T>;
		insertNode->link = 0;
		insertNode->data = data;
		first = insertNode;
	}else
	{
		ChainNode<T>* current;
		current = first;
		
		while(current->link)
		{
			current = current->link;
		}
		ChainNode<T>* insertNode = new ChainNode<T>;
		insertNode->data = data;
		insertNode->link = 0; 
		current->link = insertNode;
	}
	
	return *this;
}

template<class T>
void Chain<T>::Output(ostream& out) const
{
	ChainNode<T>* current = first;
	while(current)
	{
		out << current->data << " ";
		current = current->link;
	}
}

template<class T>
ostream& operator<<(ostream& out,const Chain<T>&x)
{
	x.Output(out);
	return out;
}

template <class T>
ChainNode<T>* Chain<T>::First()
{
	return first;
}
#endif
