#pragma once
#include <vector>
#include "Student.hpp"

using std::vector;

int binSearch(vector<Student*>s, int b, int l, int t);
bool sortByID(Student* left, Student* right);