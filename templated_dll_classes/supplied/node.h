#ifndef NODE_H
#define NODE_H

template <class T> class DLL;

template <class T> class Node
{
  friend class DLL <T>;

  public:

    Node(const T &v): prev(NULL), value(v), next(NULL) { }
   ~Node() { }

  private:
    Node <T> *prev;
    Node <T> *next;
    T value;
};

#endif
