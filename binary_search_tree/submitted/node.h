#ifndef NODE_H
#define NODE_H

class Node {
friend class BST;

public:
	Node(const int);
	~Node();

private:
	Node *root;
	Node *left;
	Node *right;
	int value;
};

#endif
