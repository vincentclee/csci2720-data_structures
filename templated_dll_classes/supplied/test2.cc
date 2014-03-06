#include "list1.h"
#include <iostream>

using std::cout;
using std::endl;

void Double_It(double &val){
val = val * 2.0;
}

main(int argc, char *argv){

DLL<double> listOfDoubles;
DLL<double> anotherListOfDoubles;

cout << endl;
cout << "empty listOfDoubles successfully created" << endl;
cout << endl;

if (listOfDoubles.IsEmpty())
	cout << "and confirmed to be empty. " << endl;
else
	cout << "but not found empty. " << endl;
cout << endl;

listOfDoubles.Push_front(1.1);
cout << "Pushed 1.1 on front " << endl;
cout << "List now contains: ";
listOfDoubles.Print();
cout << endl;

listOfDoubles.Push_front(2.2);
cout << "Pushed 2.2 on front " << endl;
cout << "List now contains: ";
listOfDoubles.Print();
cout << endl;

listOfDoubles.Push_front(3.3);
cout << "Pushed 3.3 on front " << endl;
cout << "List now contains: ";
listOfDoubles.Print();
cout << endl;

listOfDoubles.Push_front(4.4);
cout << "Pushed 4.4 on front " << endl;
cout << "List now contains: ";
listOfDoubles.Print();
cout << endl;

listOfDoubles.Push_front(5.5);
cout << "Pushed 5.5 on front " << endl;
cout << "List now contains: ";
listOfDoubles.Print();
cout << endl;

listOfDoubles.Push_front(6.6);
cout << "Pushed 6.6 on front " << endl;
cout << "List now contains: ";
listOfDoubles.Print();
cout << endl;

if (listOfDoubles.IsEmpty())
	cout << "but you found it empty." << endl;
else
	cout << "and is now not empty. " << endl;
cout << endl;

cout << "listOfDoubles contains " << listOfDoubles.Length() << " elements. " << endl;
cout << "Specifically: ";
listOfDoubles.Print();
cout << endl;

cout << "Now we double all values: ";
listOfDoubles.Iterate(Double_It);
cout << "and get ...: ";
listOfDoubles.Print();
cout << endl;

cout << "Now we reverse the list and get: ";
listOfDoubles.Reverse();
listOfDoubles.Print();
cout << endl;

cout << "and reverse it again and get: ";
listOfDoubles.Reverse();
listOfDoubles.Print();
cout << endl;

cout << "Backwards that is ... ";
listOfDoubles.PrintBack();
cout << endl;

cout << "The item at the front is: " << listOfDoubles.Front() << endl;
cout << endl;

cout << "The item at the back is: " << listOfDoubles.Back() << endl;
cout << endl;


 
if (!(listOfDoubles.IsEmpty())){
	listOfDoubles.Pop_front();
	cout << "Popped from the front, listOfDoubles now contains " 
             << listOfDoubles.Length() << " elements. " << endl;
	cout << "Specifically: ";
	listOfDoubles.Print();
	cout << endl;
	cout << "Backwards that is ... ";
	listOfDoubles.PrintBack();
	cout << endl;
	}
else{
	cout << "Couldn't pop from an empty list. " << endl;
}


if (!(listOfDoubles.IsEmpty())){
	listOfDoubles.Pop_front();
	cout << "Popped from the front, listOfDoubles now contains " 
             << listOfDoubles.Length() << " elements. " << endl;
	cout << "Specifically: ";
	listOfDoubles.Print();
	cout << endl;
	cout << "Backwards that is ... ";
	listOfDoubles.PrintBack();
	cout << endl;
	}
else{
	cout << "Couldn't pop from an empty list. " << endl;
}


if (!(listOfDoubles.IsEmpty())){
	listOfDoubles.Pop_front();
	cout << "Popped from the front, listOfDoubles now contains " 
             << listOfDoubles.Length() << " elements. " << endl;
	cout << "Specifically: ";
	listOfDoubles.Print();
	cout << endl;
	cout << "Backwards that is ... ";
	listOfDoubles.PrintBack();
	cout << endl;
	}
else{
	cout << "Couldn't pop from an empty list. " << endl;
}


if (!(listOfDoubles.IsEmpty())){
	listOfDoubles.Pop_front();
	cout << "Popped from the front, listOfDoubles now contains " 
             << listOfDoubles.Length() << " elements. " << endl;
	cout << "Specifically: ";
	listOfDoubles.Print();
	cout << endl;
	cout << "Backwards that is ... ";
	listOfDoubles.PrintBack();
	cout << endl;
	}
else{
	cout << "Couldn't pop from an empty list. " << endl;
}


if (!(listOfDoubles.IsEmpty())){
	listOfDoubles.Pop_front();
	cout << "Popped from the front, listOfDoubles now contains " 
             << listOfDoubles.Length() << " elements. " << endl;
	cout << "Specifically: ";
	listOfDoubles.Print();
	cout << endl;
	cout << "Backwards that is ... ";
	listOfDoubles.PrintBack();
	cout << endl;
	}
else{
	cout << "Couldn't pop from an empty list. " << endl;
}

if (!(listOfDoubles.IsEmpty())){
	listOfDoubles.Pop_front();
	cout << "Popped from the front, listOfDoubles now contains " 
             << listOfDoubles.Length() << " elements. " << endl;
	cout << "Specifically: ";
	listOfDoubles.Print();
	cout << endl;
	cout << "Backwards that is ... ";
	listOfDoubles.PrintBack();
	cout << endl;
	}
else{
	cout << "Couldn't pop from an empty list. " << endl;
}

cout << "Can we reverse an empty list??" << endl;
listOfDoubles.Reverse();
cout << "Yes!! " << endl;

}
