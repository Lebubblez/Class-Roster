/* 
 * File:   student.h
 * Author: ledaerlandson
 *
 * Created on January 29, 2019, 9:35 AM
 */

#ifndef STUDENT_H
#define	STUDENT_H
#include <iostream>
#include <string>
using namespace std;

#include "degree.h" //allow to access virtual Degree

//base class Student 

class Student {
public:

    //constructor with all parameters
    Student(string ID, string fName, string lName, string emAdd, int a, int* nDays);

    //Destructor
    ~Student();

    //Accessor (getter) for each instance variable (object)
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int *getNumDays(); //pointer for access

    //virtual allows for invoking derived degree class functions from the 
    //student base class
    virtual Degree getDegreeProgram();
    virtual void print();

    //Mutator (setter) for each instance variable (object)
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setNumDays(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void setDegreeProgram(string degree);


private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int numDays[3];
};


#endif	/* STUDENT_H */

