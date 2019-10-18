#include <iostream>
#include <string>
#include "networkStudent.h"

using namespace std;

// Overrides student.cpp Print() function
void NetworkStudent::Print() {

	Student::Print();
	return;
}

Degree NetworkStudent::GetDegreeProgram() {
	return degreeProgram;
}