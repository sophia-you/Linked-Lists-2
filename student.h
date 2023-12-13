#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>

using namespace std;

class Student
{
 public:
  // constructors
  Student(); // default constructor
  Student(char*, char*, int, float); // pass in first/last name, ID, and GPA
  ~Student(); // destructor

  // getters
  char* getFirst(); // returns first name
  char* getLast(); // returns last name
  int getID(); // returns student ID
  float getGPA(); // returns student GPA

  // setters
  void setFirst(char*); // set first name
  void setLast(char*); // set last name
  void setID(int); // set student ID
  void setGPA(float); // set student GPA

 private:
  // variables
  char* first;
  char* last;
  int id;
  float gpa;
  
  
};
#endif
