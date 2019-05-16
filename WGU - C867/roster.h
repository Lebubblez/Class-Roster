/* 
 * File:   roster.h
 * Author: ledaerlandson
 *
 * Created on January 29, 2019, 9:32 AM
 */

#ifndef ROSTER_H
#define	ROSTER_H
#include <iostream>
#include <string>
#include <array>

using namespace std;

#include "student.h"

class Roster {
public:
    //constructor
    Roster();

    //destructor
    ~Roster();

    //count for adding to class roster through classRosterArray
    int count = 0;

    //Defined functions
    void add(string ID, string fName, string lName, string emAd, int a, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree);

    void remove(string ID);

    void printAll();

    void printDaysInCourse(string ID);

    void printInvalidEmails();

    void printByDegreeProgram(string degree);

private:
    //array of pointers
    //references to actual objects in studentData by pointers
    Student *classRosterArray[5];
};


#endif	/* ROSTER_H */

