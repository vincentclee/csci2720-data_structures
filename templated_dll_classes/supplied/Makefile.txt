all:	test1 test2

test1:	list1.h test1.cc
	g++ -o test1 test1.cc 

test2:	list1.h test2.cc
	g++ -o test2 test2.cc 



