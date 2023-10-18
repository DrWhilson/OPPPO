#include "figure.h"

using namespace std;

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

void Sphere::print(FILE *ofile) const {
  std::fprintf(ofile, "!--Sphere--!\nName %s\nDensity %f\nRadius %d\n", name,
               Density, Radius);
}

int Sphere::calcCap() const { return ((4.0 / 3.0) * Pi * Radius * Radius); }

bool Sphere::setFig(char *comm) {
  char check[50];
  if (sscanf(comm, "%*s %*s %*s%150[^\n\r]", check) == 1)
    return false;

  if ((sscanf(comm, "%s %f %d", name, &Density, &Radius) == 3) &&
      checkName(name) && isPositive(Density) && isPositive(Radius)) {
    return true;
  } else {
    return false;
  }
}

void Parallelepiped::print(FILE *ofile) const {
  std::fprintf(ofile,
               "!--Parallelepiped--!\nName %s\nDensity %f\nRibs %d %d %d\n",
               name, Density, edgeA, edgeB, edgeC);
}

int Parallelepiped::calcCap() const { return edgeA * edgeB * edgeC; }

bool Parallelepiped::setFig(char *comm) {
  char check[50];
  if (sscanf(comm, "%*s %*s %*s %*s %*s%150[^\n\r]", check) == 1)
    return false;

  if ((sscanf(comm, "%s %f %d %d %d", name, &Density, &edgeA, &edgeB, &edgeC) ==
       5) &&
      checkName(name) && isPositive(Density) && isPositive(edgeA) &&
      isPositive(edgeB) && isPositive(edgeC)) {
    return true;
  } else {
    return false;
  }
}

void Cylinder::print(FILE *ofile) const {
  std::fprintf(ofile,
               "!--Cylinder--!\nName %s\nDensity %f\nCoordinates %d %d "
               "%d\nRadius %f\nHeight %f\n",
               name, Density, center.x, center.y, center.z, Radius, Hight);
}

int Cylinder::calcCap() const { return Pi * Radius * Radius * Hight; }

bool Cylinder::setFig(char *comm) {
  char check[50];
  if (sscanf(comm, "%*s %*s %*s %*s %*s %*s %*s%150[^\n\r]", check) == 1)
    return false;

  if ((sscanf(comm, "%s %f %d %d %d %f %f", name, &Density, &center.x,
              &center.y, &center.z, &Radius, &Hight) == 7) &&
      checkName(name) && isPositive(Density) && isPositive(Radius) &&
      isPositive(Hight)) {
    return true;
  } else {
    return false;
  }
}
