#include "NDGraph.h"
#include <iostream>
using namespace std;
int main() {
	int vertices = 5; // 顶点数
	int edges = 6;    // 边数
	NDGraph graph(vertices, edges);
	// 添加边
	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(1, 2);
	graph.addEdge(1, 3);
	graph.addEdge(2, 4);
	graph.addEdge(3, 4);
	int start = 0; // 起始顶点
	int end = 4;   // 目标顶点
	int length = 2; // 路径长度
	if (graph.IsConnected_BFS(start, end, length)) {
		cout << "存在从顶点 " << start << " 到顶点 " << end << " 且长为 " << length << " 的路径。" << endl;
	}
	else {
		cout << "不存在从顶点 " << start << " 到顶点 " << end << " 且长为 " << length << " 的路径。" << endl;
	}
	start = 0;
	end = 4;
	length = 3;
	if (graph.IsConnected_BFS(start, end, length)) {
		cout << "存在从顶点 " << start << " 到顶点 " << end << " 且长为 " << length << " 的路径。" << endl;
	}
	else {
		cout << "不存在从顶点 " << start << " 到顶点 " << end << " 且长为 " << length << " 的路径。" << endl;
	}
	start = 1;
	end = 4;
	length = 4;
	if (graph.IsConnected_BFS(start, end, length)) {
		cout << "存在从顶点 " << start << " 到顶点 " << end << " 且长为 " << length << " 的路径。" << endl;
	}
	else {
		cout << "不存在从顶点 " << start << " 到顶点 " << end << " 且长为 " << length << " 的路径。" << endl;
	}
	return 0;
}