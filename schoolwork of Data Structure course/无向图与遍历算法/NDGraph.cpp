#define _CRT_SECURE_NO_WARNINGS
#include "NDGraph.h"
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
bool NDGraph::IsConnected_BFS(int i, int j, int k) {
	vector<bool> visited(V, false);
	queue<vector<int>> q;	// 队列中存储当前顶点及路径长度
	q.push({ i, 0 }); // 入队起始顶点及路径长度0
	visited[i] = true;
	while (!q.empty()) {
		vector<int> current = q.front();
		q.pop();
		int vertex = current[0];
		int length = current[1];
		if (vertex == j && length == k) {
			return true; // 找到路径
		}
		if (length < k) { // 仅当当前路径长度小于k时继续扩展
			for (int neighbor : adj[vertex]) {
				if (!visited[neighbor] || neighbor == j) { // 允许访问目标顶点j多次
					visited[neighbor] = true;
					q.push({ neighbor, length + 1 });
				}
			}
		}
	}
	return false; // 未找到路径
}