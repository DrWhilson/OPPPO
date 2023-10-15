#include "my_list.h"
#include <cstdio>

using namespace std;

bool List::is_empty() { return first == nullptr; }

void List::push_back(Fig *newfig) {
  Node *newNode = new Node(newfig);
  if (is_empty()) {
    first = newNode;
    last = newNode;
    return;
  }
  last->next = newNode;
  newNode->prev = last;
  last = newNode;
}

void List::print(FILE *ofile) {
  if (is_empty())
    return;

  Node *searNode = first;
  std::fprintf(ofile, "!----PRINT----!\n");
  // ofile << "!----PRINT----!" << endl;
  while (searNode) {
    searNode->fig->print(ofile);
    searNode = searNode->next;
  }
}

void List::remove_first() {
  if (is_empty())
    return;
  if (first->next == nullptr) {
    delete first;
    first = last = nullptr;
    return;
  }
  Node *searNode = first;
  first = searNode->next;
  first->prev = nullptr;
  delete searNode;
}

void List::remove_last() {
  if (is_empty())
    return;
  if (first == last) {
    remove_first();
    return;
  }
  Node *searNode = last->prev;
  searNode->next = nullptr;
  delete last;
  last = searNode;
}

bool List::remove_node(Node *remNode) {
  if (is_empty())
    return false;
  if (remNode == nullptr)
    return false;

  if (first == remNode) {
    remove_first();
    return true;
  } else if (last == remNode) {
    remove_last();
    return true;
  }

  Node *searNode = first->next;
  while (searNode && searNode != remNode) {
    searNode = searNode->next;
  }
  if (!searNode) {
    return false;
  }
  searNode->prev->next = searNode->next;
  searNode->next->prev = searNode->prev;
  delete searNode;
  return true;
}

void List::freeList() {
  if (is_empty())
    return;
  while (!is_empty())
    this->remove_first();
}

bool List::checkCondition(Node *checkNode, char *comm) {
  if (is_empty())
    return false;

  char par[50];
  char oper[50];
  char inp[50];
  char check[50];
  if (sscanf(comm, "%*s %*s %*s%150[^\n\r]", check) == 1)
    return false;
  if (sscanf(comm, "%s %s %s", par, oper, inp) != 3)
    return false;

  map<string, function<bool(Fig *, string, string)>> pars = {
      {"name",
       [](Fig *f, string oper, string inp) {
         if (oper == "=") {
           return f->name == inp;
         } else

           return false;
       }},
      {"capacity", [](Fig *f, string oper, string inp) {
         double cap = f->calcCap();
         int serCap = atoi(inp.c_str());
         if (oper == "=") {
           return cap == serCap;
         } else if (oper == "<") {
           return cap < serCap;
         } else if (oper == ">") {
           return cap > serCap;
         } else
           return false;
       }}};

  if (pars[par](checkNode->fig, oper, inp)) {
    return true;
  }
  return false;
}

void List::remove_all_by_condition(char *comm) {
  Node *serNode = this->first;
  while (serNode) {
    if (this->checkCondition(serNode, comm)) {
    }
    serNode = serNode->next;
  }
}
