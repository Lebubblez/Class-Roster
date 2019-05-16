/* 
 * File:   roster.cpp
 * Author: ledaerlandson
 *
 * Created on January 29, 2019, 9:26 AM
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

#include "student.h"
#include "degree.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "roster.h"

//size of classRosterArray
const int MAX = 5;

int main() {
    //Instance of roster
    Roster classRoster;

    //instance of degree
    Degree newDegree;

    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Leda,Erlandson,lerland@wgu.edu,23,10,14,20,SOFTWARE"
    };

    //program functionality through function calls
    //functionality to add students to roster
    for (int i = 0; i < MAX; i++) {

        //creates a vector to store each piece of studentData named position
        vector<string> position;

        //read input from string rather than keyboard input
        istringstream ss(studentData[i]);

        string str;

        //character extracted from ss(studentData), and stored in str, ending 
        //after each ',' from studentData. Parses data.
        while (getline(ss, str, ',')) {
            position.push_back(str);
        }
        //checks position of degree for value in studentData
        if (position[8] == "NETWORK") {
            newDegree = Degree::NETWORK;
        }
        if (position[8] == "SECURITY") {
            newDegree = Degree::SECURITY;
        }
        if (position[8] == "SOFTWARE") {
            newDegree = Degree::SOFTWARE;
        }
        //stoi used to take the string value & convert to an integer value
        //adds each student object to class roster array
        classRoster.add(position[0], position[1], position[2], position[3], stoi(position[4]), stoi(position[5]), stoi(position[6]), stoi(position[7]), newDegree);
    }

    //my information
    cout << "Scripting and Programming - Applications c867" << endl;
    cout << "C++" << endl;
    cout << "Student ID: #001008502" << endl;
    cout << "Leda Erlandson" << endl;
    cout << endl;

    //printing outputs
    classRoster.printAll();

    classRoster.printInvalidEmails();

    classRoster.printDaysInCourse("A1");

    classRoster.printByDegreeProgram("SOFTWARE");

    classRoster.remove("A3");

    classRoster.remove("A3");
}

//constructor function

Roster::Roster() {
}

//destructor function

Roster::~Roster() {
}
//initializing functions 
//adding to classRosterArray

void Roster::add(string ID, string fName, string lName, string emAd, int a, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree) {

    //new public array for number of days in the course
    int numDays[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    
    //adding student by degree type
    //increases count within classRosterArray with each new student added
    if (degree == Degree::SOFTWARE) {
        classRosterArray[count++] = new SoftwareStudent(ID, fName, lName, emAd, a, numDays, degree);
    }
    if (degree == Degree::NETWORK) {
        classRosterArray[count++] = new NetworkStudent(ID, fName, lName, emAd, a, numDays, degree);
    }
    if (degree == Degree::SECURITY) {
        classRosterArray[count++] = new SecurityStudent(ID, fName, lName, emAd, a, numDays, degree);
    }
}

//removing a student from roster

void Roster::remove(string ID) {
    bool removeStudent = false;
    for (int i = 0; i < MAX; i++) {

        //checks that position isn't already empty, and studentID is in that location
        //replaces studentID in class roster with a nullprt as removal
        if (classRosterArray[i] != nullptr && ID == classRosterArray[i]->getStudentID()) {
            classRosterArray[i] = nullptr;
            removeStudent = true;
        }
    }
    //condition if position doesn't contain the student entered or is empty
    if (!removeStudent) {
        cout << "Student with ID: " << ID << " could not be removed, because it was not found." << endl;
    }
}

//prints 
void Roster::printAll() {
    cout << "ROSTER OF ALL STUDENTS:" << endl << endl;
    for (int i = 0; i < MAX; i++) {
        classRosterArray[i]->print();
    }
    cout << endl;
}

//prints average days in 3 courses 

void Roster::printDaysInCourse(string ID) {
    for (int i = 0; i < MAX; i++) {

        //checks if classRosterArray at position i, pointing to getStudentID, is equal to studentID
        if (classRosterArray[i]->getStudentID() == ID) {
            int average = 0;
            average = (classRosterArray[i]->getNumDays()[0] + classRosterArray[i]->getNumDays()[1] + classRosterArray[i]->getNumDays()[2]) / 3;
            cout << "Student with student ID: " << ID << " completed 3 courses in an average of " << average << " days." << endl;
        }
    }
    cout << endl;
}

//prints all invalid email addresses

void Roster::printInvalidEmails() {
    cout << "All invalid email addresses found:" << endl << endl;

    for (int i = 0; i < MAX; i++) {

        //storing email address from classRosterArray[i] into new email string 
        string email = classRosterArray[i]->getEmailAddress();
        bool atCharFound = false;
        bool periodCharFound = false;
        bool spaceCharFound = false;

        //checking the new email string for characters
        //checking character (chr) in email
        for (char chr : email) {
            if (chr == '.') {
                periodCharFound = true;
            }
            if (chr == '@') {
                atCharFound = true;
            }
            if (chr == ' ') {
                spaceCharFound = true;
            }
        }
        if (atCharFound == false || periodCharFound == false || spaceCharFound == true) {
            cout << classRosterArray[i]->getEmailAddress() << endl;
        }
    }
    cout << endl;
}

//prints students by degree program

void Roster::printByDegreeProgram(string degree) {

    //create default Degree to test with, since degree is a string
    Degree defaultDeg = Degree::SOFTWARE;
    if (degree == "SECURITY") {
        defaultDeg = Degree::SECURITY;
        cout << "Students with Security degrees: " << endl;
    }
    if (degree == "SOFTWARE") {
        defaultDeg = Degree::SOFTWARE;
        cout << "Students with Software degrees: " << endl;
    }
    if (degree == "NETWORK") {
        defaultDeg = Degree::NETWORK;
        cout << "Students with Network degrees: " << endl;
    }
    cout << endl;

    //prints student by degree by comparing classRoster[i] to defaultDeg
    for (int i = 0; i < MAX; i++) {
        if (classRosterArray[i]->getDegreeProgram() == defaultDeg) {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}

