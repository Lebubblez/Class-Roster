#include <iostream>
using namespace std;

#include "securityStudent.h"

//created a student object for each student in studentData table

SecurityStudent::SecurityStudent(string ID, string fName, string lName, string emAd, int a, int *nDays, Degree deg) : Student(ID, fName, lName, emAd, a, nDays) {
    degree = deg;
}

Degree SecurityStudent::getDegreeProgram() {
    return degree;
}
