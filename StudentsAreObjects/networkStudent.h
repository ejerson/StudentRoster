#ifndef NETWORK_H
#define NETWORK_H

#include "student.h"
#include <iostream>
#include <string>
using namespace std;

class NetworkStudent : public Student {

public:
	using Student::Student;
	void Print();
	virtual Degree GetDegreeProgram();

private:
	Degree degreeProgram = NETWORKING;
};

#endif
