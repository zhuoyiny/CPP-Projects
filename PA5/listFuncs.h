// Name: Zhuoying Yi
// USC NetID: zhuoyiny
// CSCI 455 PA5
// Fall 2017


//*************************************************************************
// Node class definition
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.


#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

using namespace std;

struct Node {
	string key;
	int value;

	Node *next;

	Node(const string &theKey, int theValue);

	Node(const string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.



// inserts key and value at the end of list
void insertTarget(ListType &list, string key, int val);

// lookup a key in the list, returns the address of the value or null
int *lookUpTarget(ListType list, string target);

// romove the Node from the list
bool removeTarget(ListType &list, string target);

//prints out all the keys and values in the list
void printList(ListType list);

// get the size of the list
int listSize(ListType list);




// keep the following line at the end of the file
#endif
