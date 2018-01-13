#include <iostream>
#include <cstring>
#include <string>
#include "GraphNode.h"
#include "chain.h"
#include "chainnode.h"
#include "xcept.h"
#include "LinkedBase.h"
#include "LinkedWDiGraph.h"
#include "LinkedWGraph.h"
#include "LinkedDiGraph.h"
#include "LinkedGraph.h"
#include "GraphNode.h"
#include "ChainIterator.h"
using namespace std;

template <class T>
void print(LinkedWDiGraph<T> &G,int vertices)
{
	cout<<"请输入您想操作的图的边"<<endl;
	cout<<"输入格式：A  B  C"<<endl;
	cout<<"其中A为起始点,B为终点,C为权值,每一次加入边时请按回车键,结束时请输入单个0"<<endl;
	int A,B,C;
	cin>>A>>B>>C;
	int e = 0; 
	while(A)
	{
		G.Add(A,B,C);
		e++;
		cin>>A;
		if(!A) break;
		cin>>B>>C;
	} 
	while(true)
	{
		
		cout<<"请选择您要进行的操作"<<endl;
		cout<<"0.退出  1.从某个点遍历  2.输出BFS生成的树  3.输出DFS生成的树"<<endl;
		int m;
		cin>>m;
		if(m==1)
		{
			cout<<"请问您想要从哪个点开始遍历:";
			int i;
			cin>>i;
			G.IntializePos();
			int result = G.Begin(i);
			
			if(!result)
			{
				cout<<"很遗憾，没有从该点出发的边"<<endl;
				cout<<endl;
				continue;
				//为什么break就直接退出了? 
			}
			cout<<"遍历结果为：";
			while(result)
			{
				cout<<result<<" ";
				result = G.NextVertex(i);
			}
			cout<<endl;
		}else if(m==2)
		{
			cout<<"请问您想要从哪个点开始遍历:";
			int i;
			cin>>i;		
			int id[vertices+1] = {0};
			int visit[vertices+1] = {0};
			cout<<"结果如下:"<<endl;
			G.BFS(i,id,visit);
		}else if(m==3)
		{
			cout<<"请问您想要从哪个点开始遍历:";
			int i;
			cin>>i;		
			int id[vertices+1] = {0};
			int visit[vertices+1] = {0};
			cout<<"结果如下"<<endl;
			G.DFS(i,visit,1);			
		}else if(m==0)
		{
			break;
		}else
		{
			cout<<"输入格式非法。"<<endl; 
		}
		
		cout<<endl;
	}
}

void print(LinkedDiGraph &G,int vertices)
{
	cout<<"请输入您想操作的图的边"<<endl;
	cout<<"输入格式：A  B"<<endl;
	cout<<"其中A为起始点,B为终点,每一次加入边时请按回车键,结束时请输入单个0"<<endl;
	int A,B;
	cin>>A>>B;
	int e = 0; 
	while(A)
	{
		G.Add(A,B);
		e++;
		cin>>A;
		if(!A) break;
		cin>>B;
	} 
	while(true)
	{
		
		cout<<"请选择您要进行的操作"<<endl;
		cout<<"0.退出  1.从某个点遍历  2.输出BFS生成的树  3.输出DFS生成的树"<<endl;
		int m;
		cin>>m;
		if(m==1)
		{
			cout<<"请问您想要从哪个点开始遍历:";
			int i;
			cin>>i;
			G.IntializePos();
			int result = G.Begin(i);
			
			if(!result)
			{
				cout<<"很遗憾，没有从该点出发的边"<<endl;
				cout<<endl;
				continue;
				//为什么break就直接退出了? 
			}
			cout<<"遍历结果为：";
			while(result)
			{
				cout<<result<<" ";
				result = G.NextVertex(i);
			}
			cout<<endl;
		}else if(m==2)
		{
			cout<<"请问您想要从哪个点开始遍历:";
			int i;
			cin>>i;		
			int id[vertices+1] = {0};
			int visit[vertices+1] = {0};
			cout<<"结果如下:"<<endl;
			G.BFS(i,id,visit);
		}else if(m==3)
		{
			cout<<"请问您想要从哪个点开始遍历:";
			int i;
			cin>>i;		
			int id[vertices+1] = {0};
			int visit[vertices+1] = {0};
			cout<<"结果如下"<<endl;
			G.DFS(i,visit,1);			
		}else if(m==0)
		{
			break;
		}else
		{
			cout<<"输入格式非法。"<<endl; 
		}
		
		cout<<endl;
	}	
}
int main()
{
	cout<<"请选择您要操作哪种类型的图"<<endl;
	cout<<"1.有向加权图   2.无向加权图   3.有向无权图   4.无向无权图"<<endl;
	int n;
	cin>>n;
	cout<<"请输入您想要操作的图的点的个数：";
	int vertices;
	cin>>vertices;
	cout<<endl;
	if(n==1)
	{
		LinkedWDiGraph<int> G(vertices);
		print(G,vertices);
		
	}else if(n==2)
	{
		LinkedWGraph<int> G(vertices);
		print(G,vertices);
	}else if(n==3)
	{
		LinkedDiGraph G(vertices);
		print(G,vertices);
	}else if(n==4)
	{
		LinkedGraph G(vertices);
		print(G,vertices);
	}
}

