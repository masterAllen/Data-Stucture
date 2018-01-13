#ifndef LINKEDDIGRAPH_H_
#define LINKEDDIGRAPH_H_
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include "LinkedBase.h"
#include "ChainIterator.h"
using namespace std;

//模板已经明确，因此可以直接访问父类的成员 
class LinkedDiGraph : public LinkedBase<int>
{
	public:
		LinkedDiGraph(int vertices=10) : LinkedBase<int>(vertices){};
		bool Exist(int i,int j);
		
		//用virtual会发生dynamic binding 
		virtual LinkedDiGraph& Add(int i,int j);
		virtual LinkedDiGraph& Delete(int i,int j);
		int OutDegree(int i);
		
		int Begin(int i);
		int NextVertex(int i);
		void IntializePos();
		
		void BFS(int i,int id[],int visit[]);
		void Print(int id[],int visit[],int n,int i,int pre);
		void DFS(int i,int visit[],int pre);
	private:
		ChainIterator<int> *it;
};

LinkedDiGraph& LinkedDiGraph::Add(int i,int j)
{
	chain[i].Insert(1,j);
	e++;
	return *this;
}

LinkedDiGraph& LinkedDiGraph::Delete(int i,int j)
{
	chain[i].Delete(j);
	e--;
		
	return *this;
}

bool LinkedDiGraph::Exist(int i,int j)
{
	if(chain[i].Search(j))
	{
		return true;
	}
	
	return false;
}

int LinkedDiGraph::OutDegree(int i)
{
	int result = 0;
	for(int p=1;p<=n;p++)
	{
		if(p==i) continue;
		if(chain[p].Search(i))
			result++;
	}
	return result;
}

int LinkedDiGraph::Begin(int i)
{
	int *x = it[i].Intialize(this->chain[i]);
	return x ? *x : 0;
	//为什么这里不加*就不会报错。。。 
}

int LinkedDiGraph::NextVertex(int i)
{
	int *x = it[i].Next();
	return x ? *x : 0;
}

void LinkedDiGraph::IntializePos()
{
	it = new ChainIterator<int>[n+1];
}

void LinkedDiGraph::BFS(int i,int id[],int visit[])
{
	queue<int> Q;
	Q.push(i);

	while(!Q.empty())
	{
		int m = Q.front();
		ChainNode<int> *current = chain[m].First();
		while(current)
		{
			int p = current->Data();	
			if(!visit[p])
			{
				Q.push(p);
				id[p] = m;
				visit[p] = 1;
			}
			current = current->Link();
		}
		
		Q.pop();
	}
	
	int temp[n+1] = {0};
	Print(id,temp,n,i,1);
}

void LinkedDiGraph::Print(int id[],int visit[],int n,int i,int pre)
{

	for(int temp=1;temp<=pre;temp++)
	{
		cout<<"--";
	}
	cout<<i<<endl;
	visit[i] = 1;
	for(int temp=1;temp<=n;temp++)
	{
		if(temp==i) continue;
		if(id[temp] == i&&!visit[temp])
		{
			Print(id,visit,n,temp,pre+1);
		}
	}
}

void LinkedDiGraph::DFS(int i,int visit[],int pre)
{
	for(int temp=1;temp<=pre;temp++)
	{
		cout<<"--";
	}
	cout<<i<<endl;
	
	visit[i] = 1;
	ChainNode<int> *current = chain[i].First();
	while(current)
	{
		int m = current->Data();
		if(!visit[m])
			DFS(m,visit,pre+1);
		visit[m] = 1;
		current = current->Link();
	}
	
}

#endif
