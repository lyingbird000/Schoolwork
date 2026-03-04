#define _CRT_SECURE_NO_WARNINGS
#include "NDNet.h"
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
NDNet::NDNet() {
	vexnum = 0;
	arcnum = 0;
}

NDNet::~NDNet() {
}

void NDNet::CreateNDNet() {
	cout << "请输入顶点数和边数：";
	cin >> vexnum >> arcnum;
	vexs.resize(vexnum);
	arcs.resize(vexnum, vector<int>(vexnum, INT_MAX));
	cout << "请输入各顶点信息：" << endl;
	for (int i = 0; i < vexnum; i++) {
		cout << "第" << i + 1 << "个顶点：";
		cin >> vexs[i];
	}
	cout << "请输入各边信息(格式：vi vj weight)： " << endl;
	for (int k = 0; k < arcnum; k++) {
		string vi, vj;
		int weight;
		cout << "第" << k + 1 << "条边：";
		cin >> vi >> vj >> weight;
		int i = 0, j = 0;
		while (i < vexnum && vexs[i] != vi) i++;
		while (j < vexnum && vexs[j] != vj) j++;
		if (i < vexnum && j < vexnum) {
			arcs[i][j] = weight;
			arcs[j][i] = weight; //无向网对称赋值
		}
		else {
			cout << "输入边有误！" << endl;
			k--;
		}
	}
}

void NDNet::DispNDNet() {
	cout << "无向网的邻接矩阵为：" << endl;
	cout << setw(6) << " ";
	for (int i = 0; i < vexnum; i++) {
		cout << setw(6) << vexs[i];
	}
	cout << endl;
	for (int i = 0; i < vexnum; i++) {
		cout << setw(6) << vexs[i];
		for (int j = 0; j < vexnum; j++) {
			if (arcs[i][j] == INT_MAX)
				cout << setw(6) << "∞";
			else
				cout << setw(6) << arcs[i][j];
		}
		cout << endl;
	}
}

int NDNet::GetVexNum() {
	return vexnum;
}

int NDNet::GetArcNum() {
	return arcnum;
}

int NDNet::FirstAdjVex(int v) {
	for (int i = 0; i < vexnum; i++) {
		if (arcs[v][i] != INT_MAX && arcs[v][i] != 0)
			return i;
	}
	return -1;
}

int NDNet::NextAdjVex(int v, int w) {
	for (int i = w + 1; i < vexnum; i++) {
		if (arcs[v][i] != INT_MAX && arcs[v][i] != 0)
			return i;
	}
	return -1;
}

int NDNet::GetWeight(int v, int w) {
	return arcs[v][w];
}

void NDNet::MST_Prim() {
	vector<bool> inMST(vexnum, false); //记录顶点是否在最小生成树中
	vector<int> lowcost(vexnum, INT_MAX); //记录各顶点到最小生成树的最小权值
	vector<int> adjvex(vexnum, -1); //记录各顶点在最小生成树中的邻接顶点(父节点)
	inMST[0] = true; //从第一个顶点开始
	for (int i = 0; i < vexnum; i++) {
		lowcost[i] = arcs[0][i];
		if (arcs[0][i] != INT_MAX && arcs[0][i] != 0)	//INT_MAX表示无穷大，0表示自己到自己的距离
			adjvex[i] = 0;
	}
	cout << "最小生成树的边为：" << endl;
	for (int i = 1; i < vexnum; i++) {
		int mincost = INT_MAX;	//最小权值的最小值
		int k = -1;	//记录最小权值对应的顶点下标
		for (int j = 0; j < vexnum; j++) {	//寻找不在最小生成树中的顶点中权值最小的顶点
			if (!inMST[j] && lowcost[j] < mincost) {
				mincost = lowcost[j];
				k = j;
			}
		}
		if (k != -1) {
			inMST[k] = true;	//将选中的顶点加入最小生成树
			cout << "(" << vexs[adjvex[k]] << ", " << vexs[k] << ") 权值: " << mincost << endl;
			for (int j = 0; j < vexnum; j++) {	//更新不在最小生成树中的顶点的权值
				if (!inMST[j] && arcs[k][j] < lowcost[j]) {
					lowcost[j] = arcs[k][j];
					adjvex[j] = k;
				}
			}
		}
	}
}