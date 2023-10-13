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

bool isPositive(int num) { return num >= 0; }

bool isPositive(float num) { return num >= 0; }

class Point3D {
public:
  int x, y, z;

  Point3D(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

class Fig {
public:
  char name[50];
  float Density;
  virtual void print(ostream &ofile) const = 0;
  virtual int calcCap() const = 0;
  virtual bool setFig(char *comm) = 0;

  Fig() : name(""), Density(0) {}

  virtual ~Fig() {}
};

class Sphere : public Fig {
public:
  int Radius;
  void print(ostream &ofile) const override {
    ofile << "!--Shpere--!\nName: " << name << "\nP: " << Density
          << "\nR: " << Radius << endl;
  }

  int calcCap() const override { return ((4.0 / 3.0) * Pi * Radius * Radius); }

  bool setFig(char *comm) override {
    char check[50];
    if (sscanf(comm, "%*s %*s %*s%150[^\n\r]", check) == 1)
      return false;

    if ((sscanf(comm, "%s %f %d", name, &Density, &Radius) == 3) &&
        checkName(name) && isPositive(Density) && isPositive(Radius)) {
      return true;
    } else {
      logs << "[WRN] Wrong parameters" << endl;
      return false;
    }
  }

  Sphere() : Fig(), Radius(0) {}
};

class Parallelepiped : public Fig {
public:
  int edgeA, edgeB, edgeC;
  void print(ostream &ofile) const override {
    ofile << "!--Parallelepiped--!\nName: " << name << "\nP: " << Density
          << "\nRibs: " << edgeA << " " << edgeB << " " << edgeC << endl;
  }

  int calcCap() const override { return edgeA * edgeB * edgeC; }

  bool setFig(char *comm) override {
    char check[50];
    if (sscanf(comm, "%*s %*s %*s %*s %*s%150[^\n\r]", check) == 1)
      return false;

    if ((sscanf(comm, "%s %f %d %d %d", name, &Density, &edgeA, &edgeB,
                &edgeC) == 5) &&
        checkName(name) && isPositive(Density) && isPositive(edgeA) &&
        isPositive(edgeB) && isPositive(edgeC)) {
      return true;
    } else {
      logs << "[WRN] Wrong parameters" << endl;
      return false;
    }
  }

  Parallelepiped() : Fig(), edgeA(0), edgeB(0), edgeC(0) {}
};

class Cylinder : public Fig {
public:
  Point3D center;
  float Radius, Hight;
  void print(ostream &ofile) const override {
    ofile << "!--Cylinder--!\nName: " << name << "\nP: " << Density
          << "\nCoordinates: " << center.x << " " << center.y << " " << center.z
          << "\nR: " << Radius << "\nH: " << Hight << endl;
  }

  int calcCap() const override { return Pi * Radius * Radius * Hight; }

  bool setFig(char *comm) override {
    char check[50];
    if (sscanf(comm, "%*s %*s %*s %*s %*s %*s %*s%150[^\n\r]", check) == 1)
      return false;

    if ((sscanf(comm, "%s %f %d %d %d %f %f", name, &Density, &center.x,
                &center.y, &center.z, &Radius, &Hight) == 7) &&
        checkName(name) && isPositive(Density) && isPositive(Radius) &&
        isPositive(Hight)) {
      return true;
    } else {
      logs << "[WRN] Wrong parameters" << endl;
      return false;
    }
  }

  Cylinder() : Fig(), center(0, 0, 0), Radius(0), Hight(0) {}
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

  void print(ostream &ofile) {
    if (is_empty())
      return;

    Node *searNode = first;
    ofile << "!----PRINT----!" << endl;
    while (searNode) {
      searNode->fig->print(ofile);
      searNode = searNode->next;
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
    Node *searNode = first;
    first = searNode->next;
    first->prev = nullptr;
    delete searNode;
  }

  void remove_last() {
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

  void remove(Node *sernode) {
    if (is_empty())
      return;
    if (sernode == nullptr)
      return;

    if (first == sernode) {
      remove_first();
      return;
    } else if (last == sernode) {
      remove_last();
      return;
    }

    Node *searNode = first->next;
    while (searNode && searNode != sernode) {
      searNode = searNode->next;
    }
    if (!searNode) {
      logs << "[INF] This element does not exist" << endl;
      return;
    }
    searNode->prev->next = searNode->next;
    searNode->next->prev = searNode->prev;
    delete searNode;
  }

  void freeList() {
    if (is_empty())
      return;
    while (!is_empty())
      this->remove_first();
  }

  Node *searchFirst(char *comm) {
    if (is_empty())
      return nullptr;

    char par[50];
    char oper[50];
    char inp[50];
    char check[50];
    if (sscanf(comm, "%*s %*s %*s%150[^\n\r]", check) == 1)
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
        return serNode;
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
