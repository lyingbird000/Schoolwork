#ifndef NDGRAPH_H
#define NDGRAPH_H
#include <iostream>
#include <vector>
class NDGraph {
private:
	int V; // 顶点数
	int E; // 边数
	std::vector <std::vector<int>> adj; // 邻接表
public:
	NDGraph(int vertices, int edges) : V(vertices), E(edges) {
		adj.resize(V);
	}
	void addEdge(int u, int v) {
		adj[u].push_back(v); // 无向边
		adj[v].push_back(u);
	}
	void removeEdge(int u, int v) {
		auto& edges = adj[u];
		edges.erase(std::remove(edges.begin(), edges.end(), v), edges.end());
	}
	bool IsConnected_BFS(int i, int j, int k);	// 判断是否存在从顶点i到顶点j且长为k的路径
};
#endif
