# 1.概述
用c++实现简单的矩阵数据结构，类图如下：

| **class Matrix**                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| vector<vector<double>> data;    //存放数据<br><br>int rows;    //行数<br><br>int cols;    //列数                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| cMatrix(int r,int c);    //构造函数<br><br>~cMatrix();    //析构函数<br><br>cMatrix(const cMatrix& other)    //拷贝构造函数<br><br>double& operator()(int row, int col)    //设置<br><br>const double& operator()(int row, int col) const    //提取<br><br>int getRows()  //获取行数<br><br>int getCols()   //获取列数<br><br>cMatrix operator+(const cMatrix& other) const    //加法<br><br>cMatrix operator-(const cMatrix& other) const    //减法<br><br>cMatrix operator*(const cMatrix& other) const    //乘法<br><br>friend istream& operator>>(istream& is, cMatrix& matrix)    //输入<br><br>friend ostream& operator<<(ostream& os, const cMatrix& matrix)    //输出<br><br>static cMatrix identity(int size)    //生成单位矩阵 |
代码：
```cpp
class cMatrix {
private:
    std::vector<std::vector<double>> data;
    int rows;
    int cols;

public:
    cMatrix(int r = 0, int c = 0, double initial = 0.0);    // 构造函数
    cMatrix(const cMatrix& other);    // 拷贝构造函数
    cMatrix& operator=(const cMatrix& other);   // 赋值运算
    double& operator()(int row, int col);    // ()运算符重载 - 用于提取或设置矩阵元素值
	const double& operator()(int row, int col) const;    // const版本的()运算符重载

    int getRows() const;        // 获取行数
    int getCols() const;        // 获取列数
    cMatrix operator+(const cMatrix& other) const;    // 矩阵加法
    cMatrix operator-(const cMatrix& other) const;    // 矩阵减法
    cMatrix operator*(const cMatrix& other) const;    // 矩阵乘法

    friend std::istream& operator>>(std::istream& is, cMatrix& matrix);    // 输入运算符重载
    friend std::ostream& operator<<(std::ostream& os, const cMatrix& matrix);    // 输出运算符重载
    void setAll(double value);    // 设置矩阵所有元素为指定值
    static cMatrix identity(int size);    // 生成单位矩阵（必须是方阵）
};
```

# 2.关键知识点
- 使用二维动态数组`vector<vector<double>>`实现矩阵的二维存储结构
- 需要对加减乘运算符重载，改造成矩阵加减乘法
# 3.运行结果
见附图
# 4.后续改进
- 可以联系数据结构课程中的稀疏矩阵存储知识，添加矩阵的一维存储方法
