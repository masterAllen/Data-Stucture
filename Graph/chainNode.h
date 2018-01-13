#ifndef CHAINNODE_H_
#define CHAINNODE_H_
#include "GraphNode.h"
template<class T> class Chain;
template<class T> class ChainIterator;

template<class T>
class ChainNode
{
	friend Chain<T>;//
	friend ChainIterator<T>;

	public:
		T Data(){return data;}
		ChainNode<T>* Link(){return link;}
	private:
		T data;
		ChainNode<T>* link;
};
#endif

