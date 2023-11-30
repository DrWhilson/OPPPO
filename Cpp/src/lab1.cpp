#include "./lib.h"

using namespace std;

int main() {
  FILE *newfile = fopen("input", "r");

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
    }
  }

  deleteList(&lst);
  fclose(newfile);

  return 0;
}
