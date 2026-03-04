#ifndef DGRAPH_H
#define DGRAPH_H
#include <iostream>
#include <vector>
class DGraph {
private:
	int V; // 顶点数
	int E; // 边数
	std::vector <std::vector<int>> adj; // 邻接表
public:
	DGraph(int vertices, int edges) : V(vertices), E(edges) {
		adj.resize(V);
	}
	void addEdge(int u, int v) {
		adj[u].push_back(v); // 有向边从u指向v
	}
	void removeEdge(int u, int v) {
		auto& edges = adj[u];
		edges.erase(std::remove(edges.begin(), edges.end(), v), edges.end());
	}
	void printVertex(int); // 打印指定顶点
	void DFS(int); // 深度优先遍历
	void BFS(int); // 广度优先遍历
	bool IsConnected_BFS(int i, int j);	// 用广度优先遍历判断是否存在从顶点i到顶点j的路径
	bool IsConnected_DFS(int i, int j);	// 用深度优先遍历判断是否存在从顶点i到顶点j的路径
};
#endif
