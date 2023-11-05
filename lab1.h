#include <list>
#include <map>
#include <stdio.h>
#include <string>

#include "figure.h"

void deleteList(std::list<Fig *> *lst);

bool checkCondition(Fig *fig, char *comm);

void addCom(std::list<Fig *> *lst, char *comm, char *param);

void remCom(std::list<Fig *> *lst, char *comm);

void printCom(std::list<Fig *> *lst, FILE *ofile);
