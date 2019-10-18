#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <iostream>
#include <string>
using namespace std;

class Student {
	public:
		// Default Constructor
		Student();

		// Custom Constructor
		Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourseOne, int daysInCourseTwo, int daysInCourseThree, Degree degreeProgram);

		// Destructor
		~Student();

		// Accessors
		string GetStudentID();
		string GetFirstName();
		string GetLastName();
		string GetEmailAddress();
		int GetAge();
		int* GetDaysInCourses();
	

		// Mutators
		void SetStudentID(string studentID);
		void SetFirstName(string firstName);
		void SetLastName(string lastName);
		void SetEmailAddress(string emailAddress);
		void SetAge(int age);
		void SetDaysInCourses(int daysInCourses[3]);
		void SetDegreeProgram(Degree degreeProgram);

		// Virtual Methods
		virtual void Print();
		virtual Degree GetDegreeProgram();

	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int daysInCourses[3];
		int daysInCourseOne;
		int daysInCourseTwo;
		int daysInCourseThree;
		Degree degreeProgram;
	
};

#endif
