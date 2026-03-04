#include "Compare.h"
#include <iostream>
#include <string>
#include "CComplex.h"
using namespace std;
int main() {
	// 整型比较
	int intA = 10;
	int intB = 20;
	cout << Compare<int>::IsBigger(intA, intB) << endl;
	cout << Compare<int>::IsSmaller(intA, intB) << endl;
	cout << Compare<int>::IsEqual(intA, intB) << endl;
	// 浮点型比较
	double doubleA = 10.5;
	double doubleB = 20.5;
	cout<<Compare<double>::IsBigger(doubleA, doubleB)<<endl;
	cout << Compare<double>::IsSmaller(doubleA, doubleB) << endl;
	cout << Compare<double>::IsEqual(doubleA, doubleB) << endl;
	// 字符串比较
	string strA = "apple";
	string strB = "banana";
	cout<<Compare<string>::IsBigger(strA, strB)<<endl;
	cout << Compare<string>::IsSmaller(strA, strB) << endl;
	cout << Compare<string>::IsEqual(strA, strB) << endl;
	// 复数比较
	CComplex complexA(3.0, 4.0); // 复数3 + 4i
	CComplex complexB(1.0, 7.0); // 复数1 + 7i
	cout<<Compare<CComplex>::IsBigger(complexA, complexB)<<endl;
	cout << Compare<CComplex>::IsSmaller(complexA, complexB) << endl;
	cout << Compare<CComplex>::IsEqual(complexA, complexB) << endl;
	return 0;
}