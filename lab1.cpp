#include <cstdio>
#include <string>

#include <list>

#include "figure.cpp"

FILE *logs;

bool checkCondition(Fig *fig, char *comm) {
  if (fig == nullptr)
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

  if (pars[par](fig, oper, inp)) {
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

  if ((obj != nullptr) && (obj->setFig(param) == true)) {
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

  lst.clear();
  fclose(newfile);
  fclose(logs);

  return 0;
}
