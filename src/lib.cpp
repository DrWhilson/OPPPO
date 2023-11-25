#include "./lib.h"

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

  std::vector<std::string> keys = {"name", "capacity"};

  std::map<std::string, std::function<bool(Fig *, std::string, std::string)>>
      pars = {{keys[0],
               [](Fig *f, std::string oper, std::string inp) {
                 if (oper == "=") {
                   return f->name == inp;
                 } else
                   return false;
               }},
              {keys[1], [](Fig *f, std::string oper, std::string inp) {
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
  if (std::string(comm) == "Sphere") {
    obj = new Sphere();
  } else if (std::string(comm) == "Parallelepiped") {
    obj = new Parallelepiped();
  } else if (std::string(comm) == "Cylinder") {
    obj = new Cylinder();
  } else {
    obj = nullptr;
  }

  if ((obj != nullptr) && (obj->setFig(param))) {
    lst->push_back(obj);
  } else {
    delete obj;
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
