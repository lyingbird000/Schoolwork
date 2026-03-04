#include "cMatrix.h"

// 构造函数
cMatrix::cMatrix(int r, int c, double initial) : rows(r), cols(c) {
    if (r < 0 || c < 0) {
        throw std::invalid_argument("矩阵行列数不能为负数");
    }
    data.resize(rows, std::vector<double>(cols, initial));
}

// 拷贝构造函数
cMatrix::cMatrix(const cMatrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}

// 赋值运算符
cMatrix& cMatrix::operator=(const cMatrix& other) {
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        data = other.data;
    }
    return *this;
}

// ()运算符重载 - 用于提取或设置矩阵元素值
double& cMatrix::operator()(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("矩阵索引越界");
    }
    return data[row][col];
}

// const版本的()运算符重载
const double& cMatrix::operator()(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("矩阵索引越界");
    }
    return data[row][col];
}

// 获取行数
int cMatrix::getRows() const { return rows; }

// 获取列数
int cMatrix::getCols() const { return cols; }

// 矩阵加法
cMatrix cMatrix::operator+(const cMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("矩阵维度不匹配，无法相加");
    }

    cMatrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result(i, j) = data[i][j] + other(i, j);
        }
    }
    return result;
}

// 矩阵减法
cMatrix cMatrix::operator-(const cMatrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("矩阵维度不匹配，无法相减");
    }

    cMatrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result(i, j) = data[i][j] - other(i, j);
        }
    }
    return result;
}

// 矩阵乘法
cMatrix cMatrix::operator*(const cMatrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("矩阵维度不匹配，无法相乘");
    }

    cMatrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                result(i, j) += data[i][k] * other(k, j);
            }
        }
    }
    return result;
}

// 输入运算符重载
std::istream& operator>>(std::istream& is, cMatrix& matrix) {
    std::cout << "请输入矩阵 (" << matrix.rows << "x" << matrix.cols << ") 的元素:" << std::endl;
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            std::cout << "元素[" << i << "][" << j << "]: ";
            is >> matrix(i, j);
        }
    }
    return is;
}

// 输出运算符重载
std::ostream& operator<<(std::ostream& os, const cMatrix& matrix) {
    os << "矩阵 (" << matrix.rows << "x" << matrix.cols << "):" << std::endl;
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            os << std::setw(8) << std::fixed << std::setprecision(2) << matrix(i, j);
        }
        os << std::endl;
    }
    return os;
}

// 设置矩阵所有元素为指定值
void cMatrix::setAll(double value) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = value;
        }
    }
}

// 生成单位矩阵（必须是方阵）
cMatrix cMatrix::identity(int size) {
    if (size <= 0) {
        throw std::invalid_argument("单位矩阵大小必须为正数");
    }

    cMatrix result(size, size);
    for (int i = 0; i < size; ++i) {
        result(i, i) = 1.0;
    }
    return result;
}