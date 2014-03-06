#include "bst.h"
#include <new>
#include <queue>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <map>

using namespace std;

//G++ sucks.
//every other compiler in the whole world to_string function works.
//source: http://www.cplusplus.com/forum/general/96668/
namespace my {
    template < typename T > std::string to_string( const T& v ) {
        std::ostringstream stm;
        return ( stm << v ) ? stm.str() : "{*** error ***}" ;
    }
}

BST::BST() {
	head = NULL;
	tail = NULL;
	nodes = 0;
}

BST::~BST() {
	//recursively remove nodes from memory
	RemoveAll(head);
}

void BST::RemoveAll(Node *node) {
	if (node) {
		RemoveAll(node->left); //go left
		RemoveAll(node->right); //go right
		delete node; //delete node from memory
		nodes--; //decrement node count
	}
}

void BST::Insert(int value) {
	Node *tree = head;
	Node *node = new Node(value);
	
	//if empty add to head;
	if (!head) {
		head = node;
		nodes++;
	} else {
		while (true) {
			//go left
			if (value < tree->value) {
				if (!tree->left) {
					node->root = tree;
					tree->left = node;
					nodes++;
					return;
				} else
					tree = tree->left;
			}
			//go right
			else if (value > tree->value) {
				if (!tree->right) {
					node->root = tree;
					tree->right = node;
					nodes++;
					return;
				} else
					tree = tree->right;
			}
			else if (value == tree->value)
				return;
		}
	}
}

void BST::Delete(int value) {
	Node *node = head;
	Node *nodeRoot; //used as a previous aka root
	
	while (true) {
		//empty tree or value not found
		if (!node)
			return;
		
		//go left
		if (value < node->value) {
			nodeRoot = node;
			node = node->left;
		} 
		//go right
		else if (value > node->value) {
			nodeRoot = node;
			node = node->right;
		} 
		//found it!
		else if (value == node->value) {
			//node that has no children
			if (!node->left && !node->right) {
				if (node == head)
					head = NULL;
				else {
					//set the pointer of the root
					if (value < nodeRoot->value)
						nodeRoot->left = NULL;
					else
						nodeRoot->right = NULL;
				}

				
				delete node; //delete node memory
				nodes--; //decrement node count
				return;
			}
			//node that has left children, but no right child
			else if (!node->right) {
				if (node == head)
					head = node->left;
				else {
					//set the pointer of the root
					if (value < nodeRoot->value)
						nodeRoot->left = node->left;
					else
						nodeRoot->right = node->left;
				}
				
				delete node; //delete node memory
				nodes--; //decrement node count
				return;
			}
			//node that has a left and right children
			else {
				//find minimum value of right subtree
				int min = findMin(node->right)->value;
								
				Delete(min); //delete minimum node
				node->value = min; //set node to minimum value
				
				//check for head node
				if (node == head)
					head = node;
				
				return;
			}
		}
	}
}

Node* BST::findMin(Node *node) {
	//for empty
	if (!node)
		return NULL;
	//return lowest
	if (!node->left)
		return node;
	
	return findMin(node->left);
}

Node* BST::getHead() {
	return head;
}

int BST::getNodes() {
	return nodes;
}

int BST::getHeight(Node *node) {
	//for empty
	if (!node)
		return 0;
	
	//find highest subtree
	int left = getHeight(node->left);
	int right = getHeight(node->right);
	
	return 1 + max(left, right);
}

void BST::PreOrder(Node *node) {
	//for empty
	if (!node)
		return;
	//root
	cout << node->value << " ";
	//left subtree
	if (node->left)
		PreOrder(node->left);
	//right subtree
	if (node->right)
		PreOrder(node->right);
}

void BST::InOrder(Node *node) {
	//for empty
	if (!node)
		return;
	//left subtree
	if (node->left)
		InOrder(node->left);
	//print root
	cout << node->value << " ";
	//right subtree
	if (node->right)
		InOrder(node->right);
}

void BST::PostOrder(Node *node) {
	//for empty
	if (!node)
		return;
	//left subtree
	if (node->left)
		PostOrder(node->left);
	//right subtree
	if (node->right)
		PostOrder(node->right);
	//print root
	cout << node->value << " ";
}

void BST::LevelOrder() {
	Node *node = head;
	queue<Node *> queue;
	
	while (node) {
		cout << node->value << " ";
		
		//if left child exists, add
		if (node->left)
			queue.push(node->left);
		//if right child exists, add
		if (node->right)
			queue.push(node->right);
		if (!queue.empty()) {
			node = queue.front(); //set current to node at front of queue
			queue.pop(); //remove a element at end
		} else
			node = NULL; //set node to null, if queue is empty
	}
}

void BST::HCI() {
	map<int, vector<Node*> > map1;
	map<int, vector<string> > map2;
	Node *tree = head;
	
	//initialize two maps 0-height
	for (int i = 0; i < getHeight(head); i++) {
		map1[i];
		map2[i];
	}
	
	
	//Head node
	map1[0].push_back(head);
	int value = head->value;
	
	if (value < -9)
		map2[0].push_back(my::to_string(value));
	else if (value > -10 && value < 0)
		map2[0].push_back(my::to_string(value) + " ");
	else if (value > -1 && value < 10)
		map2[0].push_back(" " + my::to_string(value) + " ");
	else if (value > 9 && value < 100)
		map2[0].push_back(my::to_string(value) + " ");
	else if (value > 99)
		map2[0].push_back(my::to_string(value));
	else
		map2[0].push_back(my::to_string(value));
	
	
	for (int i = 1; i < getHeight(head); i++) {
		for(vector<Node*>::iterator j = map1[i-1].begin(); j != map1[i-1].end(); j++) {
			if ((*j)->left) {
				map1[i].push_back((*j)->left);
				
				int value = (*j)->left->value;
				
				if (value < -9)
					map2[i].push_back(my::to_string(value));
				else if (value > -10 && value < 0)
					map2[i].push_back(my::to_string(value) + " ");
				else if (value > -1 && value < 10)
					map2[i].push_back(" " + my::to_string(value) + " ");
				else if (value > 9 && value < 100)
					map2[i].push_back(my::to_string(value) + " ");
				else if (value > 99)
					map2[i].push_back(my::to_string(value));
				else
					map2[i].push_back(my::to_string(value));
			}
			else {
				map1[i].push_back(new Node(-2));
				map2[i].push_back(" x ");
			}
			if ((*j)->right){
				map1[i].push_back((*j)->right);
				
				int value = (*j)->right->value;
				
				if (value < -9)
					map2[i].push_back(my::to_string(value));
				else if (value > -10 && value < 0)
					map2[i].push_back(my::to_string(value) + " ");
				else if (value > -1 && value < 10)
					map2[i].push_back(" " + my::to_string(value) + " ");
				else if (value > 9 && value < 100)
					map2[i].push_back(my::to_string(value) + " ");
				else if (value > 99)
					map2[i].push_back(my::to_string(value));
				else
					map2[i].push_back(my::to_string(value));
			}
			else {
				map1[i].push_back(new Node(-2));
				map2[i].push_back(" x ");
			}
		}
	}

	//Print out tree
	for (int i = 0, j = map1.size(); i < map1.size(); i++, j--) {
		//initial space
		//2^n - 2
		for (int k = 0; k < (pow(2, j)-2); k++)
			cout << " ";
		
		for(vector<string>::iterator h = map2[i].begin(); h != map2[i].end(); h++) {
			cout << *h;
			
			//internal space
			//2^(n+1) - 3
			for (int k = 0; k < (pow(2, j+1)-3); k++)
				cout << " ";
		}
		cout << endl;
	}
}
