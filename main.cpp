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
void add(Node* newNode, Node* prevNode, Node* &startNode)
{
  Node* currentNode = startNode;
  if (currentNode == NULL) // if the current node is the first node in the list
    {
      startNode = newNode; // the new student gets put into the start node
    }
  else // the current node is not the first node
    {
      if (currentNode->getNext()->getID() > newNode->getID()) // the node list is organized from least to greatest ID
	{
	  /*
	   * let's say that Node A points to Node C, and we are trying to insert
	   * Node B in between. We should save Node C in a new node, then set Node 
	   A's next Node to Node B. Then we set Node B's next node to node C.
	   */
	  Node* nextNode = currentNode->getNext(); // save Node C here
	  currentNode->setNext(new Node(newstudent)); // Node A now points to B
	  currentNode = currentNode->getNext(); // move to Node B
	  currentNode->setNext(nextNode); // set Node C as the node after B 
	}
      add(newNode, current // START HEREEEEE
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
