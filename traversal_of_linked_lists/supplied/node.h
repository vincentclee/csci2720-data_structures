#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class Node
{
  public:

    Node(const string, const int) ;
   ~Node() { }
    void setNext(Node *);
    Node * getNext();
    string getKey();
    int getDistance();   

  private:
    Node *next;
    int dist;
    string key;
};

#endif

