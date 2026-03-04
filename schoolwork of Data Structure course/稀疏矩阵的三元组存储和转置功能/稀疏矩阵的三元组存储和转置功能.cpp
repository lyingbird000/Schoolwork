#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 三元组结构体
struct Triple {
    int row;    // 行号
    int col;    // 列号
    int value;  // 值

    // 默认构造函数
    Triple() : row(0), col(0), value(0) {}

    // 带参数的构造函数
    Triple(int r, int c, int v) : row(r), col(c), value(v) {}
};

// 稀疏矩阵类
class SparseMatrix {
private:
    int rows;           // 矩阵行数
    int cols;           // 矩阵列数
    vector<Triple> data; // 三元组数据

public:
    // 构造函数
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    // 添加元素
    void addElement(int row, int col, int value) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            cout << "错误：位置(" << row << "," << col << ")超出矩阵范围！" << endl;
            return;
        }
        if (value != 0) {
            data.push_back(Triple(row, col, value));
        }
    }

    // 显示三元组
    void displayTriples() const {
        cout << "行\t列\t值" << endl;
        cout << "----------------" << endl;
        for (const auto& triple : data) {
            cout << triple.row << "\t" << triple.col << "\t" << triple.value << endl;
        }
    }

    // 显示矩阵（用于验证）
    void displayMatrix() const {
        vector<vector<int>> matrix(rows, vector<int>(cols, 0));

        // 填充矩阵
        for (const auto& triple : data) {
            matrix[triple.row][triple.col] = triple.value;
        }

        // 显示矩阵
        cout << "矩阵形式：" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // 普通转置方法
    SparseMatrix transpose() const {
        SparseMatrix result(cols, rows); // 转置后行列互换

        // 简单方法：遍历所有列，对于每一列找到对应的元素
        for (int j = 0; j < cols; j++) {
            for (const auto& triple : data) {
                if (triple.col == j) {
                    result.addElement(triple.col, triple.row, triple.value);
                }
            }
        }

        return result;
    }

    // 快速转置方法（更高效）
    SparseMatrix fastTranspose() const {
        SparseMatrix result(cols, rows);

        // 如果原矩阵没有非零元素，直接返回
        if (data.empty()) {
            return result;
        }

        // 统计原矩阵每列的非零元素个数，即新矩阵每行的非零元素个数
        vector<int> colCount(cols, 0);
        for (const auto& triple : data) {
            colCount[triple.col]++;
        }

        // 计算每列在转置矩阵中的起始位置
        vector<int> startPos(cols, 0);
        for (int i = 1; i < cols; i++) {
            startPos[i] = startPos[i - 1] + colCount[i - 1];
        }

        // 创建转置后的三元组数组
        result.data.resize(data.size());

        // 进行转置
        for (const auto& triple : data) {
            int pos = startPos[triple.col];
            result.data[pos] = Triple(triple.col, triple.row, triple.value);
			startPos[triple.col]++; // 更新同列元素的下一个存放位置
        }

        return result;
    }

    // 获取行数
    int getRows() const { return rows; }

    // 获取列数
    int getCols() const { return cols; }

    // 获取非零元素个数
    int getNonZeroCount() const { return data.size(); }
};

// 测试函数
void testSparseMatrix() {
    cout << "=== 稀疏矩阵转置演示 ===" << endl;

    // 创建一个5x4的稀疏矩阵
    SparseMatrix matrix(5, 4);

    // 添加非零元素
    matrix.addElement(0, 0, 1);
    matrix.addElement(0, 3, 2);
    matrix.addElement(1, 1, 3);
    matrix.addElement(2, 0, 4);
    matrix.addElement(2, 2, 5);
    matrix.addElement(3, 1, 6);
    matrix.addElement(4, 3, 7);

    // 显示原矩阵信息
    cout << "\n原矩阵信息：" << endl;
    cout << "矩阵大小: " << matrix.getRows() << " × " << matrix.getCols() << endl;
    cout << "非零元素个数: " << matrix.getNonZeroCount() << endl;

    // 显示原矩阵的三元组
    cout << "\n原矩阵的三元组表示：" << endl;
    matrix.displayTriples();

    // 显示原矩阵（用于验证）
    cout << "\n原矩阵：" << endl;
    matrix.displayMatrix();

    // 转置矩阵
    SparseMatrix transposed = matrix.fastTranspose();

    // 显示转置后的信息
    cout << "\n转置后矩阵信息：" << endl;
    cout << "矩阵大小: " << transposed.getRows() << " × " << transposed.getCols() << endl;
    cout << "非零元素个数: " << transposed.getNonZeroCount() << endl;

    // 显示转置后的三元组
    cout << "\n转置后的三元组表示：" << endl;
    transposed.displayTriples();

    // 显示转置后的矩阵（用于验证）
    cout << "\n转置后的矩阵：" << endl;
    transposed.displayMatrix();
}

// 交互式输入函数
void interactiveInput() {
    cout << "\n=== 交互式输入 ===" << endl;

    int rows, cols, count;

    cout << "请输入矩阵的行数: ";
    cin >> rows;
    cout << "请输入矩阵的列数: ";
    cin >> cols;

    SparseMatrix matrix(rows, cols);

    cout << "请输入非零元素的个数: ";
    cin >> count;

    cout << "请依次输入每个非零元素的行号、列号和值：" << endl;
    for (int i = 0; i < count; i++) {
        int r, c, v;
        cout << "元素 " << i + 1 << ": ";
        cin >> r >> c >> v;
        matrix.addElement(r, c, v);
    }

    // 显示输入结果
    cout << "\n输入的三元组：" << endl;
    matrix.displayTriples();

    // 转置并显示结果
    SparseMatrix transposed = matrix.fastTranspose();
    cout << "\n转置后的三元组：" << endl;
    transposed.displayTriples();
}

int main() {
    // 运行演示
    testSparseMatrix();

    // 交互式输入
    char choice;
    cout << "\n是否进行交互式输入？(y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        interactiveInput();
    }

    return 0;
}