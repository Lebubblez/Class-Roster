#include <iostream>
using namespace std;

#include "networkStudent.h"

//created a student object for each student in studentData table

NetworkStudent::NetworkStudent(string ID, string fName, string lName, string emAd, int a, int *nDays, Degree deg) : Student(ID, fName, lName, emAd, a, nDays) {
    degree = deg;
}

Degree NetworkStudent::getDegreeProgram() {
    return degree;
}
