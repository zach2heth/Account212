//***********************************************************
//
// NAME: Zachary Heth
//
// CLASS: 212
//
// INSTRUCTOR: Ravi Narayan
//
// DATE: November 25 2016
//
// FILE: main.c
//
// DESCRIPTION: This file contains the driver for Project2
//
//**********************************************************/

#include <iostream>
#include "llist.h"
using namespace std;
void getaccountno(int*);
void getaddress(char[]);
void getname(char[]);
void getyearofbirth(int*);

/**********************************************************
//
// Function Name: main
//
// Description: The driver for Project2. User interface for 
//              creating, storing, deleting, records.
//
// Parameters: argc(int): Not used
//             argv(char**):Not used
//
// Return Value: 0 on exit
//
/*********************************************************/

int main(int argc, char * argv[])
{
    #ifdef DEBUGMODE
        cout <<"*******************\n";
        cout << "Entering DEBUGMODE\n";
        cout <<"*******************\n";
    #endif
    int printTracker = 0;
    int accNo;
    int yob;
    char addrss[80];
    char nme[25];
    char menuInput;
    char addRec[] = "Add a new record in the database\n";
    char modifyRec[] = "Modify a record in the database using the accountno as the key\n";
    char printInformation[] = "Print information about a record using the accountno as the key\n";
    char printAll[] = "Print all information in the database\n";
    char deleteRec[] = "Delete an existing record from the database using the accountno as a key\n";
    char reverseList[] = "Reverse the order of the records\n";
    char reverseWarning[] = "Whoa there friend!\nReverse the list back to normal before trying to add a record\n";
    char quit[] ="Quit the program\n";
    char database[] = "database.txt";
    bool loop = true;
    bool reversed = false; 
    llist * List = new llist(database);
    while(loop)
    {
    
        if(printTracker % 2 == 0)
        {
            cout << "--------------------\n";
            cout << "|A: " << addRec;
            cout << "|B: " << modifyRec;
            cout << "|C: " << printInformation;
            cout << "|D: " << printAll;
            cout << "|E: " << deleteRec;
            cout << "|F: " << reverseList;
            cout << "|G: " << quit;
            cout << "--------------------\n";
            cout << "Input a letter option\n>";
            printTracker++;
        }
        cin.get(menuInput);
        if(menuInput == 'A')
        {
            if(!reversed)
            {
                getaccountno(&accNo);
                getname(nme);
                getaddress(addrss);
                getyearofbirth(&yob);
                (*List).addRecord(accNo,nme,addrss,yob);
            }
            else
            {
                cout << reverseWarning;
            }
            printTracker++;
        } 
        else if(menuInput == 'B')
        {
            getaccountno(&accNo);
            getaddress(addrss);
            (*List).modifyRecord(accNo,addrss);
            printTracker++;
        } 
        else if(menuInput == 'C')
        {
            getaccountno(&accNo);
            (*List).printRecord(accNo);
            printTracker++;
        } 
        else if(menuInput == 'D')
        {
            cout << *List;
            printTracker++;
        } 
        else if(menuInput == 'E')
        {
            getaccountno(&accNo);
            (*List).deleteRecord(accNo);
            printTracker++;
        }
        else if(menuInput == 'F')
        {
            (*List).reverse();
            if(reversed)  
            {
                reversed = false;
            }
            else
            {
                reversed = true;
            }
            printTracker++;
        } 
        else if(menuInput == 'G')
        {
            cout << "Exiting the Program\n";
            delete List; 
            exit(0);
        }
    }
}
