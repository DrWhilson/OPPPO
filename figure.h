#ifndef FIGURE_H
#define FIGURE_H

#include <cstring>
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

  Point3D() {}
};

class Fig {
public:
  char name[50];
  float Density;
  virtual void print(FILE *ofile) const = 0;
  virtual int calcCap() const = 0;
  virtual bool setFig(char *comm) = 0;

  Fig() {}
  virtual ~Fig() {}
};

class Sphere : public Fig {
public:
  int Radius;

  void print(FILE *ofile) const override;
  int calcCap() const override;
  bool setFig(char *comm) override;

  Sphere() {}
  ~Sphere() {}
};

class Parallelepiped : public Fig {
public:
  int edgeA, edgeB, edgeC;

  void print(FILE *ofile) const override;
  int calcCap() const override;
  bool setFig(char *comm) override;

  Parallelepiped() {}
  ~Parallelepiped() {}
};

class Cylinder : public Fig {
public:
  Point3D center;
  float Radius, Hight;

  void print(FILE *ofile) const override;
  int calcCap() const override;
  bool setFig(char *comm) override;

  Cylinder() {}
  ~Cylinder() {}
};

#endif // FIGURE_H
