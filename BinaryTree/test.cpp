#include <iostream>
#include <cstring>
#include <string>
#include "BinaryTree.h"
#include "Node.h"
using namespace std;

void visit(Node<int> *current)
{
	//current是指向一个node的指针，因此要用它指向那个node的方法，要用-> 
	cout<<current->returnData()<<" ";	
}

int main()
{
	
	BinaryTree<int> a;
	cout<<"请输入您想要构建的二叉树的节点数"<<endl;
	int n;
	cin>>n;
	cout<<"请输入您想要构建的二叉树的前序遍历"<<endl; 
	vector<int> input_1,input_2;

	for(int i=1;i<=n;i++)
	{
		int temp;
		cin>>temp;
		input_1.push_back(temp);
	}
	cout<<"请输入您想要构建的二叉树的中序遍历"<<endl; 
	for(int i=1;i<=n;i++)
	{
		int temp;
		cin>>temp;
		input_2.push_back(temp);
	}
	a.PreAndIn(input_1,input_2,0,n,0,n);
	cout<<"二叉树构建完毕，请选择如下操作"<<endl;
	cout<<"1.输出后序遍历  2.输出中序遍历  3.输出前序遍历  4.输出高度  5.输出结点数目  0.结束"<<endl;
	while(1)
	{
		cin>>n;
		if(n==1)
		{
			cout<<"后序遍历为:";
			a.Postorder(visit);
			cout<<endl;
		}else if(n==2)
		{
			cout<<"中序遍历为:";
			a.Inorder(visit);
			cout<<endl;
		}else if(n==3)
		{
			cout<<"前序遍历为:";
			a.Preorder(visit);
			cout<<endl;
		}else if(n==4)
		{
			cout<<"二叉树高度为:";
			cout<<a.countHeight(a.returnRoot())<<endl;
		}else if(n==5)
		{
			cout<<"节点数目为:";
			cout<<a.countNode(a.returnRoot())<<endl;
		}else if(n==0)
		{
			break;
		}
	}
	

}
