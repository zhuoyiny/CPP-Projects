// Name: Zhuoying Yi
// USC NetID: zhuoyiny
// CSCI 455 PA5
// Fall 2017

// Table.cpp  Table class implementation


/*
 * Modified 11/22/11 by CMB
 *   changed name of constructor formal parameter to match .h file
 */

#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
    hashSize = HASH_SIZE;
	data = new ListType[hashSize];
	initTable();
}

Table::Table(unsigned int hSize) {
    hashSize = hSize;
	data = new ListType[hashSize];
	initTable();
}


// lookup a key in the table, return its address
int * Table::lookup(const string &key) {
    int code = hashCode(key);
    return lookUpTarget(data[code], key);
}

// remove an entry in the table
bool Table::remove(const string &key) {
    int code = hashCode(key);
    return removeTarget(data[code], key);
}

// insert a new entry in the table
bool Table::insert(const string &key, int value) {
    if(lookup(key) != NULL){
        return false;
    }
    else{
        int code = hashCode(key);
        insertTarget(data[code], key, value);
        return true;
    }
}

// get the number of entries in the table
int Table::numEntries() const {
	int num = 0;
	for (int i = 0; i < hashSize; i++) {
		num = num + listSize(data[i]);
	}
	return num;
}

// prints out all the entries in the table
void Table::printAll() const {    
    int nonEmpty = 0;
    for(int i = 0; i < hashSize; i++){
        int size = listSize(data[i]);
        if ( size != 0){
            nonEmpty++;
        }
        printList(data[i]);
    }
    if(nonEmpty == 0){
        cout << "Empty table."<<endl;
    }
}

// print the hash stats of the table
void Table::hashStats(ostream &out) const {
    out << "number of buckets: " << hashSize << endl;
    out << "number of entries: " << numEntries() << endl;
    out << "number of non-empty buckets: "<< numNonEmpty() << endl;
    out << "longest chain: "<< longestChain()<< endl;
}


// add definitions for your private methods here

// initate the table, create an empty list
void Table::initTable(){    
    for(int i = 0; i < hashSize; i++){
        data[i] = NULL;
    }
}

// get the number of the non-empty buckets
int Table::numNonEmpty() const {
    int nonEmpty = 0;
    for(int i = 0; i < hashSize; i ++){
        if ( listSize(data[i]) > 0){
            nonEmpty++;            
        }       
    }
    return nonEmpty;
}

// get the length of the longest chain
int Table::longestChain() const {
    int longest = 0;
    for(int i = 0; i < hashSize; i ++){
        if ( listSize(data[i]) > 0){
            if( listSize(data[i]) > longest){
                longest = listSize(data[i]);
            }
        }       
    }
    return longest;   
}

