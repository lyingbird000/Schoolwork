#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
#include <stack>
class TreeNode {
public:
	int data;
	TreeNode* lchild;
	TreeNode* rchild;
	TreeNode(int d) : data(d), lchild(nullptr), rchild(nullptr) {}
	TreeNode() : data(0), lchild(nullptr), rchild(nullptr) {}
};
class binary_tree {
private:
	TreeNode* root;
	void PreorderHelper(TreeNode* node, TreeNode* visit, int& i); // 辅助函数
	void InorderHelper(TreeNode* node, TreeNode* visit, int& i); // 辅助函数
	void PostorderHelper(TreeNode* node, TreeNode* visit, int& i); // 辅助函数
public:
	binary_tree(TreeNode* r);
	~binary_tree();// 析构函数
	void Preorder(TreeNode* visit);   // 前序遍历
	void Inorder(TreeNode* visit);    // 中序遍历
	void Postorder(TreeNode* visit);  // 后序遍历
	void destroy(TreeNode* node); // 销毁树
	void InorderNonRecursive(TreeNode* visit); // 非递归中序遍历
	void Print() const; // 直观打印树（右子树在上，左子树在下，根居中）
	static TreeNode* CreateFromPreIn(const int* preorder, const int* inorder, int n);	// 从前序和中序遍历数组创建二叉树
	int Depth() const; // 计算二叉树的深度
	void LevelOrder(TreeNode* visit, int n);	//二叉树层次遍历的非递归算法
};


#endif
