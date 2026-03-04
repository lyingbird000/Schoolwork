#pragma once
class CComplex {
	double mR;
	double mI;
public:
	CComplex(double zR = 0, double zI = 0);     //构造函数
	~CComplex();   //析构函数

	void SetValue();   //复数对象设置操作函数1
	void SetValue(double zR, double zI);     //复数对象设置操作函数2
	void ShowValue();   //复数对象显示操作函数

	CComplex Add(const CComplex& zC) const;     //复数加法运算功能函数
	CComplex Substract(const CComplex& zC) const;     //复数减法运算功能函数
	CComplex Multiply(const CComplex& zC) const;     //复数乘法运算功能函数
	CComplex Divide(const CComplex& zC) const;     //复数除法运算功能函数

	double abs() const;   //复数模长计算函数
};
