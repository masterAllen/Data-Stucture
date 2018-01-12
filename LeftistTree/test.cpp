#include <iostream>
#include <cstring>
#include <string>
#include "MaxHBLT.h"
#include "HBLTNode.h"

using namespace std;
/*目前存在的问题
1.析构函数还没有完成 
2.有一个疑问：为什么单独编译MaxHBLT时，leftChild不会报错，但运行主程序，就会说leftChild不存在(实际为left) √(源文件未编译...) 
3.-> 和 . 究竟有什么区别  √ 
4.左高树具体的定义 
5.学习书上用法 
6.时间复杂度分析 
*/
int main()
{
	MaxHBLT<int> A;
	MaxHBLT<int> B;
	int a[3] = {18,7,6};
	int b[5] = {40,30,5,20,10};
	A.Initialize(a,3);
	B.Initialize(b,5);
//	A.Meld(B);
	
	A.Print();
	B.Print();
}
