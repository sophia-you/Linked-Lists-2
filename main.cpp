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

int main()
{
  // test if the node works
  char* bobbieFirst = new char[20];
  char* bobbieLast = new char[20];
  strcpy(bobbieFirst, "bobbie");
  strcpy(bobbieLast, "brown");
  Student* bobbie = new Student(bobbieFirst, bobbieLast, 99, 4.0);

  char* billFirst = new char[20];
  char* billLast = new char[20];
  strcpy(billFirst, "bill");
  strcpy(billLast, "brown");
  Student* bill = new Student(billFirst, billLast, 29, 4.0);

  char* bretFirst = new char[20];
  char* bretLast = new char[20];
  strcpy(bretFirst, "bret");
  strcpy(bretLast, "brown");
  Student* bret = new Student(bretFirst, bretLast, 39, 4.0);

  char* brianaFirst = new char[20];
  char* brianaLast = new char[20];
  strcpy(brianaFirst, "briana");
  strcpy(brianaLast, "brown");
  Student* briana = new Student(brianaFirst, brianaLast, 1039, 4.0);

  Node* startNode = NULL; // this is the "head" node                                   
  add(bobbie, startNode, startNode, startNode);
  add(bill, startNode, startNode, startNode);
  add(bret, startNode, startNode, startNode);
  add(briana, startNode, startNode, startNode);
  print(startNode, startNode);
  remove(bret->getID(), startNode, startNode, startNode);
  print(startNode, startNode);

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
      cout << "Type 'quit' to exit editing mode." << endl;
      cin.getline(input, max);
      int length = strlen(input);
      input[length + 1] = '\0';

      if (strcmp(input, "add") == 0)
	{
	  
	}
      else if (strcmp(input, "delete") == 0)
	{
	}
      else if (strcmp(input, "print") == 0)
	{
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
  Node* newNode = new Node(student);
  int newID = newNode->getStudent()->getID();

  // starting the list
  if (startNode == NULL)
    {
      startNode = newNode; // the new student gets put into the start node
    }
  // the new node is smaller than the head node
  else if (newID < startNode->getStudent()->getID())
    {
      newNode->setNext(head);
      startNode = newNode;
    }
  // new node is in between previous and current
  else if (newID > prevNode->getStudent()->getID() && newID < currentNode->getStudent()->getID())
    {
      newNode->setNext(currentNode);
      prevNode->setNext(newNode);
    }
  // you reach the end of the linked list
  else if (currentNode->getNext() == NULL)
    {
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
      remove(id, currentNode, currentNode->getNext(), startNode);
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
