#include <iostream>
#include <string>
#include "securityStudent.h"
#include "student.h"
#include "degree.h"
using namespace std;

// Overrides student.cpp Print() function
void SecurityStudent::Print() {
	Student::Print();

	return;
}

Degree SecurityStudent::GetDegreeProgram() {

	return degreeProgram;
}