#include <iostream>
#include <cstring>
#include <string>
#include "LinkedDiGraph.h"
using namespace std;

class LinkedGraph : public LinkedDiGraph
{
	public:
		LinkedGraph (int vertices = 10) : LinkedDiGraph(vertices){};
		LinkedGraph& Add(int i,int j);
		LinkedGraph& Delete(int i,int j);
};//没有这个逗号，反馈的错误信息:expected initializer before '&' token 

LinkedGraph& LinkedGraph::Add(int i,int j)
{
	if(!LinkedDiGraph::Exist(i,j))
	{
		LinkedDiGraph::Add(i,j);
		try
		{
			LinkedDiGraph::Add(j,i);
			e--;
		}catch(...)
		{
			LinkedDiGraph::Delete(i,j);
		}
	}
	return *this;
}

LinkedGraph& LinkedGraph::Delete(int i,int j)
{
	if(!LinkedDiGraph::Exist(i,j))
	{
		LinkedDiGraph::Delete(i,j);
		e++;
		LinkedDiGraph::Delete(j,i);
	}
	return *this;
}
