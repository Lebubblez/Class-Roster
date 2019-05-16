#include <iostream>
using namespace std;

#include "softwareStudent.h"

//created a student object for each student in studentData table

SoftwareStudent::SoftwareStudent(string ID, string fName, string lName, string emAd, int a, int *nDays, Degree deg) : Student(ID, fName, lName, emAd, a, nDays) {
    degree = deg;
}

Degree SoftwareStudent::getDegreeProgram() {
    return degree;
}
