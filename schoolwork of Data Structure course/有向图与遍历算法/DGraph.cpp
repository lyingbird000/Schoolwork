#define _CRT_SECURE_NO_WARNINGS
#include "DGraph.h"
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
void DGraph::printVertex(int v) {
	cout << "Vertex " << v << ": ";
	for (int neighbor : adj[v]) {
		cout << neighbor << " ";
	}
	cout << endl;
}

void DGraph::DFS(int start) {
	vector<bool> visited(V, false);
	stack<int> s;
	s.push(start);
	visited[start] = true;
	cout << "DFS Traversal starting from vertex " << start << ": "<<endl;
	while (!s.empty()) {
		int v = s.top();
		s.pop();
		printVertex(v);	// 打印当前顶点及其邻接点;可以根据需要修改为其他操作
		// cout << v << " "; // 仅打印顶点
		for (int neighbor : adj[v]) {
			if (!visited[neighbor]) {
				s.push(neighbor);
				visited[neighbor] = true;
			}
		}
	}
	cout << endl;
}

void DGraph::BFS(int start) {
	vector<bool> visited(V, false);
	queue<int> q;
	q.push(start);
	visited[start] = true;
	cout << "BFS Traversal starting from vertex " << start << ": "<<endl;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		printVertex(v);	// 打印当前顶点及其邻接点;可以根据需要修改为其他操作
		// cout << v << " "; // 仅打印顶点
		for (int neighbor : adj[v]) {
			if (!visited[neighbor]) {
				q.push(neighbor);
				visited[neighbor] = true;
			}
		}
	}
	cout << endl;
}

bool DGraph::IsConnected_BFS(int i, int j) {
	vector<bool> visited(V, false);
	queue<int> q;
	q.push(i);
	visited[i] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (v == j) {
			return true; // 找到路径
		}
		for (int neighbor : adj[v]) {
			if (!visited[neighbor]) {
				q.push(neighbor);
				visited[neighbor] = true;
			}
		}
	}
	return false; // 未找到路径
}

bool DGraph::IsConnected_DFS(int i, int j) {
	vector<bool> visited(V, false);
	stack<int> s;
	s.push(i);
	visited[i] = true;
	while (!s.empty()) {
		int v = s.top();
		s.pop();
		if (v == j) {
			return true; // 找到路径
		}
		for (int neighbor : adj[v]) {
			if (!visited[neighbor]) {
				s.push(neighbor);
				visited[neighbor] = true;
			}
		}
	}
	return false; // 未找到路径
}