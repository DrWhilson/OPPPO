#include <cctype>
#include <cstdio>
#include <fstream>
#include <functional>
#include <map>
#include <regex>
#include <stdio.h>
#include <string>

using namespace std;

#include "my_list.cpp"

FILE *logs;

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
    fprintf(logs, "[WRN] %s is not a figure type!\n", comm);
  }

  if ((obj != nullptr) && (obj->setFig(param) == true)) {
    lst->push_back(obj);
    fprintf(logs, "[INF] Figure created!\n");

  } else {
    delete obj;
    fprintf(logs, "[WRN] Can`t create a figure!\n");
  }
}

void remCom(List *lst, char *comm) { lst->remove_all_by_condition(comm); }
void printCom(List *lst) { lst->print(stdout); }

int main() {
  FILE *newfile = fopen("input", "r");
  logs = fopen("output", "w");

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
      fprintf(logs, "[WRN] %s is not a command!\n", param);
    }
  }

  fprintf(logs, "[INF] Programm finished!\n");

  lst.freeList();
  fclose(newfile);
  fclose(logs);

  return 0;
}
