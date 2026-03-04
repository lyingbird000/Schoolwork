# 1.概述
用模板类的方法实现一个通用比大小函数（类），其中为string类和复数类`（CComplex）`设计了特化的实现（为此还引入了CComplex.h）
CComplex类图如下：

| class CComplex {                                               |
| -------------------------------------------------------------- |
| private:                                                       |
| double mR;                                                     |
| double mI;                                                     |
| public:                                                        |
| CComplex(double zR = 0, double zI = 0);     //构造函数             |
| ~CComplex();   //析构函数                                          |
|                                                                |
| void SetValue();   //复数对象设置操作函数1                               |
| void SetValue(double zR, double zI);     //复数对象设置操作函数2         |
| void ShowValue();   //复数对象显示操作函数                               |
|                                                                |
| CComplex Add(const CComplex& zC) const;     //复数加法运算功能函数       |
| CComplex Substract(const CComplex& zC) const;     //复数减法运算功能函数 |
| CComplex Multiply(const CComplex& zC) const;     //复数乘法运算功能函数  |
| CComplex Divide(const CComplex& zC) const;     //复数除法运算功能函数    |
|                                                                |
| double abs() const;   //复数模长计算函数                               |
# 2.知识点
- 模板类基本语法
- 模板类特化语法
# 3.运行结果
见附图
# 4.改进方向
- 加入更复杂的结构体的比大小方法（原理类似）