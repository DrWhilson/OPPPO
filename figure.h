// #include <fstream>
#include <cstdio>
#include <regex>
#include <stdio.h>
#include <string>

const float Pi = 3.14;

bool isContainNum(char *str);

bool checkName(char *str);

bool isPositive(int num);

bool isPositive(float num);

class Point3D {
public:
  int x, y, z;

  Point3D(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

class Fig {
public:
  char name[50];
  float Density;
  virtual void print(FILE *ofile) const = 0;
  virtual int calcCap() const = 0;
  virtual bool setFig(char *comm) = 0;

  Fig() : name(""), Density(0) {}

  virtual ~Fig() {}
};

class Sphere : public Fig {
public:
  int Radius;
  void print(FILE *ofile) const override;

  int calcCap() const override;

  bool setFig(char *comm) override;

  Sphere() : Fig(), Radius(0) {}
};

class Parallelepiped : public Fig {
public:
  int edgeA, edgeB, edgeC;
  void print(FILE *ofile) const override;

  int calcCap() const override;

  bool setFig(char *comm) override;

  Parallelepiped() : Fig(), edgeA(0), edgeB(0), edgeC(0) {}
};

class Cylinder : public Fig {
public:
  Point3D center;
  float Radius, Hight;
  void print(FILE *ofile) const override;

  int calcCap() const override;
  bool setFig(char *comm) override;

  Cylinder() : Fig(), center(0, 0, 0), Radius(0), Hight(0) {}
};
