#include <iostream>
#include <cstdio>
#include "linearList.h"
#include "xcept.h"

int main()
{
	LinearList<int> L(5);
	cout<<"Length = "<<L.Length()<<endl;
	L.Insert(0,5);
	cout<<"Length = "<<L.Length()<<endl;
	L.Insert(1,5).Insert(2,3);
	//Insert是在第i位插入数字，所以(1,n)就不是第一位 
	cout<<"Length = "<<L.Length()<<endl;
	
	int z;
	L.Find();//一开始写成了Find(),忘了L. 
	//Find函数是找第i个数，原来写了(0,n)那就相对于是-1了 
	cout<<"First Element = "<<z<<endl;
	L.Delete(3,z);
	//Delete和Find一样，之前完全都搞混了 
	cout<<"Deleted element is "<<z<<endl;
	cout<<"Length = "<< L.Length()<<endl;
	cout<<"List is "<< L <<endl; 
	//注意L并不是为0，因此如果第一个没有，输出的是一堆数字 
	
	return 0;
}
