#include <iostream>
#include <cstring>
#include <string>
#include "HuffmanTree.h"

using namespace std;

int main()
{
	HuffmanTree tree;
	cout<<"请输入您想要编码的字符个数:";
	int n;
	cin>>n;
	 
	char str[n];
	int num[n];
	
	cout<<"请输入您想要编码的字符:";
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
	}
	cout<<"请输入各个字符的对应频率:";
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	
	tree.CreateTree(str,num,n);
	tree.Print();
}
