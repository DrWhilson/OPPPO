#include "figure.cpp"
#include <cctype>
// #include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <regex>
#include <stdio.h>
#include <string>

struct Node {
  Fig *fig;
  Node *next;
  Node *prev;

  Node(Fig *newfig) : fig(newfig), next(nullptr), prev(nullptr) {}
};

struct List {
  Node *first;
  Node *last;

  List() : first(nullptr), last(nullptr) {}
  bool is_empty();
  void push_back(Fig *newfig);

  void print(FILE *ofile);

  void remove_first();
  void remove_last();
  void remove(Node *remNode);
  void freeList();

  Node *searchFirst(char *comm);
};
