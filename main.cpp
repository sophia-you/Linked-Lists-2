#include <iostream>
#include <cstring>
#include "student.h"
#include "node.h"

using namespace std;

/*
 * Name | Sophia You
 * Date | 01/03/2024
 * Description | Linked Lists Part 2. A student list function that stores
 * student information in a series of recursive nodes. You can add, delete,
 * and print students. 
 */

// function prototypes
void add(Student* student, Node* prevNode, Node* currentNode,  Node* &startNode);
void print(Node* nextNode, Node* &startNode);
void remove(int id, Node* prevNode, Node* currentNode, Node* &startNode);
void average(float &total, int &count, float mean, Node* currentNode, Node* &startNode);

int main()
{ 
  Node* startNode = NULL; // this is the "head" node                           

  bool editing = true; // while editing is true, the program runs
  while (editing)
    {
      int max = 20;
      char input[max];
      // prompts user for command type
      cout << "LOWER CASE LETTERS ONLY!!!" << endl;
      cout << "Type 'add' to add a student." << endl;
      cout << "Type 'delete' to delete a student." << endl;
      cout << "Type 'print' to print the student roster." << endl;
      cout << "type 'average' to print the school's average GPA." << endl;
      cout << "Type 'quit' to exit editing mode." << endl;
      cin.getline(input, max);
      int length = strlen(input);
      input[length + 1] = '\0';

      if (strcmp(input, "add") == 0)
	{
	  int max = 50;
	  char input[max];
	  char* first = new char[25];
          char* last = new char[50];
	  int id = 0;
	  float gpa = 0.0;

	  // prompt for student information
	  cout << "Enter student information: " << endl;
	  cout << "First name: " << endl;
	  cin.getline(input, max);
	  strcpy(first, input);
	  cout << "Last name: " << endl;
	  cin.getline(input, max);
	  strcpy(last, input);
	  cout << "Student ID: " << endl;
	  cin >> id;
	  cin.ignore(max, '\n');
	  cout << "Student GPA:" << endl;
	  cin >> gpa;
          cin.ignore(max, '\n');

	  Student* student = new Student(first, last, id, gpa);
	  add(student, startNode, startNode, startNode);
	  
	}
      else if (strcmp(input, "delete") == 0)
	{
	  int id = 0;
	  cout << "enter the ID of the student you want to delete." << endl;
	  cin >> id;
	  cin.ignore(25, '\n');
	  remove(id, startNode, startNode, startNode);
	  cout << "Student removed. " << endl;
	  cout << "" << endl;
	}
      else if (strcmp(input, "print") == 0)
	{
	  // prints student roster
	  print(startNode, startNode);
	}
      else if (strcmp(input, "average") == 0)
	{
	  float total = 0.0;
	  int count = 0;
	  float mean = 0.0;
	  average(total, count, mean, startNode, startNode);
	}
      else if (strcmp(input, "quit") == 0)
	{
	  editing = false;
	}
      else
	{
	  cout << "Command not recognized." << endl;
	  cout << "Check your spelling and capitalization and try again." << endl;
	}
    }

  
  return 0;
  
}

/**
 * this function creates a new node and adds it to the current linked list.
 * @param newstudent | this is the student value added to the
 * new node.
 */
void add(Student* student, Node* prevNode, Node* currentNode,  Node* &startNode)
{
  Node* head = startNode;

  // starting the list
  if (startNode == NULL)
    {
      Node* newNode = new Node(student);
      startNode = newNode; // the new student gets put into the start node
    }
  // the new node is smaller than the head node
  else if (student->getID() < startNode->getStudent()->getID())
    {
      Node* newNode = new Node(student);
      newNode->setNext(head);
      startNode = newNode;
    }
  // new node is in between previous and current
  else if (student->getID() > prevNode->getStudent()->getID() &&
	   student->getID() < currentNode->getStudent()->getID())
    {
      Node* newNode = new Node(student);
      newNode->setNext(currentNode);
      prevNode->setNext(newNode);
    }
  // you reach the end of the linked list
  else if (currentNode->getNext() == NULL)
    {
      Node* newNode = new Node(student);
      currentNode->setNext(newNode);
    }
  // new node doesn't go in this location
  else
    {
      add(student, currentNode, currentNode->getNext(), startNode);
    }
}

/**
 * This function, when given a student's id, finds that student and removes
 * them from the linked list.
 */
void remove(int id, Node* prevNode, Node* currentNode, Node* &startNode)
{
  // the student has been found
  if (currentNode != NULL && currentNode->getStudent()->getID() == id)
    {
      if (currentNode == startNode) // if the id is the first in the list
	{
	  startNode = currentNode->getNext(); // set the head to the next node
	}
      else if (currentNode->getNext() != NULL) // the node is in the middle
	{
	  // previous node now connects to the node after currentNode
	  prevNode->setNext(currentNode->getNext());
	}
      else if (currentNode->getNext() == NULL) // end of list
	{
	  prevNode->setNext(NULL);
	}
      
      delete currentNode;
    }
  else
    {
      if (currentNode->getNext() != NULL)
	{
	  remove(id, currentNode, currentNode->getNext(), startNode);
	}
      else // id not found
	{
	  cout << "ID not found." << endl;
	  cout << "" << endl;
	}
    }
}

/**
 * this function prints out the linked list using a recursive technique. 
 * 
 * @param nextNode | this is like the current node (the recursion is
 * called with this node?)
 * @param startNode | we have to pass in the head node with this since global
 * variables aren't allowed.
 */
void print(Node* nextNode, Node* &startNode)
{
  // print out "Node List:" at the first node
  if (nextNode == startNode)
    {
      cout << " " << endl;
      cout << "Student Roster:" << endl;
    }
  if (nextNode != NULL)
    {
      Student* student = nextNode->getStudent();
      cout.precision(3);
      cout.setf(ios::showpoint);
      
      // print out the student info held inside the current node
      cout << student->getFirst() << " " << student->getLast() << ", ID " << student->getID() << ", GPA " << student->getGPA() << endl;

      // call the printNode function (recursively) on the next node in the list
      print(nextNode->getNext(), startNode);
    }
  else if (nextNode == NULL)
    {
      cout << " " << endl;
    }
}

/**
 * This function walks through the linked list recursively and returns an
 * average of all students' GPA.
 */
void average(float &total, int &count, float mean, Node* currentNode, Node* &startNode)
{
  if (startNode != NULL)
    {
      // if there is only one item in the linked list
      if (startNode->getNext() == NULL)
	{
	  mean = currentNode->getStudent()->getGPA();
	  cout.precision(3);
	  cout.setf(ios::showpoint);
	  cout << "" << endl;
	  cout << "Average GPA: " << mean << endl;
	  cout << "" << endl;
	}
      else
	{
	  // add current node's GPA to the total
	  total += currentNode->getStudent()->getGPA();
	  count++;
	  if (currentNode->getNext() != NULL)
	    {
	      average(total, count, mean, currentNode->getNext(), startNode);
	    }
	  else // you have reached the last node in the list
	    {
	      mean = (float)(total/count);
	      cout.precision(3);
	      cout.setf(ios::showpoint);
	      cout << "" << endl;
	      cout << "Average GPA: " << mean << endl;
	      cout << "" << endl;
	    }
	}
    }
}
