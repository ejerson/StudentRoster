#include <iostream>
#include <string>
#include "securityStudent.h"
#include "student.h"
#include "degree.h"
using namespace std;

// Overrides student.cpp Print() function
void SecurityStudent::Print() {
	
	cout << "SECURITY" << endl;

	return;
}

Degree SecurityStudent::GetDegreeProgram() {

	cout << "GetDegreeProgram Invoked SECURITY" << endl;
	return degreeProgram;
}