/* 
 * File:   softwareStudent.h
 * Author: ledaerlandson
 *
 * Created on January 29, 2019, 9:34 AM
 */

#ifndef SOFTWARESTUDENT_H
#define	SOFTWARESTUDENT_H
#include <iostream>
using namespace std;

#include "student.h"

class SoftwareStudent : public Student {
public:
    //Include for student data table as a object for student 
    SoftwareStudent(string, string, string, string, int, int*, Degree);

    //overrides from Student
    Degree getDegreeProgram() override;

    //private data member to hold enumerated type of degree
private:
    Degree degree;
};


#endif	/* SOFTWARESTUDENT_H */

