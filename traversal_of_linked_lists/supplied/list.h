#ifndef LIST_H
#define LIST_H

#include "node.h"

class SLL
{
	public:
		SLL();
		~SLL();
               void Insert (string searchKey, int distance);
               bool Delete (string searchKey);
               void Print();
               //TODO Search
		
	private:
		Node *head;
};

#endif

