#include "../src/lib.h"
#include <cstdio>
#include <cstring>
#include <gtest/gtest.h>
#include <list>
#include <string>
#include <vector>

TEST(remComTest, remFromNone) {
  std::list<Fig *> lst;
  char comm[50];
  std::strcpy(comm, "name = None");

  remCom(&lst, comm);

  ASSERT_EQ(0, lst.size());
  deleteList(&lst);
}

TEST(remComTest, remFromOneEl) {
  std::list<Fig *> lst;
  char comm[50];
  char param[50];
  std::strcpy(comm, "Sphere");
  std::strcpy(param, "Name 4.0 4");
  addCom(&lst, comm, param);

  std::strcpy(comm, "name = Name");

  remCom(&lst, comm);

  ASSERT_EQ(0, lst.size());
  deleteList(&lst);
}

TEST(remComTest, remFirst) {
  std::list<Fig *> lst;
  char comm[50];
  char param[50];
  std::strcpy(comm, "Sphere");
  std::strcpy(param, "Name 4.0 4");
  addCom(&lst, comm, param);
  std::strcpy(comm, "Sphere");
  std::strcpy(param, "Names 4.0 4");
  addCom(&lst, comm, param);
  std::strcpy(comm, "Sphere");
  std::strcpy(param, "Namess 4.0 4");
  addCom(&lst, comm, param);

  std::strcpy(comm, "name = Name");

  remCom(&lst, comm);

  ASSERT_EQ(2, lst.size());
  deleteList(&lst);
}

TEST(remComTest, remLast) {
  std::list<Fig *> lst;
  char comm[50];
  char param[50];
  std::strcpy(comm, "Sphere");
  std::strcpy(param, "Name 4.0 4");
  addCom(&lst, comm, param);
  std::strcpy(comm, "Sphere");
  std::strcpy(param, "Names 4.0 4");
  addCom(&lst, comm, param);
  std::strcpy(comm, "Sphere");
  std::strcpy(param, "Namess 4.0 4");
  addCom(&lst, comm, param);

  std::strcpy(comm, "name = Namess");

  remCom(&lst, comm);

  ASSERT_EQ(2, lst.size());
  deleteList(&lst);
}

TEST(remComTest, remMidle) {
  std::list<Fig *> lst;
  char comm[50];
  char param[50];
  std::strcpy(comm, "Sphere");
  std::strcpy(param, "Name 4.0 4");
  addCom(&lst, comm, param);
  std::strcpy(comm, "Sphere");
  std::strcpy(param, "Names 4.0 4");
  addCom(&lst, comm, param);
  std::strcpy(comm, "Sphere");
  std::strcpy(param, "Namess 4.0 4");
  addCom(&lst, comm, param);

  std::strcpy(comm, "name = Names");

  remCom(&lst, comm);

  ASSERT_EQ(2, lst.size());
  deleteList(&lst);
}

TEST(remComTest, remAll) {
  std::list<Fig *> lst;
  char comm[50];
  char param[50];
  std::strcpy(comm, "Sphere");
  std::strcpy(param, "Name 4.0 4");
  addCom(&lst, comm, param);
  std::strcpy(comm, "Sphere");
  std::strcpy(param, "Name 4.0 4");
  addCom(&lst, comm, param);
  std::strcpy(comm, "Sphere");
  std::strcpy(param, "Name 4.0 4");
  addCom(&lst, comm, param);

  std::strcpy(comm, "name = Name");

  remCom(&lst, comm);

  ASSERT_EQ(0, lst.size());
  deleteList(&lst);
}

TEST(addComTest, corInpSph) {
  std::list<Fig *> lst;
  char comm[50];
  char param[50];

  std::strcpy(comm, "Sphere");
  std::strcpy(param, "Name 4.0 5");

  addCom(&lst, comm, param);

  ASSERT_EQ(1, lst.size());
  deleteList(&lst);
}

TEST(addComTest, corInpPar) {
  std::list<Fig *> lst;
  char comm[50];
  char param[50];

  std::strcpy(comm, "Parallelepiped");
  std::strcpy(param, "Name 4.0 5 6 7");

  addCom(&lst, comm, param);

  ASSERT_EQ(1, lst.size());
  deleteList(&lst);
}

TEST(addComTest, corInpCyl) {
  std::list<Fig *> lst;
  char comm[50];
  char param[50];

  std::strcpy(comm, "Cylinder");
  std::strcpy(param, "Name 4.0 0 0 0 5 1");

  addCom(&lst, comm, param);

  ASSERT_EQ(1, lst.size());
  deleteList(&lst);
}

TEST(addComTest, vrInpSph) {
  std::list<Fig *> lst;
  char comm[50];
  char param[50];

  std::strcpy(comm, "Sphere");
  std::strcpy(param, "Name false f");

  addCom(&lst, comm, param);

  ASSERT_EQ(0, lst.size());
  deleteList(&lst);
}

TEST(addComTest, vrInpPar) {
  std::list<Fig *> lst;
  char comm[50];
  char param[50];

  std::strcpy(comm, "Parallelepiped");
  std::strcpy(param, "Name false f f f");

  addCom(&lst, comm, param);

  ASSERT_EQ(0, lst.size());
  deleteList(&lst);
}

TEST(addComTest, vrInpCyl) {
  std::list<Fig *> lst;
  char comm[50];
  char param[50];

  std::strcpy(comm, "Cylinder");
  std::strcpy(param, "Name false f f f f f");

  addCom(&lst, comm, param);

  ASSERT_EQ(0, lst.size());
  deleteList(&lst);
}

TEST(addComTest, manyInpSph) {
  std::list<Fig *> lst;
  char comm[50];
  char param[50];

  std::strcpy(comm, "Sphere");
  std::strcpy(param, "Name 4.0 5 f");

  addCom(&lst, comm, param);

  ASSERT_EQ(0, lst.size());
  deleteList(&lst);
}

TEST(addComTest, manyInpPar) {
  std::list<Fig *> lst;
  char comm[50];
  char param[50];

  std::strcpy(comm, "Parallelepiped");
  std::strcpy(param, "Name 4.0 5 6 7 f");

  addCom(&lst, comm, param);

  ASSERT_EQ(0, lst.size());
  deleteList(&lst);
}

TEST(addComTest, manyInpCyl) {
  std::list<Fig *> lst;
  char comm[50];
  char param[50];

  std::strcpy(comm, "Cylinder");
  std::strcpy(param, "Name 4.0 0 0 0 5 1 f");

  addCom(&lst, comm, param);

  ASSERT_EQ(0, lst.size());
  deleteList(&lst);
}

TEST(keyTest, corKey) {
  std::vector<std::string> keys = {"name", "capacity"};
  std::string key = "name";
  EXPECT_TRUE(isKeyContain(keys, key));
  key = "capacity";
  EXPECT_TRUE(isKeyContain(keys, key));
}

TEST(keyTest, vrKey) {
  std::vector<std::string> keys = {"name", "capacity"};
  std::string key = "nmae";
  EXPECT_FALSE(isKeyContain(keys, key));
}

TEST(checkNameTest, corrName) {
  char name[50];
  std::strcpy(name, "Name");
  EXPECT_TRUE(checkName(name));
}

TEST(checkNameTest, vrName) {
  char name[50];
  std::strcpy(name, "Nma1e");
  EXPECT_FALSE(checkName(name));
  std::strcpy(name, "name");
  EXPECT_FALSE(checkName(name));
}

TEST(deleteListTest, delNoList) {
  std::list<Fig *> lst;
  deleteList(&lst);

  ASSERT_EQ(0, lst.size());
}

TEST(deleteListTest, delList) {
  std::list<Fig *> lst;
  char comm[50];
  char param[50];

  std::strcpy(param, "Sphere");
  std::strcpy(comm, "Name 4.0 5");
  addCom(&lst, param, comm);
  addCom(&lst, param, comm);
  addCom(&lst, param, comm);

  deleteList(&lst);

  ASSERT_EQ(0, lst.size());
}

TEST(setFigTest, corInpSph) {
  Sphere sph;
  char comm[50];
  std::strcpy(comm, "Name 4.0 5");
  sph.setFig(comm);
  ASSERT_EQ("Name", std::string(sph.name));
  ASSERT_EQ(4.0, sph.Density);
  ASSERT_EQ(5, sph.Radius);
}

TEST(setFigTest, corInpPar) {
  char comm[50];
  Parallelepiped par;
  std::strcpy(comm, "Name 4.0 5 4 2");
  par.setFig(comm);
  ASSERT_EQ("Name", std::string(par.name));
  ASSERT_EQ(4.0, par.Density);
  ASSERT_EQ(5, par.edgeA);
  ASSERT_EQ(4, par.edgeB);
  ASSERT_EQ(2, par.edgeC);
}

TEST(setFigTest, corInpCyl) {
  char comm[50];
  Cylinder cyl;
  std::strcpy(comm, "Name 3.0 5 4 2 10 6");
  cyl.setFig(comm);
  ASSERT_EQ("Name", std::string(cyl.name));
  ASSERT_EQ(3.0, cyl.Density);
  ASSERT_EQ(5, cyl.center.x);
  ASSERT_EQ(4, cyl.center.y);
  ASSERT_EQ(2, cyl.center.z);
  ASSERT_EQ(10, cyl.Radius);
  ASSERT_EQ(6, cyl.Hight);
}

TEST(setFigTest, vrInpSph) {
  Sphere sph;
  char comm[50];
  std::strcpy(comm, "Name false 5");
  EXPECT_FALSE(sph.setFig(comm));
}

TEST(setFigTest, vrInpPar) {
  char comm[50];

  Parallelepiped par;
  std::strcpy(comm, "name 4.0 5 4 2");
  EXPECT_FALSE(par.setFig(comm));
}

TEST(setFigTest, vrCyl) {
  char comm[50];

  Cylinder cyl;
  std::strcpy(comm, "Name1 3.0 5 4 2 10 6");
  EXPECT_FALSE(cyl.setFig(comm));
}

TEST(setFigTest, manyInpSph) {
  Sphere sph;
  char comm[50];
  std::strcpy(comm, "Name 4.0 5 X_X");
  EXPECT_FALSE(sph.setFig(comm));
}

TEST(setFigTest, manyInpPar) {
  char comm[50];
  Parallelepiped par;
  std::strcpy(comm, "Name 4.0 5 4 2 X_X");
  EXPECT_FALSE(par.setFig(comm));
}

TEST(setFigTest, manyInpCyl) {
  char comm[50];
  Cylinder cyl;
  std::strcpy(comm, "Name 3.0 5 4 2 10 6 X_X");
  EXPECT_FALSE(cyl.setFig(comm));
}

TEST(checkConditionTest, corInp) {
  Sphere sph;

  char param[50];
  char comm[50];

  std::strcpy(param, "Name 4.0 5");
  std::strcpy(comm, "name = Name");
  sph.setFig(param);

  EXPECT_TRUE(checkCondition(&sph, comm));

  std::strcpy(comm, "name = cyl");
  EXPECT_FALSE(checkCondition(&sph, comm));

  std::strcpy(comm, "capacity > 0");
  EXPECT_TRUE(checkCondition(&sph, comm));
}

TEST(checkConditionTest, vrInp) {
  Sphere sph;

  char param[50];
  char comm[50];

  std::strcpy(param, "Name 4.0 5");
  std::strcpy(comm, "a314 = Name");
  sph.setFig(param);

  EXPECT_FALSE(checkCondition(&sph, comm));
}

TEST(checkConditionTest, manyInp) {
  Sphere sph;

  char param[50];
  char comm[50];

  std::strcpy(param, "Name 4.0 5");
  std::strcpy(comm, "name = Name 6");
  sph.setFig(param);

  EXPECT_FALSE(checkCondition(&sph, comm));

  std::strcpy(comm, "capacity > 0 6");
  EXPECT_FALSE(checkCondition(&sph, comm));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
