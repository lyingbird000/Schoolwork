#include <iostream>
#include "CString.h"
using namespace std;

int main()
{
	//调试函数功能
	CString str1("abcdefg", 7);
	CString str2("bdf", 3);
	CString str3("gcb", 3);	
	str2.StrAssign(str2, str3); //赋值函数
	cout << "str2的值是: ";
	str2.Print(); //打印串
	str1.StrReverse(); //反转函数
	cout << "str1反转后是: ";
	str1.Print();
	bool cmp = str1.StrCompare(str1, str2); //比较函数
	if (cmp)
		cout << "str1大于等于str2" << endl;
	else
		cout << "str1小于str2" << endl;
	int time[100];
	str1.GetDifference(str1, str2, str3, time); //求差集函数
	cout << "str1与str2的差集是: ";
	str3.Print();
	cout << "差集字符在str1中第一次出现的位置是: ";
	for (int i = 0; i < str3.GetLength(); i++)
	{
		cout << time[i] << " ";
	}
	cout << endl;
	str2.SetValue("gf",2);
	str3.SetValue("x",1);
	cout << "str1,str2,str3现在分别是: " << endl;
	cout << "str1: ";
	str1.Print();
	cout << "str2: ";
	str2.Print();
	cout << "str3: ";
	str3.Print();
	str1.Replace(str1, str2, str3); //替换函数
	cout << "将str1中所有与str2相等的子串替换为str3后，str1是: ";
	str1.Print();
	cout << "str1与str2拼接结果：" << endl;
	CString str4 = str1.Concat(str1, str2); //连接函数
	str4.Print();
	return 0;
}
