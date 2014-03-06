//============================================================================
// Name        : Project.cpp
// Author      : Vincent Lee
// Version     : 1.0.9
// Copyright   : SSLTunnel.net
// Description : Contains the main class to run Linked List program.
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

/**
 * The main class runs the program and takes in a command line argument for the file.txt.
 */
int main(int argc, char* argv[]) {
	List mainList; //Main linked list storing all of the nodes.
	string line; //Input for getline.
	
	//Read in the file in argument[1].
	ifstream infile(argv[1]);
	if (infile.is_open()) {
		while (infile.good()) {
			getline (infile,line);
			//The if statement checks if the line is empty. 
			if (!line.empty()) {
				//Using istringstream to parse the line into tokens. 
				istringstream parse(line);
				
				//START: Temporary variables for parsing.
				char operation = 'e';
				string searchKey = "";
				int number = 0;
				string extra = "";
				//END: Temporary variable for parsing.
				
				//This line will parse the string line into different values.
				parse >> operation >> searchKey >> number >> extra;
				
				/**
				 * Converts the operation (I, D, S) into lowercase.
				 * Lowercase letters are less prone to errors where I l look the same.
				 */
				operation = tolower(operation);
				
				/**
				 * The switch statement is use as a  selection control mechanism to determine
				 * user input with respects to insertion, deletion, search. 
				 */
				switch (operation) {
					//Insertion operation: I [Search key] [Integer]
					case 'i':
						cout << line << endl;
						mainList.Insert(searchKey, number);
						mainList.Print();
						break;
					//Deletion operation: D [Search key]
					case 'd':
						cout << line << endl;
						mainList.Delete(searchKey);
						mainList.Print();
						break;
					//Search operation: S [Search key]
					case 's':
						cout << line << endl;
						mainList.Search(searchKey);
						break;
					//All other erroneous input gets rejected. 
					default:
						break;
				}
			}
		}
		//Close the input  file. VERY IMPORTANT
		infile.close();
	}
	//If the file is corrupted or unable to open, display a message.
	else
		cout << "ERROR: Unable to open file" << endl << endl;
	
	//VERY IMPORTANT: returning 0 also calls the deconstructors for the classes.
	return 0;
}
