//============================================================================
// Name        : node.cpp
// Author      : Vincent Lee
// Version     : 1.0
// Copyright   : SSLTunnel.net
// Description : The node source file.
//============================================================================

#include <iostream>
using namespace std;

#include "node.h"

/**
 * Node constructor sets string value, integer, and next node.
 */
Node::Node(const string allocator, const int constInt, Node* next) {
	key = allocator;
	dist = constInt;
	this->next = next;
}

/**
 * Deconstructor removes the head pointer during the return 0 call.
 */
Node::~Node() {
//	delete next;
}

/**
 * setNode setter method sets next node with a Node pointer object.
 */
void Node::setNext(Node* next) {
	this->next = next;
}

/**
 * setDist setter method sets distance with a integer parameter. 
 */
void Node::setDist(int dist) {
	this->dist = dist;
}

/**
 * getNext getter method returns next node in the linked list.
 */
Node* Node::getNext() {
	return next;
}

/**
 * getKey getter method returns the key or search string.
 */
string Node::getKey() {
	return key;
}

/**
 * getDistance getter method returns the distance of a particular node.
 */
int Node::getDistance() {
	return dist;
}
