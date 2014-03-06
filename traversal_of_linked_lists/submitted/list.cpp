//============================================================================
// Name        : list.cpp
// Author      : Vincent Lee
// Version     : 1.0
// Copyright   : SSLTunnel.net
// Description : The list source file.
//============================================================================

#include <cassert>
#include <iostream>
#include "list.h"

using namespace std;

/**
 * Default constructor initializes head node to 0.
 */
List::List() {
	  head = 0;
}

/**
 * Deconstructor removes all nodes.
 * It also removes itself, and the head node pointer.
 */
List::~List() {
	Node* nodeRemover = head;
	while (nodeRemover != 0) {
		nodeRemover = nodeRemover->getNext();
		delete head;
		head = nodeRemover;
	}
	
	//Remove all the evidence.
	delete nodeRemover;
	delete head;
}

/**
 * Insert method takes a search key and a integer value.
 * If the search key is found, the integer value is replaced.
 * If the search key is not found, a new node is pushed onto the front,
 * and that becomes the head node. 
 */
void List::Insert(string searchKey, int distance) {
	//If the list is empty, create a new node automatically.
	if (head == 0)
	    head = new Node(searchKey, distance, head);
	/**
	 * If the list is not empty, look through the whole list,
	 * if a match is found, a new integer value is set for distance.
	 * It will then set found to true, and break out, saving cycles.
	 */
	else {
	    Node* node = head;
	    bool found = false;
	    while (node != 0) {
	    	if (node->getKey().compare(searchKey) == 0) {
	    		node->setDist(distance);
	    		found = true;
	    		break;
	    	}
	    	node = node->getNext();
	    }
	    
	    //If the found value is true, create a new node on the front of the list.
	    if (!found)
	    	head = new Node(searchKey, distance, head);
	}
}

/**
 * Delete method inputs a search key and searches the list and if the element is found,
 * it is removed by this method.
 */
bool List::Delete(string searchKey) {
	if (head != 0) {
		Node* node = head;
		if (node->getKey().compare(searchKey) == 0) {
			head = head->getNext();
			delete node;
			return true;
		} else {
			while (node->getNext() != 0) {
				Node* noder = node->getNext();
				if (noder->getKey().compare(searchKey) == 0) {
					node->setNext(noder->getNext());
					delete noder;
					break;
				} else
					node = noder;
			}
		}
	}
	return false;
}

/**
 * Search method inputs a search key and searches the list for matches.
 * It implements two pointers which only move forward.
 * If a searchKey is found, the distance needed to be traveled is computed
 * through logic, and a second pointer takes control.
 * This method prints out distance integer value and/or string key.
 */
void List::Search(string searchKey) {
	if (head != 0) {
		Node* node = head;
		Node* noder = head;
		int position = 0;
		bool enterNeeded = false;
		
		/**
		 * The while loop will search through the list, and find the item.
		 * If the item is found, the position is frozen and saved for the second pointer.
		 */
		while (node != 0) {
			if (node->getKey().compare(searchKey) == 0) {
				cout << node->getDistance() << " ";
				enterNeeded = true;
				break;	
			}
			node = node->getNext();
			position++;
		}
		
		/**
		 * Second pointer takes over.
		 * If the position of the node with the matching string is
		 * greater than or equal to the distance needed to travel backwards.
		 * For loop iterates the correct amount of times.
		 * position - distance = iterations. 
		 */
		if (position >= node->getDistance()) {
			for (int i = 0; i < (position-node->getDistance()); i++) {
				noder = noder->getNext();
			}
			cout << noder->getKey() << endl;
			enterNeeded = false;
		}
		if (enterNeeded)
			cout << endl;
	}
}

/**
 * Print method list all elements in the linked list.
 * 
 */
void List::Print() {
	Node* node = head;
	while (node != 0) {
		cout << node->getKey() << "-" << node->getDistance();
		node = node->getNext();
		
		/**
		 * Little piece of logic which only prints out a string when
		 * not at the end, and actually separating items.
		 */
		if (node != 0)
			cout << ", ";
	}
	//Returns to the next line.
	if (head != 0)
		cout << endl;
}
