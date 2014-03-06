//============================================================================
// Name        : permutations.cpp
// Author      : Vincent Lee
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Generates all permutations of objects
//============================================================================

#include <array>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

template <class T> void permutate(vector<T>, bool);

int main(int argc, char **argv) {
	//argv[0] path
	//argv[1] type
	//argv[2] boolean
	if (argc > 1) {
		if (strcmp(argv[1], "int") == 0) {
			cout << "int: 1 2 3 4" << endl; 
			
			vector<int> array;
			array.push_back(1);
			array.push_back(2);
			array.push_back(3);
			array.push_back(4);
			
			if (argc > 2)
				permutate(array, true);
			else
				permutate(array, false);
		} else if (strcmp(argv[1], "double") == 0) {
			cout << "double: .1 0.2 1.3 .4" << endl;
			
			vector<double> array;
			array.push_back(.1);
			array.push_back(0.2);
			array.push_back(1.3);
			array.push_back(.4);
			
			if (argc > 2)
				permutate(array, true);
			else
				permutate(array, false);
		} else if (strcmp(argv[1], "char") == 0) {
			cout << "char: a b c d" << endl;
			
			vector<char> array;
			array.push_back('a');
			array.push_back('b');
			array.push_back('c');
			array.push_back('d');
			
			if (argc > 2)
				permutate(array, true);
			else
				permutate(array, false);
		} else if (strcmp(argv[1], "string") == 0) {
			cout << "string: one two three four" << endl;
			
			vector<string> array;
			array.push_back("one");
			array.push_back("two");
			array.push_back("three");
			array.push_back("four");
			
			if (argc > 2)
				permutate(array, true);
			else
				permutate(array, false);
		}
	} else {
		cout << "Enter a list of non-repeating elements separated by a space: ";
		
		//get input as one line
		string input;
		getline (cin, input);
		
		//tokenize string
		string temp;
		vector<string> tokens;
		stringstream ss(input);
		while(ss >> temp)
			tokens.push_back(temp);
		
		//enable to separate objects
		bool seperator = true;
		
		//compute
		permutate(tokens, seperator);
	}
	return 0;
}

template <class T> void permutate(const vector<T> array, const bool seperator) {
	int numbers = array.size();
	
	//calculate factorial
	for (int i = array.size()-1; i > 0; i--)
		numbers *= i;
	
	//holds output
	vector<string> output;
	
	//runs until all items are generated
	while (output.size() != numbers) {
		//list of non repeating random numbers
		vector<int> random; 
		
		//generates non repeating random numbers
		for (int i = 0; i < array.size(); i++) {
			int randomNumber = rand() % array.size();
			
			//if already exists, generate a number that does not exist
			while (find(random.begin(), random.end(), randomNumber) != random.end())
				randomNumber = rand() % array.size();
			
			//add number
			random.push_back(randomNumber);
		}
		
		string permutation;
		
		//generate a test permutation
		for (int i = 0; i < array.size(); i++) {
			stringstream strs;
			strs << array[random.at(i)];
			permutation += strs.str();
			if (seperator && i < array.size()-1)
				permutation += " ";
		}
		
		//if permutation does not exist, add
		if (!(find(output.begin(), output.end(), permutation) != output.end()))
			output.push_back(permutation);
	}
	
	//sort list of permutations
	sort (output.begin(), output.end());
	
	//print out permutations
	for(vector<string>::iterator i = output.begin(); i != output.end(); i++) {
		cout << *i;
		cout << endl;
	}
	
	cout << "Permutations: " << numbers << endl;
}
