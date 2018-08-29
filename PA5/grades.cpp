// Name: Zhuoying Yi
// USC NetID: zhuoyiny
// CSCI 455 PA5
// Fall 2017

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 *
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>


void printCmdSum();
string getCommand();
string getName(string command);
int getScore(string command);
void scoreInsert(const string &name, int score, Table *grades);
void scoreChange(const string &name, int score, Table *grades);
void nameLookUp(const string &name, Table *grades);
void nameRemove(const string &name, Table *grades);
void commandOperations(Table *grades);


int main(int argc, char * argv[]) {

	// gets the hash table size from the command line

	int hashSize = Table::HASH_SIZE;

	Table * grades;  // Table is dynamically allocated below, so we can call
	// different constructors depending on input from the user.

	if (argc > 1) {
		hashSize = atoi(argv[1]);  // atoi converts c-string to int

		if (hashSize < 1) {
			cout << "Command line argument (hashSize) must be a positive number"
			     << endl;
			return 1;
		}

		grades = new Table(hashSize);

	} else { // no command line args given -- use default table size
		grades = new Table();
	}


	grades->hashStats(cout);

	// add more code here
	// Reminder: use -> when calling Table methods, since grades is type Table*
    commandOperations(grades);
        
	return 0;
}

/**
 * Modifies the grades table depending on the command entered by the user
 */
void commandOperations(Table *grades) {
    while(true){
        string command = getCommand();
        string name = getName(command);
        int score = getScore(command);        
        if(cin.fail()){             // when input is fail, output an error message
            cout << "ERROR: invalid command!" << endl;
            printCmdSum();
            continue;
        }        
        if(command == "insert"){         // insert new name score pair
            scoreInsert(name, score, grades);
        }               
        else if(command == "change"){       // change score
            scoreChange(name, score, grades);
        }        
        else if(command == "lookup"){      // lookup a name
            nameLookUp(name, grades);
        }        
        else if(command == "remove"){      // remove a name and corresponding score
            nameRemove(name, grades);        
        }        
        else if(command == "print"){       // prints out all entries in the table
            grades -> printAll();
        }        
        else if(command == "size"){        // prints out the size of the table
            cout << "the number of entries in the table is "<< grades -> numEntries()<<endl;
        }        
        else if(command == "stats"){       // prints out the entries statistics
            grades->hashStats(cout);
        }        
        else if(command == "help"){        // prints out the command line input summary
            printCmdSum();
        }        
        else if(command == "quit"){        // exit
            break;
        }        
        else{
            cout << "ERROR: invalid command!" << endl;  // invalid input, give a reminder
            printCmdSum();
        }        
    }
}

// prints out the command line input summary
void printCmdSum(){
    
    cout << " \n Valid commands are: "<<endl;    
    cout << " \n 1) insert <name> <score>" << endl;
    cout << "    Insert name and score in the grade table." << endl;    
    cout << " \n 2) change <name> <newscore>" << endl;
    cout << "    Change the score for name. Print an appropriate message." << endl;    
    cout << " \n 3) lookup <name>" << endl;
    cout << "    Lookup the name, and print out his or her score." << endl;
    cout << " \n 4) remove <name>" << endl;
    cout << "    Remove this student in the grade table." << endl;
    cout << " \n 5) print" << endl;
    cout << "    Prints out all names and scores in the table." << endl;
    cout << " \n 6) size" << endl;
    cout << "    Prints out the number of entries in the table." << endl;
    cout << " \n 7) stats" << endl;
    cout << "    Prints out statistics about the hash table at this point." << endl;
    cout << " \n 8) help" << endl;
    cout << "    Prints out a brief command summary." << endl;
    cout << " \n 9) quit" << endl;
    cout << "    Exits the program." << endl;
}

// get the entered command
string getCommand() {
    cout << "cmd> ";
	string command = "";
	cin >> command;
	return command;
}

// Get the entered name
string getName(string command) {
    string name= "";
	if (command == "insert" || command == "change" || command == "lookup" || command == "remove") {
		cin >> name;
	}
	return name;
}

// Get the entered score
int getScore(string command) {
    int score = 0;
    if (command == "insert" || command == "change") {
        cin >> score;
    }
    return score;
}

// Insert this name and score in the grade table.
void scoreInsert(const string &name, int score, Table *grades) {            
    if (grades ->insert(name, score)){
        cout << "Score inserted successfully."<<endl;
    }
    else{
        cout << "Score of "<< name << " already exists, is " << *(grades -> lookup(name))<<"."<< endl;
    }
}
            
// Change the score for name.          
void scoreChange(const string &name, int score, Table *grades) {
    int newScore = score;
    int *temp = grades -> lookup(name);
    if(temp == NULL){
        cout << "Name does not exists."<<endl;
    }
    else{
        int oldScore = *temp;
        *temp = newScore;
        cout << "Score of " <<name<<" changed from "<<oldScore<<" to "<<newScore<< endl;
    }
}

// lookup the name, and print out his or her score
void nameLookUp(const string &name, Table *grades) {
    int *temp = grades -> lookup(name);
    if(temp == NULL){
        cout << "Name does not exists."<<endl;
    }
    else{
        cout << "Score of "<<name<<" is "<< *temp<<endl;
    }    
}

// remove this student
void nameRemove(const string &name, Table *grades) {
    int *temp = grades -> lookup(name);
    if(temp == NULL){
        cout << "Name does not exists."<<endl;
    }
    else{
        grades -> remove(name);
        cout << name <<" removed successfully." << endl;
    } 
}

