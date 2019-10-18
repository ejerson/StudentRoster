#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include "degree.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include <iostream>
#include <string>
using namespace std;

class Roster {

public:
	// Default Constructor
	Roster(int arraySize);
	// Destructor
	~Roster();

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourseOne, int daysInCourseTwo, int daysInCourseThree, Degree degreeProgram);
	void remove(string studentID);
	void printAll();
	void printDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);

	Student** classRosterArray;
	
};

#endif