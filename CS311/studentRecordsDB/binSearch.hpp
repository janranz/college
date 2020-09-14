#pragma once
#include <vector>
#include <stdio.h>
#include <iomanip>
#include "Student.hpp"

using std::vector;
using std::fixed;
using std::setprecision;

int binSearch(vector<Student*>s, int b, int l, int t);
int binRemove(vector<Student*>&s, int b, int l, int t);
bool sortByID(Student* left, Student* right);