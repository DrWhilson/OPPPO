#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <regex>
#include <stdio.h>
#include <string>

using namespace std;

#include "my_list.cpp"

ofstream logs;

void addCom(List *lst, char *comm, char *param) {
  Fig *obj;
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
    lst->push_back(obj);
    logs << "[INF] Figure created" << endl;
  } else {
    delete obj;
    logs << "[WRN] Can`t create a figure" << endl;
  }
}

void remCom(List *lst, char *comm) { lst->remove(lst->searchFirst(comm)); }
void printCom(List *lst) { lst->print(cout); }

int main() {
  FILE *newfile = fopen("input", "r");
  logs.open("output");

  List lst;

  char param[150];
  char commline[150];
  char comm[150];
  while (fgets(commline, 149, newfile)) {
    sscanf(commline, "%s", param);
    if (string(param) == "ADD") {
      sscanf(commline, "%*s %s %150[^\n\r]", comm, param);
      addCom(&lst, comm, param);
    } else if (string(param) == "REM") {
      sscanf(commline, "%*s %150[^\n\r]", param);
      remCom(&lst, param);
    } else if (string(param) == "PRINT") {
      printCom(&lst);
    } else {
      logs << "[WRN] " << string(param) << " is not a command!" << endl;
    }
  }

  logs << "[INF] Program finished!" << endl;

  lst.freeList();
  fclose(newfile);
  logs.close();

  return 0;
}
