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
void add(Node* newNode, Node* prevNode, Node* &startNode);
void print(Node* nextNode, Node* &startNode);

int main()
{
  // test if the node works
  char* bobbieFirst = new char[20];
  char* bobbieLast = new char[20];
  strcpy(bobbieFirst, "bobbie");
  strcpy(bobbieLast, "brown");
  Student* bobbie = new Student(bobbieFirst, bobbieLast, 99, 4.0);

  char* henFirst = new char[20];
  char* henLast = new char[20];
  strcpy(henFirst, "henriette");
  strcpy(henLast, "eustacus");
  Student* henriette = new Student(henFirst, henLast, 12, 3.0);
  
  Node* startNode = NULL; // this is the "head" node
  add(bobbie, startNode, startNode);
  print(startNode, startNode);
  add(henriette, startNode);
  print(startNode, startNode, startNode);
  
  return 0;
  
}

/**
 * this function creates a new node and adds it to the current linked list.
 * @param newstudent | this is the student value added to the
 * new node.
 */
void add(Node* newNode, Node* prevNode, Node* currentNode, Node* &startNode)
{
  Node* head = startNode;
  int newID = newNode()->getstudent()->getID();
  int prevID = prevNode->getStudent()->getID();
  int nextID = prevNode->getNext()->getStudent()->getID();
  if (head == NULL) // if the current node is the first node in the list
    {
      startNode = newNode; // the new student gets put into the start node
    }
  else if (newID < startNode->getStudent()->getID()) // the new node id is smaller than the head node
        {
           newNode->setNext(head); // set new node's next pointer to the current head
           startNode = newNode; // set the starting node to new node
        }
  else
    {
      if (prevID <= newID) // if the new node has a greater id than the previous node
	{
	  if (prevNode->getNext() == NULL) // end of list
	    {
	      prevNode->setNext(newNode); // add node to end of list
	    }
	  else if (nextID > newID) // the new node goes in between the previous node and the next node
	    {
	      // insert in between prevNode and prevNode -> getNext()
	      newNode->setNext(prevNode->getNext()); // the new node points to the next node
	      prevNode->setNext(newNode); // the previous node points to the new node
	    }
	  else // the new node's id is larger than both the previous node and the next node
	    {
	      // keep going down the linked list, using recursion
	      add(newNode, prevNode->getNext(), startNode);
	    }
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
      cout << "Node List:" << endl;
    }
  if (nextNode != NULL)
    {
      // print out the student info held inside the current node
      cout << nextNode->getStudent()->getFirst() << endl;

      // call the printNode function (recursively) on the next node in the list
      printNode(nextNode->getNext(), startNode);
    }
}
