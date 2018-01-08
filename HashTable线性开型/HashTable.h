#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

template <class K,class E>
class HashTable
{
	public:
		HashTable();
		HashTable(int d);
		~HashTable(){};
		
		//找到key值的位置 
		int Pos(const K& k);
		//把key值为k的值返回给E 
		bool Search(const K& k,E &e);
		//把key值为K的值删掉,返回给E 
		HashTable<K,E>& Delete(const K& k,E& e);
		//插入E值 
		HashTable<K,E>& Insert(const E& e);
	private:
		bool *empty;
		E *save;
		int D;
};

template <class K,class E>
HashTable<K,E>::HashTable()
{
	D = 0;
}

template <class K,class E>
HashTable<K,E>::HashTable(int d)
{
	D = d;
	empty = new bool[D];
	save = new E[D];
	
	for(int i=0;i<D;i++)
	{
		empty[i] = true;
	}
	//为什么不是 new TableNode<T>[D]();
}

template <class K,class E>
//返回key值为K的位置 
int HashTable<K,E>::Pos(const K& k)
{
	int i = k%D;
	int pos = i;
	while(save[pos]!=k && !empty[pos])
	{
		pos = (pos+1)%D;
		if(pos==i) break;
	}
	
	return pos;
}

template <class K,class E>
//根据key值找到元素 
bool HashTable<K,E>::Search(const K& k,E &e)
{
	int pos = Pos(k);
	if(empty[pos] || save[pos]!=k)
	{
		//失败情况，在空位置停下，或者在错误位置停下
		return false;
	}
	
	e = save[pos];
	return true;
}

template <class K,class E>
HashTable<K,E>& HashTable<K,E>::Insert(const E& e)
{
	K key = e;
	int pos = Pos(key);
	if(empty[pos])
	{
		save[pos] = e;
		empty[pos] = false;
	}
	
	return *this;
	
	//如果不是空，有两种情况
	//第一种为当前位置确实为K，则说明输入的e有问题(注意每个对应的key是唯一的
	//第二种为当前位置不是K，则说明找了一圈没找到这个KEY安身之地，就说明表已经满了。 
//	if(save[pos]==k) 
//	
}


template <class K,class E>
HashTable<K,E>& HashTable<K,E>::Delete(const K& k,E& e)
{
	int pos = Pos(k);
	if(empty[pos] || save[pos]!=k)
	{
		//失败情况，在空位置停下，或者在错误位置停下
		//失败,返回一些说明 
		return *this;
	}
	
	e = save[pos];
	save[pos] = 0;
	return *this;
}

#endif
