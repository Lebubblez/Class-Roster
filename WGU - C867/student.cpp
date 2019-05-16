#include <iostream>
#include <string>
using namespace std;

#include "student.h"
#include "degree.h"

//base class student with all variables
//constructor with all input paramaters

Student::Student(string ID, string fName, string lName, string emAd, int a, int *nDays) {

    setStudentID(ID);
    setFirstName(fName);
    setLastName(lName);
    setEmailAddress(emAd);
    setAge(a);
    numDays[0] = nDays[0];
    numDays[1] = nDays[1];
    numDays[2] = nDays[2];
}

//destructor

Student::~Student() {
}

//Mutator (setter) definitions

void Student::setStudentID(string ID) {
    studentID = ID;
    return;
}

void Student::setFirstName(string fName) {
    firstName = fName;
    return;
}

void Student::setLastName(string lName) {
    lastName = lName;
    return;
}

void Student::setEmailAddress(string emAd) {
    emailAddress = emAd;
}

void Student::setAge(int a) {
    age = a;
}

void Student::setNumDays(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    numDays[0] = daysInCourse1;
    numDays[1] = daysInCourse2;
    numDays[2] = daysInCourse3;
}

void Student::setDegreeProgram(string degree) {
    degree = degree;
}

//Accessor (getter) definition initializing

string Student::getStudentID() {
    return studentID;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getEmailAddress() {
    return emailAddress;
}

int Student::getAge() {
    return age;
}

int *Student::getNumDays() //pointer for access
{
    return numDays;
}

Degree Student::getDegreeProgram() {
    return Degree::SOFTWARE;
}

void Student::print() {
    cout << getStudentID() << "\t"
            << "First Name: " << getFirstName() << "\t"
            << "Last Name: " << getLastName() << "\t"
            << "Age: " << getAge() << "\t" << "\t"
            << " Days In Course: {";
    cout << getNumDays()[0] << ", " << getNumDays()[1] << ", " << getNumDays()[2] << "}" << "\t";
    cout << " Degree Program: ";
    switch (getDegreeProgram()) {
        case 0: cout << "Security";
            break;
        case 1: cout << "Network";
            break;
        case 2: cout << "Software";
            break;
    }
    cout << "\n";
}
