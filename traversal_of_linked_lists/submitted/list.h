//============================================================================
// Name        : list.h
// Author      : Vincent Lee
// Version     : 1.0
// Copyright   : SSLTunnel.net
// Description : The list header file.
//============================================================================

#ifndef LIST_H
#define LIST_H

#include "node.h"

class List {
	public:
		List();
		~List();
		void Insert (string searchKey, int distance);
		bool Delete (string searchKey);
		void Search(string searchKey);
		Node* getHead() const;
		void Print();
	private:
		Node *head;
};

#endif
