#ifndef SECURITY_H
#define SECURITY_H

#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>
using namespace std;

class SecurityStudent : public Student {

	public:
		using Student::Student;
		void Print();
		Degree GetDegreeProgram();
		
	private:
		Degree degreeProgram = SECURITY;
};

#endif

