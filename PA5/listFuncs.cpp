// Name: Zhuoying Yi
// USC NetID: zhuoyiny
// CSCI 455 PA5
// Fall 2017


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
	key = theKey;
	value = theValue;
	next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
	key = theKey;
	value = theValue;
	next = n;
}




//*************************************************************************
// put the function definitions for your list functions below


// inserts key and value at the end of list
void insertTarget(ListType &list, string key, int val){
    ListType p = list;    
    if( p == NULL){
        ListType n = new Node(key, val);
        list = n;
        return;
    }    
    while(p -> next != NULL){
        p = p ->next;
    }    
    ListType n = new Node(key,val);
    p->next = n;
}

// lookup a key in the list, returns the address of the value or null
int *lookUpTarget(ListType list, string target){
    if(list == NULL)
        return NULL;    
    while(list != NULL){
        if(list -> key == target){
            return (& (list-> value));
        }
        list = list -> next;
    }    
    return NULL;
}

// remove an Node from the list
bool removeTarget(ListType &list, string target){
    if(list == NULL){
        return false;
    }
    else{
        while(list != NULL){
            ListType p = list;    
            if(p->key == target){
                list = list -> next;
                delete p;
                return true;
            }
            else if(p->next != NULL && p->next->key != target){
                ListType q = p->next;
                p->next = q->next;
                delete q;
                return true;
            }
            p = p->next;
        }
        return false;
    }

}
    
// prints out all the keys and values in the list
void printList(ListType list){
    if(list == NULL){
        return;
    }    
    ListType p = list;
    while(p != NULL){
        cout << p->key << " " << p->value << endl;
        p = p -> next;
    }
}

// get the size of the list
int listSize(ListType list){
    int count = 0;
    if(list == NULL){
        return count;
    }    
    ListType p = list;
    while(p != NULL){
        count ++;
        p = p -> next;
    }
    return count;
}

