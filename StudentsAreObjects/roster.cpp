#include <iostream>
#include <string>
#include <sstream>
#include <array>

#include "roster.h"

using namespace std;

int main() {

	// Contains an array of student data, needs to be transformed into objects
	const string studentData[5] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Ejerson,Balabas,ebalaba@wgu.edu,31,0,SOFTWARE" };

	const int arraySize = sizeof(studentData) / sizeof(studentData[0]);

	Roster classRoster(arraySize);
	classRoster.SetArraySize(arraySize);

	// Populates the classRosterArray using the studentData array
	for (int i = 0; i < arraySize; ++i) {






	}
	



	classRoster.add("A1", "John", "Smith", "John@nmsu.edu", 20, 30, 35, 40, NETWORKING);
	

	classRoster.printAll();
	classRoster.printInvalidEmails();

}



// Default constructor
Roster::Roster(int arraySize) {

	classRosterArray = new Student * [arraySize];

	// Initializes classRoster Array
	for (int i = 0; i < arraySize; ++i) {
		this->classRosterArray[i] = nullptr;
	}

	return;
}

// Default Destructor
Roster::~Roster() {

	delete[] classRosterArray;
	classRosterArray = NULL;

	return;
}

// sets the instance variables from part D1 and updates the roster.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourseOne, int daysInCourseTwo, int daysInCourseThree, Degree degreeProgram) {
	
	int numOfCourseDays[3] = { daysInCourseOne, daysInCourseTwo, daysInCourseThree };
	
	for (int i = 0; i < this->GetArraySize(); i++) {

		if (classRosterArray[i] == nullptr) {

			switch (degreeProgram) {

				case SECURITY:
					classRosterArray[i] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourseOne, daysInCourseTwo, daysInCourseThree, degreeProgram);
					break;

				case NETWORKING:
					classRosterArray[i] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourseOne, daysInCourseTwo, daysInCourseThree, degreeProgram);
					break;

				case SOFTWARE:
					classRosterArray[i] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourseOne, daysInCourseTwo, daysInCourseThree, degreeProgram);
					break;

				default:
					classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseOne, daysInCourseTwo, daysInCourseThree, degreeProgram);
					break;
				}
			
			// stops the for loop when all students have been added
			break;
			
		}

	}

	return;
}


// removes students from the roster by student ID. If the student ID does not exist, 
// the function prints an error message indicating that the student was not found.
void Roster::remove(string studentID) {

	bool isFound = false;

	for (int i = 0; i < this->GetArraySize(); ++i) {

		if ((classRosterArray[i] != nullptr) && (this->classRosterArray[i]->GetStudentID() == studentID)) {
			this->classRosterArray[i] = nullptr;
			isFound = true;
		}

	}
	
	if (isFound == false) {
		cout << "ERROR: Student does not exist!" << endl;
	}

	return;
}


// prints a complete tab - separated list of student data 
// using accessor functions with the provided format : 
// 1[tab] First Name : John[tab] Last Name : Smith[tab] Age : 20[tab]daysInCourse : {35, 40, 55} Degree Program : Security.
// The printAll() function should loop through all  the students in 
// classRosterArrayand call the print() function for each student.
void Roster::printAll() {

	for (int i = 0; i < this->GetArraySize(); ++i) {

		if (classRosterArray[i] != nullptr) {
			cout << i + 1;
			this->classRosterArray[i]->Print();
		}

	}

	return;
}

// that correctly prints a student’s average number of days in the three courses. 
// The student is identified by the studentID parameter.
void Roster::printDaysInCourse(string studentID) {

	int averageNumberOfDays = 0;

	for (int i = 0; i < this->GetArraySize(); ++i) {

		if (this->classRosterArray[i]->GetStudentID() == studentID) {
			averageNumberOfDays = ((this->classRosterArray[i]->GetDaysInCourses()[0] + this->classRosterArray[i]->GetDaysInCourses()[1] + this->classRosterArray[i]->GetDaysInCourses()[2]) / 3);
		}

	}
	cout << averageNumberOfDays << endl;

	return;
}
// verifies student email addresses 
// and displays all invalid email addresses to the user
// Note: A valid email should include an at sign ('@') and period ('.') 
// and should not include a space (' ').
void Roster::printInvalidEmails() {

	bool isValid = false;
	string emailHolder = "";
	
	// check for space and see if @ and . is present.
	for (int i = 0; i < this->GetArraySize(); ++i) {

		if (classRosterArray[i] != nullptr) {
			emailHolder = classRosterArray[i]->GetEmailAddress();

			// checks to make sure that the characters '@' and '.' exist within the string
			// checks to make sure that the charater ' ' (space), DOES NOT exist within the string
			// if all condition stated above is met, the email address provided is valid
			if ((emailHolder.find('.') < emailHolder.length()) && (emailHolder.find('@') < emailHolder.length()) && (emailHolder.find(' ') > emailHolder.length())) {
				isValid = true;
			}
			else {

				isValid = false;
				
			}

			// prints the invalid email if checker sets isValid to false
			if (isValid == false) {
				cout << emailHolder << endl;
			}
		}

	}

		return;

}


// prints out student information for a degree program specified by an enumerated type
void Roster::printByDegreeProgram(int degreeProgram) {

	switch (degreeProgram) {

		case 0: 
			cout << "SECURITY" << endl;
			break;
		case 1:
			cout << "NETWORKING" << endl;
			break;
		case 2:
			cout << "SOFTWARE" << endl;
			break;
		default:
			cout << "OTHER" << endl;
			break;

	}

	return;
}

void Roster::SetArraySize(const int arraySize) {

	this->arraySize = arraySize;

	return;
}

int Roster::GetArraySize() {
	return arraySize;
}


