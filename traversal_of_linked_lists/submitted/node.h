//============================================================================
// Name        : node.h
// Author      : Vincent Lee
// Version     : 1.0
// Copyright   : SSLTunnel.net
// Description : The node header file.
//============================================================================

#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class Node {
  public:
    Node(const string, const int, Node* next);
    ~Node();
    void setNext(Node *);
    void setDist(int dist);
    Node * getNext();
    string getKey();
    int getDistance();   
  private:
    Node *next;
    int dist;
    string key;
};

#endif
