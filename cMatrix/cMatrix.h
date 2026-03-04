#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

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
    const double& operator()(int row, int col) const;       // const版本的()运算符重载

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

#endif 