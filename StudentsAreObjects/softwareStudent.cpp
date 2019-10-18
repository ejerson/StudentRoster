#include <iostream>
#include <string>
#include "securityStudent.h"
#include "student.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "degree.h"
using namespace std;

// Overrides student.cpp Print() function
void SoftwareStudent::Print() {


	if (degreeProgram == Degree::SOFTWARE) {
		cout << "SOFTWARE" << endl;

	}

	return;
}

Degree SoftwareStudent::GetDegreeProgram() {

	cout << "GetDegreeProgram Invoked SOFTWARE" << endl;
	return degreeProgram;
}