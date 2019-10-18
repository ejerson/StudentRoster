#include <iostream>
#include <string>
#include <sstream>
#include <array>

#include "roster.h"

using namespace std;

int main() {

	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Ejerson,Balabas,ebalaba@wgu.edu,31,0,SOFTWARE" };

	Roster* classRoster = nullptr;
	classRoster = new Roster(3);

	// Initializes classRoster Array

	
	

	
	
	classRoster->add("A1", "John", "Smith", "John@nmsu.edu", 20, 30, 35, 40, NETWORKING);
	classRoster->add("A2", "Second", "Person", "Second@nmsu.edu", 25, 10, 12, 66, SECURITY);

	classRoster->printAll();
	classRoster->printByDegreeProgram(classRoster->classRosterArray[1]->GetDegreeProgram());

	// Calls printDaysInCourses, this prints the average days for three courses
	//newRoster->printDaysInCourse(newRoster->classRosterArray[1]->GetStudentID());

	//cout << sizeof(classRoster->classRosterArray) << endl;

	cout << classRoster->classRosterArray[1]->GetLastName() << endl;


	delete classRoster;

}



// Default constructor
Roster::Roster(int arraySize) {

	classRosterArray = new Student * [arraySize];

	for (int i = 0; i < 3; ++i) {
		this->classRosterArray[i] = nullptr;
	}

	return;
}

// Default Destructor
Roster::~Roster() {
	cout << "Destructor called in Roster." << endl;

	delete[] classRosterArray;
	classRosterArray = NULL;

	return;
}

// sets the instance variables from part D1 and updates the roster.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourseOne, int daysInCourseTwo, int daysInCourseThree, Degree degreeProgram) {
	
	int numOfCourseDays[3] = { daysInCourseOne, daysInCourseTwo, daysInCourseThree };
	
	for (int i = 0; i < 3; i++) {

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
			
			break;
			
			
		}

	}

	return;
}


// removes students from the roster by student ID. If the student ID does not exist, 
// the function prints an error message indicating that the student was not found.
void Roster::remove(string studentID)
{
	

	
	return;
}


// prints a complete tab - separated list of student data 
// using accessor functions with the provided format : 
// 1[tab] First Name : John[tab] Last Name : Smith[tab] Age : 20[tab]daysInCourse : {35, 40, 55} Degree Program : Security.
// The printAll() function should loop through all  the students in 
// classRosterArrayand call the print() function for each student.
void Roster::printAll() {
	
	cout << this->classRosterArray[1]->GetDegreeProgram() << endl;

	return;
}

// that correctly prints a student’s average number of days in the three courses. 
// The student is identified by the studentID parameter.
void Roster::printDaysInCourse(string studentID) {

	int averageNumberOfDays = 0;

	for (int i = 0; i < 3; ++i) {

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

	// check for space and see if @ and . is present.

	cout << "Invalid Emails";
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


