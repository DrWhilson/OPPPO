#include "figure.h"
#include <list>
#include <map>
#include <stdio.h>
#include <string>
#include <vector>

void deleteList(std::list<Fig *> *lst);

bool isKeyContain(std::vector<std::string> keys, std::string checkstr);

bool checkCondition(Fig *fig, char *comm);

void addCom(std::list<Fig *> *lst, char *comm, char *param);

void remCom(std::list<Fig *> *lst, char *comm);

void printCom(std::list<Fig *> *lst, FILE *ofile);
