#include <iostream>
#include <string>
#include "student.h"

using namespace std;

// Default constructor. Set protected member variables to the empty string or 0
Student::Student() {
	studentID = "";
	lastName = "";
	firstName = "";
	emailAddress = "";
	age = 0;

	return;
}

// Custom constructor. Set protected member variables to actual values
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourseOne, int daysInCourseTwo, int daysInCourseThree, Degree degreeProgram) {

	SetDegreeProgram(degreeProgram);

	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourseOne = daysInCourseOne;
	this->daysInCourseTwo = daysInCourseTwo;
	this->daysInCourseThree = daysInCourseThree;
	this->daysInCourses[0] = daysInCourseOne;
	this->daysInCourses[1] = daysInCourseTwo;
	this->daysInCourses[2] = daysInCourseThree;

	return;
}

// Destructor
Student::~Student() {
	cout << "Destructor called in Student." << endl;
	// FIXME: Manage Memory here
	// 1. Change all of the declared variables in the student.h to pointers
	// 2. Change the constructor in student.cpp to instantiate a pointer

	return;
}

// Mutator Functions
void Student::SetStudentID(string studentID)
{
	this->studentID = studentID;
}

void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
	return;
}

void Student::SetLastName(string lastName) {
	this->lastName = lastName;
	return;
}

void Student::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
	return;
}

void Student::SetAge(int age) {
	this->age = age;
	return;
}

void Student::SetDaysInCourses(int daysInCourses[3]) {

	daysInCourses[0] = this->daysInCourseOne;
	daysInCourses[1] = this->daysInCourseTwo;
	daysInCourses[2] = this->daysInCourseThree;

}

void Student::SetDegreeProgram(Degree degreeProgram) {
	this->degreeProgram = degreeProgram;
	return;
}

// Virtual functions
void Student::Print() {
	return;
}

Degree Student::GetDegreeProgram() {
	return degreeProgram;
}

// Accessor Functions
string Student::GetStudentID() {
	return studentID;
}

string Student::GetFirstName() {
	return firstName;
}

string Student::GetLastName() {
	return lastName;
}

string Student::GetEmailAddress() {
	return emailAddress;
}

int Student::GetAge() {
	return age;
}

int* Student::GetDaysInCourses() {
	return daysInCourses;
}



