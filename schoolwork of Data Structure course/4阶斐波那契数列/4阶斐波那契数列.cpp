#include <iostream>
using namespace std;

const int K = 4;  // 循环队列容量

class CircularQueue {
private:
    int data[K];  // 队列数据
    int front;    // 队头指针
    int rear;     // 队尾指针
    int count;    // 元素计数

public:
    // 构造函数
    CircularQueue() {
        front = 0;
        rear = 0;
        count = 0;
    }

    // 判断队列是否为空
    bool isEmpty() {
        return count == 0;
    }

    // 判断队列是否已满
    bool isFull() {
        return count == K;
    }

    // 入队操作
    void enqueue(int value) {
        if (isFull()) {
            // 队列已满时，先出队一个元素
            dequeue();
        }
        data[rear] = value;
        rear = (rear + 1) % K;
        count++;
    }

    // 出队操作
    int dequeue() {
        if (isEmpty()) {
            return -1;  // 队列为空
        }
        int value = data[front];
        front = (front + 1) % K;
        count--;
        return value;
    }

    // 获取队头元素（不出队）
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return data[front];
    }

    // 获取队列中所有元素的和
    int getSum() {
        if (isEmpty()) {
            return 0;
        }
        int sum = 0;
        int temp = front;
        for (int i = 0; i < count; i++) {
            sum += data[temp];
            temp = (temp + 1) % K;
        }
        return sum;
    }

    // 显示队列内容（用于调试）
    void display() {
        cout << "队列内容: ";
        int temp = front;
        for (int i = 0; i < count; i++) {
            cout << data[temp] << " ";
            temp = (temp + 1) % K;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue queue;
    int n = 0;
    int current = 0;

    // 初始化前4项
    cout << "4阶斐波那契序列：" << endl;
    cout << "f0 = 0" << endl;
    queue.enqueue(0);

    cout << "f1 = 0" << endl;
    queue.enqueue(0);

    cout << "f2 = 0" << endl;
    queue.enqueue(0);

    cout << "f3 = 1" << endl;
    queue.enqueue(1);

    n = 3;  // 当前最后一项的索引

    // 继续生成序列，直到满足条件
    while (true) {
        // 计算下一项（队列中所有元素的和）
        current = queue.getSum();
        n++;

        cout << "f" << n << " = " << current << endl;

        // 检查是否满足条件：fn ≤ 200 且 fn+1 > 200
        if (current > 200) {
            cout << "\n满足条件的序列：" << endl;
            cout << "f" << n - 1 << " = " << queue.getFront() << " ≤ 200" << endl;
            cout << "f" << n << " = " << current << " > 200" << endl;
            break;
        }

        // 将新项加入队列
        queue.enqueue(current);
    }

    return 0;
}