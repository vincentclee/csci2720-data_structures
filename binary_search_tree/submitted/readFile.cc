// reading a text file
#include "bst.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv) {
	string token;
	//ifstream file ("test1.txt");
	ifstream file (argv[1]);
	BST bst;
	
	if (file.is_open()) {
		while (file.good()) {
			getline(file, token, ' ');
			
			if (token.compare("insert") == 0) {
				getline(file, token, '\n');
				int operand = atoi(token.c_str());
				cout << "Call bst's insert(" << operand << ") function" << endl;
				bst.Insert(operand);
			}
			if (token.compare("delete") == 0) {
				getline(file, token, '\n');
				int operand = atoi(token.c_str());
				cout << "Call bst's delete(" << operand << ") function" << endl;
				bst.Delete(operand);
			}
			if (atoi(token.c_str()) != 0) {} //collect whitespace
			
//			cout << token << endl;
		}
		file.close();
		
		cout << endl;
		cout << "Number of nodes in the bst: " << bst.getNodes() << endl;
		cout << "Height of the bst: " << bst.getHeight(bst.getHead())-1 << endl;
		
		cout << "Pre-order traversal:" << endl;
		bst.PreOrder(bst.getHead());
		cout << endl;
		
		cout << "In-order traversal:" << endl;
		bst.InOrder(bst.getHead());
		cout << endl;
		
		cout << "Post-order traversal:" << endl;
		bst.PostOrder(bst.getHead());
		cout << endl;
		
		cout << "Level-order traversal:" << endl;
		bst.LevelOrder();
		cout << endl;
		
		cout << "Extra credit tree visualization:" << endl;
		bst.HCI();
	} else
		cout << "Unable to open file";
	
	return 0;
}
