#define _CRT_SECURE_NO_WARNINGS
#include "cMatrix.h"

// 测试函数
void testcMatrixOperations() {
    try {
        std::cout << "=== 矩阵运算测试 ===" << std::endl;

        // 创建两个3x3矩阵
        cMatrix A(3, 3);
        cMatrix B(3, 3);

        // 设置矩阵A的值
        A(0, 0) = 1; A(0, 1) = 2; A(0, 2) = 3;
        A(1, 0) = 4; A(1, 1) = 5; A(1, 2) = 6;
        A(2, 0) = 7; A(2, 1) = 8; A(2, 2) = 9;

        // 设置矩阵B的值
        B(0, 0) = 9; B(0, 1) = 8; B(0, 2) = 7;
        B(1, 0) = 6; B(1, 1) = 5; B(1, 2) = 4;
        B(2, 0) = 3; B(2, 1) = 2; B(2, 2) = 1;

        std::cout << "矩阵A:" << std::endl;
        std::cout << A;

        std::cout << "矩阵B:" << std::endl;
        std::cout << B;

        // 测试加法
        cMatrix C = A + B;
        std::cout << "A + B:" << std::endl;
        std::cout << C;

        // 测试减法
        cMatrix D = A - B;
        std::cout << "A - B:" << std::endl;
        std::cout << D;

        // 测试乘法
        cMatrix E = A * B;
        std::cout << "A * B:" << std::endl;
        std::cout << E;

        // 测试单位矩阵
        cMatrix I = cMatrix::identity(3);
        std::cout << "3x3单位矩阵:" << std::endl;
        std::cout << I;

        // 测试与单位矩阵相乘
        cMatrix F = A * I;
        std::cout << "A * I (应该等于A):" << std::endl;
        std::cout << F;

        // 测试不同维度的矩阵乘法
        cMatrix G(2, 3);
        cMatrix H(3, 2);

        G(0, 0) = 1; G(0, 1) = 2; G(0, 2) = 3;
        G(1, 0) = 4; G(1, 1) = 5; G(1, 2) = 6;

        H(0, 0) = 7; H(0, 1) = 8;
        H(1, 0) = 9; H(1, 1) = 10;
        H(2, 0) = 11; H(2, 1) = 12;

        cMatrix K = G * H;
        std::cout << "G (2x3) * H (3x2):" << std::endl;
        std::cout << K;

        // 测试错误情况
        std::cout << "=== 测试错误处理 ===" << std::endl;
        cMatrix M(2, 2);
        cMatrix N(3, 3);

        try {
            cMatrix O = M + N; // 应该抛出异常
        }
        catch (const std::exception& e) {
            std::cout << "捕获到预期异常: " << e.what() << std::endl;
        }

        // 测试元素访问
        std::cout << "=== 测试元素访问 ===" << std::endl;
        std::cout << "A(1, 1) = " << A(1, 1) << std::endl;
        A(1, 1) = 99; // 修改元素
        std::cout << "修改后 A(1, 1) = " << A(1, 1) << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "错误: " << e.what() << std::endl;
    }
}

int main() {
    testcMatrixOperations();

    // 交互式测试
    std::cout << "\n=== 交互式测试 ===" << std::endl;
    try {
        int rows, cols;

        std::cout << "请输入第一个矩阵的行数和列数: ";
        std::cin >> rows >> cols;
        cMatrix m1(rows, cols);
        std::cin >> m1;

        std::cout << "请输入第二个矩阵的行数和列数: ";
        std::cin >> rows >> cols;
        cMatrix m2(rows, cols);
        std::cin >> m2;

        std::cout << "\n第一个矩阵:" << std::endl;
        std::cout << m1;

        std::cout << "第二个矩阵:" << std::endl;
        std::cout << m2;

        // 根据维度决定进行哪些运算
        if (m1.getRows() == m2.getRows() && m1.getCols() == m2.getCols()) {
            std::cout << "矩阵相加结果:" << std::endl;
            std::cout << m1 + m2;

            std::cout << "矩阵相减结果:" << std::endl;
            std::cout << m1 - m2;
        }
        else {
            std::cout << "矩阵维度不同，无法进行加减运算" << std::endl;
        }

        if (m1.getCols() == m2.getRows()) {
            std::cout << "矩阵相乘结果:" << std::endl;
            std::cout << m1 * m2;
        }
        else {
            std::cout << "矩阵维度不匹配，无法进行乘法运算" << std::endl;
        }

    }
    catch (const std::exception& e) {
        std::cerr << "错误: " << e.what() << std::endl;
    }

    return 0;
}