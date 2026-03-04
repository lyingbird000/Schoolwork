#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node(int val) : data(val), next(nullptr) {}
};
class LinkedList {
private:
	Node* head;
public:
	LinkedList() : head(nullptr) {}
	void append(int val) {
		if (!head) {
			head = new Node(val);
			return;
		}
		Node* curr = head;
		while (curr->next) {
			curr = curr->next;
		}
		curr->next = new Node(val);
	}
	void selectionSort() {
		for (Node* i = head; i != nullptr; i = i->next) {
			Node* minNode = i;
			for (Node* j = i->next; j != nullptr; j = j->next) {
				if (j->data < minNode->data) {
					minNode = j;
				}
			}
			if (minNode != i) {
				swap(i->data, minNode->data);
			}
		}
	}
	void printList() {
		Node* curr = head;
		while (curr) {
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}
};
int main() {
	LinkedList list;
	list.append(64);
	list.append(25);
	list.append(12);
	list.append(22);
	list.append(11);
	cout << "Original list: ";
	list.printList();
	list.selectionSort();
	cout << "Sorted list: ";
	list.printList();
	return 0;
}