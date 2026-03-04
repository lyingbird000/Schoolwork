#pragma once
#include <iostream>
#include <stdexcept>
// 使用时格式为ArrayStack <int> example_stack;
template<typename T>
class ArrayStack {
private:
    T* data;           // 存储栈元素的数组
    int capacity;      // 栈的容量
    int topIndex;      // 栈顶指针

public:
    // 构造函数
    ArrayStack(int size = 50) {
        capacity = size;
        data = new T[capacity];
        topIndex = -1;  // 栈空时指针为-1
    }

    // 析构函数
    ~ArrayStack() {
        delete[] data;
    }

    // 拷贝构造函数
    ArrayStack(const ArrayStack& other) {
        capacity = other.capacity;
        topIndex = other.topIndex;
        data = new T[capacity];
        for (int i = 0; i <= topIndex; i++) {
            data[i] = other.data[i];
        }
    }

    // 赋值运算符
    ArrayStack& operator=(const ArrayStack& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            topIndex = other.topIndex;
            data = new T[capacity];
            for (int i = 0; i <= topIndex; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // 判断栈是否为空
    bool isEmpty() const {
        return topIndex == -1;
    }

    // 判断栈是否已满
    bool isFull() const {
        return topIndex == capacity - 1;
    }

    // 获取栈大小
    int size() const {
        return topIndex + 1;
    }

    // 入栈操作
    void push(const T& value) {
        if (isFull()) {
            // 如果栈满，扩容
            resize(capacity * 2);
        }
        data[++topIndex] = value;
    }

    // 出栈操作
    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("栈为空，无法执行pop操作");
        }
        topIndex--;
    }

    // 获取栈顶元素
    T& top() {
        if (isEmpty()) {
            throw std::underflow_error("栈为空，无法获取栈顶元素");
        }
        return data[topIndex];
    }

    const T& top() const {
        if (isEmpty()) {
            throw std::underflow_error("栈为空，无法获取栈顶元素");
        }
        return data[topIndex];
    }

    // 清空栈
    void clear() {
        topIndex = -1;
    }

    // 打印栈内容（用于调试）
    void print() const {
        if (isEmpty()) {
            std::cout << "栈为空" << std::endl;
            return;
        }

        std::cout << "栈内容（从栈顶到栈底）: ";
        for (int i = topIndex; i >= 0; i--) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    // 调整栈容量
    void resize(int newCapacity) {
        T* newData = new T[newCapacity];
        for (int i = 0; i <= topIndex; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
};
