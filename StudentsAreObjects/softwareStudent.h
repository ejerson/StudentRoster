#ifndef SOFTWARE_H
#define SOFTWARE_H

#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>
using namespace std;

class SoftwareStudent : public Student {

public:
	using Student::Student;
	void Print();
	Degree GetDegreeProgram();

private:
	Degree degreeProgram = SOFTWARE;
};

#endif
