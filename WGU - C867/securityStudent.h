/* 
 * File:   securityStudent.h
 * Author: ledaerlandson
 *
 * Created on January 29, 2019, 9:33 AM
 */

#ifndef SECURITYSTUDENT_H
#define	SECURITYSTUDENT_H
#include <iostream>
using namespace std;

#include "student.h"

class SecurityStudent : public Student {
public:
    //Include for student data table as a object for student
    SecurityStudent(string, string, string, string, int, int *, Degree);

    //overrides from Student
    Degree getDegreeProgram() override;

    //private data member to hold enumerated type of degree
private:
    Degree degree;
};


#endif	/* SECURITYSTUDENT_H */

