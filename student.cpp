#include <iostream>
#include <cstring>
#include "student.h"
using namespace std;

// cpp file for the Student class - includes constructors + destructors
Student::Student() // default constructor
{
  first = new char[100];
  last = new char[100];
  id = 0;
  gpa = 0.0;
}

Student::Student(char* newfirst, char* newlast, int newid, float newgpa) // constructor w initialized variables
{
  first = new char[100];
  strcpy(first, newfirst);
  last = new char[100];
  strcpy(last, newlast);
  
  id = newid;
  gpa = newgpa;
}

Student::~Student() // destructor
{
  delete first;
  delete last;
}

char* Student::getFirst() // returns first name
{
  return first;
}

char* Student::getLast() // returns last name
{
  return last;
}

int Student::getID() // returns ID
{
  return id;
}

float Student::getGPA() // returns GPA
{
  return gpa;
}

void Student::setFirst(char* newfirst) // sets first name
{
  strcpy(first, newfirst);
}

void Student::setLast(char* newlast) // set last name
{
  strcpy(last, newlast);
}

void Student::setID(int newid)
{
  id = newid;
}

void Student::setGPA(float newgpa)
{
  gpa = newgpa;
}


