#include <new>
#include "node.h"

Node::Node(const int value) {
    left = NULL;
    right = NULL;
    root = NULL;
    this->value = value;
}

Node::~Node() {
	
}
