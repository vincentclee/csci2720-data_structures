#include "list1.h"
#include <iostream>

using std::cout;
using std::endl;

void Double_It(int &val){
val = val * 2;
}

main(int argc, char *argv){

DLL<int> listOfInts;
DLL<int> anotherListOfInts;

cout << endl;
cout << "empty listOfInts successfully created" << endl;
cout << endl;

if (listOfInts.IsEmpty())
	cout << "and confirmed to be empty. " << endl;
else
	cout << "but not found empty. " << endl;
cout << endl;

listOfInts.Push_front(1);
cout << "Pushed 1 on front " << endl;
cout << "List now contains: ";
listOfInts.Print();
cout << endl;

listOfInts.Push_front(2);
cout << "Pushed 2 on front " << endl;
cout << "List now contains: ";
listOfInts.Print();
cout << endl;

listOfInts.Push_front(3);
cout << "Pushed 3 on front " << endl;
cout << "List now contains: ";
listOfInts.Print();
cout << endl;

listOfInts.Push_front(4);
cout << "Pushed 4 on front " << endl;
cout << "List now contains: ";
listOfInts.Print();
cout << endl;

listOfInts.Push_front(5);
cout << "Pushed 5 on front " << endl;
cout << "List now contains: ";
listOfInts.Print();
cout << endl;

listOfInts.Push_front(6);
cout << "Pushed 6 on front " << endl;
cout << "List now contains: ";
listOfInts.Print();
cout << endl;

listOfInts.Push_back(0);
cout << "Pushed 0 on back " << endl;
cout << "List now contains: ";
listOfInts.Print();
cout << endl;

if (listOfInts.IsEmpty())
	cout << "but you found it empty." << endl;
else
	cout << "and is now not empty. " << endl;
cout << endl;

cout << "listOfInts contains " << listOfInts.Length() << " elements. " << endl;
cout << "Specifically: ";
listOfInts.Print();
cout << endl;

cout << "Now we double all values: ";
listOfInts.Iterate(Double_It);
cout << "and get ...: ";
listOfInts.Print();
cout << endl;

cout << "Now we reverse the list and get: ";
listOfInts.Reverse();
listOfInts.Print();
cout << endl;

cout << "and reverse it again and get: ";
listOfInts.Reverse();
listOfInts.Print();
cout << endl;

cout << "Backwards that is ... ";
listOfInts.PrintBack();
cout << endl;

cout << "The item at the front is: " << listOfInts.Front() << endl;
cout << endl;

cout << "The item at the back is: " << listOfInts.Back() << endl;
cout << endl;


 
if (!(listOfInts.IsEmpty())){
	listOfInts.Pop_front();
	cout << "Popped from the front, listOfInts now contains " 
             << listOfInts.Length() << " elements. " << endl;
	cout << "Specifically: ";
	listOfInts.Print();
	cout << endl;
	cout << "Backwards that is ... ";
	listOfInts.PrintBack();
	cout << endl;
	}
else{
	cout << "Couldn't pop from an empty list. " << endl;
}


if (!(listOfInts.IsEmpty())){
	listOfInts.Pop_front();
	cout << "Popped from the front, listOfInts now contains " 
             << listOfInts.Length() << " elements. " << endl;
	cout << "Specifically: ";
	listOfInts.Print();
	cout << endl;
	cout << "Backwards that is ... ";
	listOfInts.PrintBack();
	cout << endl;
	}
else{
	cout << "Couldn't pop from an empty list. " << endl;
}


if (!(listOfInts.IsEmpty())){
	listOfInts.Pop_front();
	cout << "Popped from the front, listOfInts now contains " 
             << listOfInts.Length() << " elements. " << endl;
	cout << "Specifically: ";
	listOfInts.Print();
	cout << endl;
	cout << "Backwards that is ... ";
	listOfInts.PrintBack();
	cout << endl;
	}
else{
	cout << "Couldn't pop from an empty list. " << endl;
}


if (!(listOfInts.IsEmpty())){
	listOfInts.Pop_front();
	cout << "Popped from the front, listOfInts now contains " 
             << listOfInts.Length() << " elements. " << endl;
	cout << "Specifically: ";
	listOfInts.Print();
	cout << endl;
	cout << "Backwards that is ... ";
	listOfInts.PrintBack();
	cout << endl;
	}
else{
	cout << "Couldn't pop from an empty list. " << endl;
}


if (!(listOfInts.IsEmpty())){
	listOfInts.Pop_front();
	cout << "Popped from the front, listOfInts now contains " 
             << listOfInts.Length() << " elements. " << endl;
	cout << "Specifically: ";
	listOfInts.Print();
	cout << endl;
	cout << "Backwards that is ... ";
	listOfInts.PrintBack();
	cout << endl;
	}
else{
	cout << "Couldn't pop from an empty list. " << endl;
}

if (!(listOfInts.IsEmpty())){
	listOfInts.Pop_front();
	cout << "Popped from the front, listOfInts now contains " 
             << listOfInts.Length() << " elements. " << endl;
	cout << "Specifically: ";
	listOfInts.Print();
	cout << endl;
	cout << "Backwards that is ... ";
	listOfInts.PrintBack();
	cout << endl;
	}
else{
	cout << "Couldn't pop from an empty list. " << endl;
}

cout << "Can we reverse an empty list??" << endl;
listOfInts.Reverse();
cout << "Yes!! " << endl;


	



}
