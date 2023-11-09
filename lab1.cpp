#include "lab1.h"

// #include <list>
// #include <map>
// #include <stdio.h>
// #include <string>

// #include "figure.h"

FILE *logs;

using namespace std;

void deleteList(std::list<Fig *> *lst) {
  for (std::list<Fig *>::iterator it = lst->begin(); it != lst->end();) {
    Fig *ptr = *it;
    delete ptr;
    it = lst->erase(it);
  }
}

bool isKeyContain(std::vector<std::string> keys, std::string check_key) {
  for (int i = 0; i < keys.size(); i++) {
    if (keys[i] == check_key)
      return true;
  }
  return false;
}

bool checkCondition(Fig *fig, char *comm) {
  if (fig == nullptr)
    return false;

  char del_param[50];
  char oper[50];
  char input_param[50];
  char check[50];
  if (sscanf(comm, "%*s %*s %*s%150[^\n\r]", check) == 1)
    return false;
  if (sscanf(comm, "%s %s %s", del_param, oper, input_param) != 3)
    return false;

  vector<string> keys = {"name", "capacity"};

  map<string, function<bool(Fig *, string, string)>> pars = {
      {keys[0],
       [](Fig *f, string oper, string inp) {
         if (oper == "=") {
           return f->name == inp;
         } else
           return false;
       }},
      {keys[1], [](Fig *f, string oper, string inp) {
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

  if (isKeyContain(keys, del_param) &&
      pars[del_param](fig, oper, input_param)) {
    return true;
  }
  return false;
}

void addCom(std::list<Fig *> *lst, char *comm, char *param) {
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

  if ((obj != nullptr) && (obj->setFig(param))) {
    lst->push_back(obj);
    fprintf(logs, "[INF] Figure created!\n");
  } else {
    delete obj;
    fprintf(logs, "[WRN] Can`t create a figure!\n");
  }
}

void remCom(std::list<Fig *> *lst, char *comm) {
  for (std::list<Fig *>::iterator it = lst->begin(); it != lst->end();) {
    Fig *ptr = *it;
    if (checkCondition(ptr, comm)) {
      delete ptr;
      it = lst->erase(it);
    } else {
      it++;
    }
  }
}

void printCom(std::list<Fig *> *lst, FILE *ofile) {
  if (lst->empty())
    return;
  fprintf(ofile, "!--------PRINT--------!\n");

  for (std::list<Fig *>::iterator it = lst->begin(); it != lst->end(); it++) {
    Fig *ptr = *it;
    ptr->print(ofile);
  }
}

int main() {
  FILE *newfile = fopen("input", "r");
  logs = fopen("output", "w");

  std::list<Fig *> lst;

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
      printCom(&lst, stdout);
    } else {
      fprintf(logs, "[WRN] %s is not a command!\n", param);
    }
  }

  fprintf(logs, "[INF] Programm finished!\n");
  deleteList(&lst);
  fclose(newfile);
  fclose(logs);

  return 0;
}
