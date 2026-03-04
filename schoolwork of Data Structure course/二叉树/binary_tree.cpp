#define _CRT_SECURE_NO_WARNINGS
#include "binary_tree.h"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

binary_tree::binary_tree(TreeNode* r) : root(r){}

void binary_tree::Preorder(TreeNode* visit) {
	int i = 0; // 用于跟踪访问节点的索引
	PreorderHelper(root, visit, i); // 调用辅助函数
}

void binary_tree::PreorderHelper(TreeNode* node, TreeNode* visit, int& i) {
	if (node == nullptr) {
		return;
	}
	visit[i++] = *node; // 访问当前节点
	PreorderHelper(node->lchild, visit, i); // 递归访问左子树
	PreorderHelper(node->rchild, visit, i); // 递归访问右子树
}

void binary_tree::Inorder(TreeNode* visit) {
	int i = 0; // 用于跟踪访问节点的索引
	InorderHelper(root, visit, i); // 调用辅助函数
}

void binary_tree::InorderHelper(TreeNode* node, TreeNode* visit, int& i) {
	if (node == nullptr) {
		return;
	}
	InorderHelper(node->lchild, visit, i); // 递归访问左子树
	visit[i++] = *node; // 访问当前节点
	InorderHelper(node->rchild, visit, i); // 递归访问右子树
}

void binary_tree::Postorder(TreeNode* visit) {
	int i = 0; // 用于跟踪访问节点的索引
	PostorderHelper(root, visit, i); // 调用辅助函数
}

void binary_tree::PostorderHelper(TreeNode* node, TreeNode* visit, int& i) {
	if (node == nullptr) {
		return;
	}
	PostorderHelper(node->lchild, visit, i); // 递归访问左子树
	PostorderHelper(node->rchild, visit, i); // 递归访问右子树
	visit[i++] = *node; // 访问当前节点
}

void binary_tree::destroy(TreeNode* node) {
	if (node != nullptr) {
		destroy(node->lchild); // 递归销毁左子树
		destroy(node->rchild); // 递归销毁右子树
		delete node; // 删除当前节点
	}
}

binary_tree::~binary_tree() 
{}

void binary_tree::InorderNonRecursive(TreeNode* visit) {
	std::stack<TreeNode*> s;
	TreeNode* current = root;
	int i = 0; // 用于跟踪访问节点的索引
	while (current != nullptr || !s.empty()) {
		while (current != nullptr) {	// 一直沿着左子树走，并将节点压入栈中
			s.push(current);
			current = current->lchild;
		}
		current = s.top();	
		s.pop();	//左
		visit[i++] = *current; // 访问当前节点，中
		current = current->rchild;	// 右
	}	//左->中->右顺序
}

// 辅助递归打印函数
void PrintHelper(const TreeNode* node, int depth) {
	if (!node) return;	// 终止条件（如果已经访问到最右结点，则node->rchild为nullstr）
	PrintHelper(node->rchild, depth + 1);	// 先打印右子树
	for (int i = 0; i < depth; ++i) std::cout << "    ";	// 根据深度打印空格
	std::cout << node->data << std::endl;	// 打印当前结点
	PrintHelper(node->lchild, depth + 1);	// 最后打印左子树
}

void binary_tree::Print() const {
	PrintHelper(root, 0);
}

// 根据前序和中序序列递归构建二叉树
static TreeNode* BuildTreeFromPreIn(const int* preorder, const int* inorder, int n) {
	if (n == 0) return nullptr;
	int root_val = preorder[0];
	TreeNode* root = new TreeNode(root_val);
	// 在中序序列中查找根节点位置
	int k = 0;
	while (k < n && inorder[k] != root_val) ++k;	//第k个位置就是根节点
	// 构建左子树
	root->lchild = BuildTreeFromPreIn(preorder + 1, inorder, k);
	// 构建右子树
	root->rchild = BuildTreeFromPreIn(preorder + k + 1, inorder + k + 1, n - k - 1);
	return root;
}

TreeNode* binary_tree::CreateFromPreIn(const int* preorder, const int* inorder, int n) {
	return BuildTreeFromPreIn(preorder, inorder, n);
}

//递归计算二叉树深度的辅助函数
static int DepthHelper(TreeNode* node) {
	if (node == nullptr) {
		return 0;
	}
	int left_depth = DepthHelper(node->lchild);
	int right_depth = DepthHelper(node->rchild);
	return std::max(left_depth, right_depth) + 1;
}

int binary_tree::Depth() const {
	return DepthHelper(root);
}

void binary_tree::LevelOrder(TreeNode* visit, int n) {
	if (root == nullptr) return;
	std::queue<TreeNode*> q;
	q.push(root);
	int i = 0; // 用于跟踪访问节点的索引
	while (!q.empty() && i < n) {
		TreeNode* current = q.front();
		q.pop();
		visit[i++] = *current; // 访问当前节点
		if (current->lchild != nullptr) {
			q.push(current->lchild);
		}
		if (current->rchild != nullptr) {
			q.push(current->rchild);
		}
	}
}


