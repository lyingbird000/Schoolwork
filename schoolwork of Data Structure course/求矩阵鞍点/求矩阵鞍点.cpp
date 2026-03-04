#include <iostream>
#include <vector>
using namespace std;

// 函数声明
void findSaddlePoints(const vector<vector<int>>& matrix);   //找鞍点
void printMatrix(const vector<vector<int>>& matrix);		//打印矩阵

int main() {
    int rows, cols;

    cout << "请输入矩阵的行数和列数: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "请输入矩阵元素:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "\n输入的矩阵为:" << endl;
    printMatrix(matrix);

    cout << "\n鞍点位置:" << endl;
    findSaddlePoints(matrix);

    return 0;
}

void findSaddlePoints(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) {
        cout << "矩阵为空!" << endl;
        return;
    }
    int cols = matrix[0].size();
    bool found = false;

    /*
	// 初版：只考虑每行的第一个最小值
    for (int i = 0; i < rows; i++) {
        // 找到第i行的最小值及其列索引
        int minInRow = matrix[i][0];
        int colIndex = 0;

        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] < minInRow) {
                minInRow = matrix[i][j];
                colIndex = j;
            }
        }

        // 检查该最小值是否是其所在列的最大值
        bool isSaddlePoint = true;
        for (int k = 0; k < rows; k++) {
            if (matrix[k][colIndex] > minInRow) {
                isSaddlePoint = false;
                break;
            }
        }

        // 如果是鞍点，输出位置和值
        if (isSaddlePoint) {
            cout << "鞍点位置: (" << i << ", " << colIndex
                << "), 值: " << minInRow << endl;
            found = true;
        }
    }
    */

    // 改进版本：处理可能存在的多个最小值情况
    // 检查每一行中所有可能的最小值
    for (int i = 0; i < rows; i++) {
        // 找到第i行的最小值
        int minInRow = matrix[i][0];
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] < minInRow) {
                minInRow = matrix[i][j];
            }
        }

        // 检查所有等于最小值的元素
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == minInRow) {
                // 检查该元素是否是其所在列的最大值
                bool isSaddlePoint = true;
                for (int k = 0; k < rows; k++) {
                    if (matrix[k][j] > minInRow) {
                        isSaddlePoint = false;
                        break;
                    }
                }

                if (isSaddlePoint) {
                    cout << "鞍点位置: (" << i << ", " << j
                        << "), 值: " << minInRow << endl;
                    found = true;
                }
            }
        }
    }

    if (!found) {
        cout << "该矩阵没有鞍点" << endl;
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}