#include "binary_tree.h"
#include <iostream>
using namespace std;
int main()
{
	TreeNode* nodes = new TreeNode[7];
	nodes[0].data = 1;     //这颗树长这样：
	nodes[1].data = 2;     //           1
	nodes[2].data = 3;	   //        2     3
	nodes[3].data = 4;     //      4  5   6  7
	nodes[4].data = 5;
	nodes[5].data = 6;
	nodes[6].data = 7;
	nodes[0].lchild = &nodes[1];
	nodes[0].rchild = &nodes[2];
	nodes[1].lchild = &nodes[3];
	nodes[1].rchild = &nodes[4];
	nodes[2].lchild = &nodes[5];
	nodes[2].rchild = &nodes[6];
	binary_tree bt(&nodes[0]);
	//测试前序遍历
	TreeNode* visit_pre = new TreeNode[7];
	bt.Preorder(visit_pre);
	cout << "Preorder: ";
	for (int i = 0; i < 7; ++i) {
		cout << visit_pre[i].data << " ";
	}
	cout << endl;
	//测试中序遍历
	TreeNode* visit_in = new TreeNode[7];
	bt.Inorder(visit_in);
	cout << "Inorder: ";
	for (int i = 0; i < 7; ++i) {
		cout << visit_in[i].data << " ";
	}
	cout << endl;
	//测试非递归中序遍历
	bt.InorderNonRecursive(visit_in);
	bt.Inorder(visit_in);
	cout << "Inorder: ";
	for (int i = 0; i < 7; ++i) {
		cout << visit_in[i].data << " ";
	}
	cout << endl;
	//测试后序遍历
	TreeNode* visit_post = new TreeNode[7];
	bt.Postorder(visit_post);
	cout << "Postorder: ";
	for (int i = 0; i < 7; ++i) {
		cout << visit_post[i].data << " ";
	}
	cout << endl;
	//直观打印二叉树
	bt.Print();
	//测试从前序和中序遍历数组创建二叉树
	
	int preorder1[11] = { 5,2,1,4,3,6,8,7,9,11,10 };
	int inorder1[11] = { 1,2,3,4,5,6,7,8,9,10,11 };
	TreeNode* root1 = binary_tree::CreateFromPreIn(preorder1, inorder1, 11);
	binary_tree bt1(root1);  
	cout << "bt1:" << endl;
	bt1.Print();
	
	int preorder2[10] = { 1,2,4,8,9,5,10,3,6,7 };
	int inorder2[10] = { 8,4,9,2,10,5,1,6,3,7 };
	TreeNode* root2 = binary_tree::CreateFromPreIn(preorder2, inorder2, 10);
	binary_tree bt2(root2);
	cout << "bt2:" << endl;
	bt2.Print();
	//测试计算二叉树深度
	cout << "Depth of bt: " << bt.Depth() << endl;
	//测试层次遍历 
	TreeNode* visit_level = new TreeNode[7];
	bt.LevelOrder(visit_level, 7);
	cout << "Level Order: ";
	for (int i = 0; i < 7; ++i) {
		cout << visit_level[i].data << " ";
	}
	cout << endl;
	//销毁二叉树
	delete[] nodes;
	delete[] visit_pre;
	delete[] visit_in;
	delete[] visit_post;
	return 0;
}