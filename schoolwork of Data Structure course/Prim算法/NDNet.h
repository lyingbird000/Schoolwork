#define _CRT_SECURE_NO_WARNINGS
#ifndef NDNET_H
#define NDNET_H
#include <vector>
#include <string>
class NDNet {	//无向网类
private:
	int vexnum, arcnum;	//顶点数和边数
	std::vector<std::string> vexs;	//顶点向量
	std::vector<std::vector<int>> arcs;	//邻接矩阵
public:
	NDNet();	//构造函数
	~NDNet();	//析构函数
	void CreateNDNet();	//创建无向网
	void DispNDNet();	//显示无向网
	int GetVexNum();	//返回顶点数
	int GetArcNum();	//返回边数
	int FirstAdjVex(int v);	//返回v的第一个邻接顶点
	int NextAdjVex(int v, int w);	//返回v相对于w的下一个邻接顶点
	int GetWeight(int v, int w);	//返回边(v,w)的权值
	void MST_Prim();	//Prim算法构造并打印最小生成树
};

#endif
