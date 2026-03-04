#include"DGraph.h"
#include <iostream>
using namespace std;
int main() {
	//下面构造一个简单的有向图
	int vertices = 6; // 顶点数
	int edges = 5;   // 边数
	DGraph graph(vertices, edges);
	// 添加有向边
	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(2, 3);
	graph.addEdge(2, 4);
	graph.addEdge(3, 5);
	int startVertex = 0; // 从顶点0开始遍历
	graph.DFS(startVertex); // 深度优先遍历
	graph.BFS(startVertex); // 广度优先遍历
	// 判断是否存在从顶点i到顶点j的路径
	int i = 0, j = 3;
	cout << "Checking path from vertex " << i << " to vertex " << j << ":" << endl;
	if (graph.IsConnected_BFS(i, j)) {
		cout << "There is a path from vertex " << i << " to vertex " << j << " (BFS)." << endl;
	}
	else {
		cout << "There is no path from vertex " << i << " to vertex " << j << " (BFS)." << endl;
	}
	if (graph.IsConnected_DFS(i, j)) {
		cout << "There is a path from vertex " << i << " to vertex " << j << " (DFS)." << endl;
	}
	else {
		cout << "There is no path from vertex " << i << " to vertex " << j << " (DFS)." << endl;
	}
	i = 3; j = 0;
	cout << "Checking path from vertex " << i << " to vertex " << j << ":" << endl;
	if (graph.IsConnected_BFS(i, j)) {
		cout << "There is a path from vertex " << i << " to vertex " << j << " (BFS)." << endl;
	}
	else {
		cout << "There is no path from vertex " << i << " to vertex " << j << " (BFS)." << endl;
	}
	if (graph.IsConnected_DFS(i, j)) {
		cout << "There is a path from vertex " << i << " to vertex " << j << " (DFS)." << endl;
	}
	else {
		cout << "There is no path from vertex " << i << " to vertex " << j << " (DFS)." << endl;
	}
	return 0;
}