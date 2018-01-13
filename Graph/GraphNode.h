#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_
#include <iostream>
#include <cstring>
#include <string>

using namespace std;


template <class T> class LinkedWDiGraph;
template <class T> class LinkedWGraph;
template <class T> class Chain;

template <class T>
class GraphNode
{
	
	friend LinkedWDiGraph<T>;
	friend LinkedWGraph<T>;
	friend Chain<T>;
	public:
		GraphNode(){ pos = 0; data = 0;}
		GraphNode(int p){pos = p;}
		GraphNode(int p,const T &d)
		{
			pos = p;
			data = d;
		};
		
		//÷ÿ‘ÿµ»”⁄∫≈ 
		int operator ==(GraphNode<T> temp)
		{
			return (pos == temp.pos);
		}
	private:
		T data;
		int pos;
};

#endif
