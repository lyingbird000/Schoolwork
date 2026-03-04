#pragma once
#include <iostream>
using namespace std;
class BST {
private:
	struct Node {
		int key;
		Node* left;
		Node* right;
		Node(int k) : key(k), left(nullptr), right(nullptr) {}
	};
	Node* root;
	Node* insertRec(Node* node, int key) {	// 插入
		if (node == nullptr) {
			return new Node(key);
		}
		if (key < node->key) {
			node->left = insertRec(node->left, key);
		}
		else if (key > node->key) {
			node->right = insertRec(node->right, key);
		}
		return node;
	}
	bool searchRec(Node* node, int key) {	// 搜索
		if (node == nullptr) {
			return false;
		}
		if (key == node->key) {
			return true;
		}
		if (key < node->key) {
			return searchRec(node->left, key);
		}
		else {
			return searchRec(node->right, key);
		}
	}
	void inorderRec(Node* node) {	// 中序遍历
		if (node != nullptr) {
			inorderRec(node->left);
			cout << node->key;
			inorderRec(node->right);
		}
	}
	Node* DeleteNodeRec(Node* node, int key) {	// 删除指定节点并重接二叉树
		if (node == nullptr) {
			return node;
		}
		if (key < node->key) {
			node->left = DeleteNodeRec(node->left, key);
		}
		else if (key > node->key) {
			node->right = DeleteNodeRec(node->right, key);
		}
		else {
			if (node->left == nullptr) {
				Node* temp = node->right;
				delete node;
				return temp;
			}
			else if (node->right == nullptr) {
				Node* temp = node->left;
				delete node;
				return temp;
			}
			Node* temp = minValueNode(node->right);
			node->key = temp->key;
			node->right = DeleteNodeRec(node->right, temp->key);
		}
		return node;
	}
	Node* minValueNode(Node* node) {	// 查找最小值节点
		Node* current = node;
		while (current && current->left != nullptr) {
			current = current->left;
		}
		return current;
	}
public:
	BST() : root(nullptr) {}
	void insert(int key) {	// 插入
		root = insertRec(root, key);
	}
	bool search(int key) {	// 搜索
		return searchRec(root, key);
	}
	void inorder() {	// 中序遍历
		inorderRec(root);
	}
	void DeleteNode(int key) {    // 删除指定节点并重接二叉树
		root = DeleteNodeRec(root, key);
	}	
};



