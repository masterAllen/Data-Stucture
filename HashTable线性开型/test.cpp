#include <iostream>
#include <cstring>
#include <string>
#include "HashTable.h"
#include "HashValue.h"
using namespace std;

/*尚未完成的地方
1.HashTable中有些抛出异常尚未完成,就是说失败情况还没有说明
2.HashValue里面的赋值运算还没搞懂
3.string与char数组的转换 
4.重载输出符号，最好强记,加了个const就好了 
*/
int main()
{
//	string str = "Hi";
//	HashValue<int,string> a = new HashValue<int,string>(80,str);

	HashTable<int,HashValue<int,char> > table(11);
	HashValue<int,char> *a = new HashValue<int,char>(40,'a');
	HashValue<int,char> *b = new HashValue<int,char>(80,'b');
	HashValue<int,char> *c = new HashValue<int,char>(24,'c');
	HashValue<int,char> *d = new HashValue<int,char>(58,'d');
	HashValue<int,char> *e = new HashValue<int,char>(35,'e');
	
	table.Insert(*a);
	table.Insert(*b);
	table.Insert(*c);
	table.Insert(*d);
	table.Insert(*e);
	
	HashValue<int,char> temp;
	table.Search(58,temp);
	table.Delete(58,temp);
	
	cout<<table.Pos(35);
	
}
