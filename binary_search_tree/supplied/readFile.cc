// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main (int argc, char** argv) {
  string token;
  ifstream file (argv[1]);
  if ( file.is_open() )
  {
    while ( file.good() )
    {
      string operation = "insert";
      getline(file, token, ' ');
      if( token.compare("insert") == 0){
	getline(file, token, '\n');
        int operand = atoi(token.c_str());
	cout << "Call bst's insert(" << operand << ") function" << endl;
      }
      if( token.compare("delete") == 0){
	
      }
      if( atoi(token.c_str()) != 0 ){
      	//cout << token << endl;
      }
      cout << token << endl;
    }
    file.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}
