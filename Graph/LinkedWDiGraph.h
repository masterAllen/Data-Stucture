#ifndef LINKEDWDIGRAPH_H_
#define LINKEDWDIGRAPH_H_

#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include "chain.h"
#include "GraphNode.h"
#include "LinkedBase.h"
#include "ChainIterator.h"
//没有头文件报错信息:invalid use of incomplete type struct
using namespace std;

//链表实现：加权有向图-->加权无向图，无权有向图-->无权无向图 
//模板类继承时，子类无法调用父类成员，解决方法是用this才能访问 
template <class T>
class LinkedWDiGraph : public LinkedBase<GraphNode<T> >
{
	public:	
		LinkedWDiGraph(int vertices = 10) : LinkedBase<GraphNode<T> >(vertices){};
		bool Exist(int i,int j);
		virtual LinkedWDiGraph<T>& Add(int i,int j,const T &weight);
		virtual LinkedWDiGraph<T>& Delete(int i,int j);		
		int OutDegree(int i);
		
		int Begin(int i);
		int NextVertex(int i);
		void IntializePos(); 

		void Output();
		
		void BFS(int i,int id[],int visit[]);
		void DFS(int i,int visit[],int pre);
		void Print(int id[],int n,int i,int pre);
	protected:
		ChainIterator<GraphNode<T> > *pos;
};

template <class T>
bool LinkedWDiGraph<T>::Exist(int i,int j)
{
	GraphNode<T> *x = new GraphNode<T>(j);
	if((this->chain[i]).Search(*x))
	{
		return true;
	}
	return false;
}

template <class T>
LinkedWDiGraph<T>& LinkedWDiGraph<T>::Add(int i,int j,const T &weight)
{
	//要插入的点 
	GraphNode<T> *x = new GraphNode<T>(j,weight);
	this->chain[i].Insert(1,*x);
	this->e++; 
	return *this;
}

template <class T>
LinkedWDiGraph<T>& LinkedWDiGraph<T>::Delete(int i,int j)
{
	//在GraphNode中构建比较方法，如果内部的pos相同则说明两者相同。 
	GraphNode<T> *x = new GraphNode<T>(j);
	(this->chain[i]).Delete(*x);
	this->e--;
	return *this;
}

template <class T>
int LinkedWDiGraph<T>::OutDegree(int i)
{
	int result = 0;
	GraphNode<T> *x = new GraphNode<T>(i);
	for(int m=1;m<=this->n;m++)
	{
		if(i==m) continue;
		if(this->chain[m].Search(*x)) result++;
	}
	return result;
}
template <class T>
void LinkedWDiGraph<T>::IntializePos()
{
	//注意这里由于T是int所以ChianNode里盛放应该是GraphNode<int> 
	pos = new ChainIterator<GraphNode<T> >[(this->n)+1];
}

template <class T>
int LinkedWDiGraph<T>::Begin(int i)
{
	GraphNode<T> *j = pos[i].Intialize(this->chain[i]);
	//这里最初写的是*j->pos,仔细体会两者区别。 
	return (j) ? j->pos : 0;//注意判断是否为空 
}

template <class T>
int LinkedWDiGraph<T>::NextVertex(int i)
{
	GraphNode<T> *j = pos[i].Next();
	return (j) ? (j->pos) : 0;
}

template <class T>
void LinkedWDiGraph<T>::Output()
{
	//为什么chain[i]不是指针? 
	cout<<this->chain[1].First()<<endl;

}

template <class T>
void LinkedWDiGraph<T>::BFS(int i,int id[],int visit[])
{
	queue<int> Q;
	id[i] = 0;
	visit[i] = 1;
	Q.push(i);
	int m = i;
	
	while(!Q.empty())
	{
		m = Q.front();
		//可以直接用链表做，不需要利用迭代器。
		ChainNode<GraphNode<T> > *current = this->chain[m].First();
		while(current)
		{
			int p = (current->Data()).pos;
			if(!visit[p])
			{
				id[p] = m;
				visit[p] = 1;
				Q.push(p);
			}
			current = current->Link();
		}	
		Q.pop();
	}
	int pre = 1;
	Print(id,this->n,i,pre);
}

template <class T>
void LinkedWDiGraph<T>::Print(int id[],int n,int i,int pre)
{
	for(int temp=0;temp<pre;temp++)
	{
		cout<<"--";
	}
	cout<<i<<endl;
	for(int temp=1;temp<=n;temp++)
	{
		if(temp==i) continue;
		if(id[temp] == i)
		{
			Print(id,n,temp,pre+1);
		}
	}
} 

template <class T>
void LinkedWDiGraph<T>::DFS(int i,int visit[],int pre)
{
	for(int temp=0;temp<pre;temp++)
	{
		cout<<"--";
	}
	cout<<i<<endl;
	
	visit[i] = 1;
	ChainNode<GraphNode<T> > *current = this->chain[i].First();
	while(current)
	{
		int x = (current->Data()).pos;
		if(!visit[x])
		{
			visit[x] = 1;
			DFS(x,visit,pre+1);
		}
		current = current->Link();
		
	}
} 
#endif
