#ifndef BST_H
#define BST_H

#include <vector>
#include "node.h"

using namespace std;

class BST {
public:
	BST();
	~BST();
	void RemoveAll(Node*);
	void Insert(const int);
	void Delete(const int);
	Node* findMin(Node*);
	Node* getHead();
	int getNodes();
	int getHeight(Node*);
	void PreOrder(Node*);
	void InOrder(Node*);
	void PostOrder(Node*);
	void LevelOrder();
	void HCI();

private:
	int nodes;
	Node *head;
	Node *tail;
};

#endif
