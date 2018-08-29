/*  Name: Zhuoying Yi
 *  USC NetID: zhuoyiny
 *  CS 455 Fall 2017
 *
 *  See ecListFuncs.h for specification of each function.
 */

#include <iostream>

#include <cassert>

#include "ecListFuncs.h"

using namespace std;


int numRuns(ListType list) {
    if(list == NULL){
        return 0;
    }
    int num = 0;
    int listValue = list->data;
    ListType p = list->next;
    while (p != NULL){        
        if(listValue == p->data){   // If there are at least two consecutive same numbers, num increase one
            num++;
            if(p->next!=NULL){
                do {
                    listValue = p->data;
                    p = p->next;
                }
                while(listValue== p->data);
            }            
        }
        listValue = p->data;
        p = p->next;        
    }
    return num;
}



ListType reverseCopy(ListType list) {
    if (list == NULL) {
        return list;
    }
    ListType p = list;
    ListType tmp = NULL;
    while (p != NULL) {
        tmp = new Node(p->data, tmp); // create new node
        p = p->next;
    }
    return tmp;
}



void removeMiddleElmt(ListType &list) {
    if (list == NULL) {   // the list is empty
        return;
    }
    if (list->next == NULL) {  // only one element in the list
        list = NULL;
        return;
    }
    if (list->next->next == NULL) {// only two element in the list
        list = list->next;
        return;
    }
    ListType slowPtr = list;
    ListType fastPtr = list;
    ListType tmp;
    while(fastPtr->next != NULL) {  // more than two element
        if(fastPtr->next->next!= NULL) {            
            fastPtr = fastPtr->next->next;
            tmp = slowPtr;
            slowPtr = slowPtr->next;
        }
        else {
            break;
        }        
    }
    tmp->next= slowPtr->next;
    delete slowPtr;
    return;    
}



void splitOn(ListType &list, int splitVal, ListType &a, ListType &b) {
    if (list == NULL) {   // the list is empty
        return;
    }    
    int listVal = list->data;
    ListType p = list;
    ListType tmp = NULL;
    if(listVal == splitVal){  // whether the first number is equal to split number
        a = NULL;
        b = p->next;
    }
    else if(p->next == NULL){
        a = list;
        b = NULL;
    }
    else{     // compare the numbers from the second number to the end of the list with split number
        while(p->next != NULL && listVal != splitVal){     
            tmp = p;
            p=p->next;
            listVal = p->data;
        }
        if(p->next == NULL&& listVal != splitVal){
            tmp = tmp ->next;
        }      
        tmp->next=NULL;
        a=list;
        b=p->next;
    }
    list=NULL;
}

