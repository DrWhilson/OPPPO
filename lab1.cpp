#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <regex>
#include <stdio.h>
#include <string>

using namespace std;

const float Pi = 3.14;

ofstream logs;

bool isContainNum(char *str) {
  for (int i = 0; i < strlen(str); i++) {
    if (isdigit(str[i]))
      return true;
  }
  return false;
}

bool checkName(char *str) { return !isContainNum(str) && isupper(str[0]); }

class Point3D {
public:
  int x, y, z;

  Point3D(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

class Fig {
public:
  char name[50];
  float P;
  virtual void print(ostream &ofile) const = 0;
  virtual int calcCap() const = 0;
  virtual bool setFig(char *comm) = 0;

  Fig() : name(""), P(0) {}

  virtual ~Fig() {}
};

class Sphere : public Fig {
public:
  int R;
  void print(ostream &ofile) const override {
    ofile << "!--Shpere--!\nName: " << name << "\nP: " << P << "\nR: " << R
          << endl;
  }

  int calcCap() const override { return ((4.0 / 3.0) * Pi * R * R); }

  bool setFig(char *comm) override {
    char check[50];
    if (sscanf(comm, "%*s %*s %*s%150[^\n\r]", check) == 1)
      return false;
    // std::vector<int> numbers{0, 1, 2, 3, 4, 5, 6, 7, 8};

    if ((sscanf(comm, "%s %f %d", name, &P, &R) == 3) && checkName(name)) {
      return true;
    } else {
      logs << "[WRN] Wrong parameters" << endl;
      return false;
    }
  }

  Sphere() : Fig(), R(0) {}
};

class Parallelepiped : public Fig {
public:
  int a, b, c;
  void print(ostream &ofile) const override {
    ofile << "!--Parallelepiped--!\nName: " << name << "\nP: " << P
          << "\nRibs: " << a << " " << b << " " << c << endl;
  }

  int calcCap() const override { return a * b * c; }

  bool setFig(char *comm) override {
    char check[50];
    if (sscanf(comm, "%*s %*s %*s %*s %*s%150[^\n\r]", check) == 1)
      return false;

    if ((sscanf(comm, "%s %f %d %d %d", name, &P, &a, &b, &c) == 5) &&
        checkName(name)) {
      return true;
    } else {
      logs << "[WRN] Wrong parameters" << endl;
      return false;
    }
  }

  Parallelepiped() : Fig(), a(0), b(0), c(0) {}
};

class Cylinder : public Fig {
public:
  Point3D center;
  float R, H;
  void print(ostream &ofile) const override {
    ofile << "!--Cylinder--!\nName: " << name << "\nP: " << P
          << "\nCoordinates: " << center.x << " " << center.y << " " << center.z
          << "\nR: " << R << "\nH: " << H << endl;
  }

  int calcCap() const override { return Pi * R * R * H; }

  bool setFig(char *comm) override {
    char check[50];
    if (sscanf(comm, "%*s %*s %*s %*s %*s %*s %*s%150[^\n\r]", check) == 1)
      return false;

    if ((sscanf(comm, "%s %f %d %d %d %f %f", name, &P, &center.x, &center.y,
                &center.z, &R, &H) == 7) &&
        checkName(name)) {
      return true;
    } else {
      logs << "[WRN] Wrong parameters" << endl;
      return false;
    }
  }

  Cylinder() : Fig(), center(0, 0, 0), R(0), H(0) {}
};

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
  bool is_empty() { return first == nullptr; }

  void push_back(Fig *newfig) {
    Node *p = new Node(newfig);
    if (is_empty()) {
      first = p;
      last = p;
      return;
    }
    last->next = p;
    p->prev = last;
    last = p;
  }

  void print(ostream &ofile) {
    if (is_empty())
      return;

    Node *p = first;
    ofile << "!----PRINT----!" << endl;
    while (p) {
      p->fig->print(ofile);
      p = p->next;
    }
  }

  void remove_first() {
    if (is_empty())
      return;
    if (first->next == nullptr) {
      delete first;
      first = last = nullptr;
      return;
    }
    Node *p = first;
    first = p->next;
    first->prev = nullptr;
    delete p;
  }

  void remove_last() {
    if (is_empty())
      return;
    if (first == last) {
      remove_first();
      return;
    }
    Node *p = last->prev;
    p->next = nullptr;
    delete last;
    last = p;
  }

  void remove(Fig *serfig) {
    if (is_empty())
      return;
    if (serfig == nullptr)
      return;

    if (first->fig == serfig) {
      remove_first();
      return;
    } else if (last->fig == serfig) {
      remove_last();
      return;
    }

    Node *slow = first;
    Node *fast = first->next;
    while (fast && fast->fig != serfig) {
      fast = fast->next;
      slow = slow->next;
    }
    if (!fast) {
      logs << "[INF] This element does not exist" << endl;
      return;
    }
    slow->next = fast->next;
    fast->next->prev = slow;
    delete fast;
  }

  void freeList() {
    if (is_empty())
      return;
    while (!is_empty())
      this->remove_first();
  }

  Fig *searchFirst(char *comm) {
    if (is_empty())
      return nullptr;

    char par[50];
    char oper[50];
    char inp[50];
    char check[50];
    if (sscanf(comm, "%*s %*s %*s %150[^\n\r]", check) == 1)
      return nullptr;
    if (sscanf(comm, "%s %s %s", par, oper, inp) != 3)
      return nullptr;

    map<string, function<bool(Fig *, string, string)>> pars = {
        {"name",
         [](Fig *f, string oper, string inp) {
           if (oper == "=") {
             return f->name == inp;
           } else
             logs << "[WRN] Not allowed operator" << endl;

           return false;
         }},
        {"capacity", [](Fig *f, string oper, string inp) {
           double cap = f->calcCap();
           int serCap = atoi(inp.c_str());
           logs << cap << " " << serCap << endl;
           if (oper == "=") {
             return cap == serCap;
           } else if (oper == "<") {
             return cap < serCap;
           } else if (oper == ">") {
             return cap > serCap;
           } else
             logs << "[WRN] Not allowed operator" << endl;
           return false;
         }}};

    Node *serNode = first;
    while (serNode) {
      if (pars[par](serNode->fig, oper, inp)) {
        logs << "[INF] Find fig" << endl;
        return serNode->fig;
      }
      serNode = serNode->next;
    }
    logs << "[INF] Found nothing :(" << endl;
    return nullptr;
  }
};

int main() {
  FILE *newfile = fopen("input", "r");
  logs.open("output");

  List lst;

  char comm[150];
  char incomm[150];
  char param[150];
  while (fgets(incomm, 149, newfile)) {
    sscanf(incomm, "%s", comm);
    if (string(comm) == "ADD") {
      Fig *obj;
      sscanf(incomm, "%*s %s %150[^\n\r]", comm, param);

      if (string(comm) == "Sphere") {
        obj = new Sphere();
      } else if (string(comm) == "Parallelepiped") {
        obj = new Parallelepiped();
      } else if (string(comm) == "Cylinder") {
        obj = new Cylinder();
      } else {
        obj = nullptr;
        logs << "[WRN] " << string(comm) << " is not a figure type" << endl;
      }

      if ((obj != nullptr) && (obj->setFig(param) == true)) {
        lst.push_back(obj);
        logs << "[INF] Figure created" << endl;
      } else {
        delete obj;
        logs << "[WRN] Can`t create a figure" << endl;
      }
    } else if (string(comm) == "REM") {
      sscanf(incomm, "%*s %150[^\n\r]", comm);
      lst.remove(lst.searchFirst(comm));
    } else if (string(comm) == "PRINT") {
      lst.print(cout);
    } else {
      logs << "[WRN] " << string(comm) << " is not a command!" << endl;
    }
  }

  logs << "[INF] Program finished!" << endl;

  lst.freeList();
  fclose(newfile);
  logs.close();

  return 0;
}
