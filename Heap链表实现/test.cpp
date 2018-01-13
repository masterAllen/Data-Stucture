#include <iostream>
#include <cstring>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "HeapNode.h"

using namespace std;

/*The answer is "you don't want to implement heap sort on a linked list."

Heapsort is a good sorting algorithm because it's O(n log n) and it's in-place.
However, when you have a linked list heapsort is no longer O(n log n) because it relies on random access to the array, 
which you do not have in a linked list. 

So you either lose your in-place attribute (but needing to define a tree-like structure is O(n) space). 
Or you will need to do without them, but remember that a linked list is O(n) for member lookup. 
Which brings the runtime complexity to something like  O(n^2 log n) which is worse than bubblesort.

Just use mergesort instead. You already have the O(n) memory overhead requirement.

*/
int main()
{
	MinHeap<int> heap; 

	while(true)
	{
		cout<<"请选择要进行的操作"<<endl;
		cout<<"0.退出  1.插入元素  2.删除元素  3.初始化  4.堆排序"<<endl;
		
		int choice;
		cin>>choice;
		if(choice==1)
		{
			cout<<"请输入您想要插入的元素的值:";
			int num;
			cin>>num;
			
			heap.Insert(num);
			cout<<"插入后结果如下"<<endl;
			heap.Print();
		}else if(choice==2)
		{
			cout<<"删除的元素的值为:"<<heap.Delete()<<endl;
			cout<<"删除元素后堆的元素如下图所示"<<endl;
			heap.Print();
		}else if(choice==3)
		{
			cout<<"请输入您想要建立的堆的元素个数:";
			int n;
			cin>>n;
			
			int input[n];
			cout<<"请输入您想要构建的堆的元素"<<endl;
			for(int i=0;i<n;i++)
			{
				cin>>input[i];
			}
			heap.Initialize(input,n);
			cout<<"所得最大堆如下图所示"<<endl;
			heap.Print();
		}else if(choice==4)
		{
			cout<<"请选择排序方式：0.从小到大   1.从大到小"<<endl;
			int q;
			cin>>q;
			if(q)
			{
				MaxHeap<int> temp;
				cout<<"请输入您想要排序的元素的个数:"<<endl;
				int n;
				cin>>n;
				
				int input[n];
				cout<<"请输入您想要构建的堆的元素"<<endl;
				for(int i=0;i<n;i++)
				{
					cin>>input[i];
				}
				temp.Initialize(input,n);
				
				cout<<"所得结果如下"<<endl;
				for(int i=0;i<n;i++)
				{
					cout<<temp.Delete()<<" ";
				}
				cout<<endl;
			}else
			{
				MinHeap<int> temp;
				cout<<"请输入您想要排序的元素的个数:"<<endl;
				int n;
				cin>>n;
				
				int input[n];
				cout<<"请输入您想要构建的堆的元素"<<endl;
				for(int i=0;i<n;i++)
				{
					cin>>input[i];
				}
				temp.Initialize(input,n);
				cout<<"所得结果如下"<<endl;
				for(int i=0;i<n;i++)
				{
					cout<<temp.Delete()<<" ";
				}
				cout<<endl;
			}
		}else if(choice==0)
		{
			break;
		}else
		{
			cout<<"输入非法"<<endl;
		}
	}
}
