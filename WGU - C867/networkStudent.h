/* 
 * File:   networkStudent.h
 * Author: ledaerlandson
 *
 * Created on January 29, 2019, 9:32 AM
 */

#ifndef NETWORKSTUDENT_H
#define	NETWORKSTUDENT_H
#include <iostream>
using namespace std;

#include "student.h"

class NetworkStudent : public Student {
public:
    //Include for student data table as a object for student
    NetworkStudent(string, string, string, string, int, int*, Degree);

    //overrides from Student
    Degree getDegreeProgram() override;

    //private data member to hold enumerated type of degree
private:
    Degree degree;
};


#endif	/* NETWORKSTUDENT_H */

