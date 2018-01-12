#ifndef VALUE_H_
#define VALUE_H_
#include <iostream>
#include <cstring>
#include <string>

using namespace std;


template <class K,class T>
class Value
{
	public:
		Value();
		Value(const K& key,const T& data);
		~Value(){};
		
		operator T() const{	return key;}
		
		bool operator!=(K &k){return (key!=k);}
		bool operator<(K& k){return (key<k);}
		bool operator>(K& k){return (key>k);}
		
		Value<K,T>& operator=(const K& k)
		{
			key = k;
			return *this;
		}
		
		void Output(ostream& os);
	private:
		K key;
		T data;
};

template <class K,class T>
Value<K,T>::Value()
{
	key = 0;
	data = 0;
}

template <class K,class T>
Value<K,T>::Value(const K& k,const T& d)
{
	key = k;
	data = d;
}

template <class K,class T>
void Value<K,T>::Output(ostream& os)
{
	if(data)
	{
		os<<"("<<key<<","<<data<<")";
	}
}

template <class K,class T>
ostream& operator<<(ostream& os,Value<K,T> &value)
{
	value.Output(os);
	return os;
} 
#endif
