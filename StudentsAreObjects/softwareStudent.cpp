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

	Student::Print();
	return;
}

Degree SoftwareStudent::GetDegreeProgram() {

	return degreeProgram;

}