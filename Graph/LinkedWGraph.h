#ifndef LINKEDWGRAPH_H_
#define LINKEDWGRAPH_H_

#include <iostream>
#include <cstring>
#include <string>
#include "LinkedWDiGraph.h"

using namespace std;
template <class T>
class LinkedWGraph : public LinkedWDiGraph<T>
{
	public:
		LinkedWGraph<T>(int vertices=10) : LinkedWDiGraph<T>(vertices){};
		LinkedWGraph<T>& Add(int i,int j,const T &weight);
		LinkedWGraph<T>& Delete(int i,int j);
};

template <class T>
LinkedWGraph<T>& LinkedWGraph<T>::Add(int i,int j,const T &weight)
{
	//如果不存在i到j，添加i到j，添加j到i 
	if(!LinkedWDiGraph<T>::Exist(i,j))
	{
		LinkedWDiGraph<T>::Add(i,j,weight);
		//try-catch用法，同JAVA 
		try
		{
			LinkedWDiGraph<T>::Add(j,i,weight);
			this->e--;
		}catch(...)
		{
			LinkedWDiGraph<T>::Delete(i,j);
		}
	}
	
	return *this;
}

template <class T>
LinkedWGraph<T>& LinkedWGraph<T>::Delete(int i,int j)
{
	LinkedWDiGraph<T>::Delete(i,j);
	LinkedWDiGraph<T>::Delete(j,i);
	this->e++;//补偿 
	
	return *this;
}

#endif
