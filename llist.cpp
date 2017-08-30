/****************************************************************
//
// NAME: Zachary Heth
//
// HOMEWORK: Project2
//
// CLASS: 212
//
// INSTRUCTOR: Ravi Narayan
//
// DATE: November 25 2016
//
// FILE: llist.cpp
//
// DESCRIPTION: Contains the record and llist methods
//
//*************************************************************/

#include "llist.h"
#include <iostream>
#include <fstream>
using namespace std;

void charArrayCopy(char[]);
void callReadFile();
void callWriteFile();

/**********************************************************
//
// Function Name: llist (Constructor)
//
// Description: Creates a new llist object
//
// Parameters: N/A
//
// Return Value: llist object 
//
/*********************************************************/

llist::llist()
{
    #ifdef DEBUGMODE
        cout <<"*******************\n";
        cout << "Entering llist()\n";
        cout <<"*******************\n";
    #endif
    start = NULL;
    char database[] = "database.txt";
    charArrayCopy(filename,database);
}

/**********************************************************
//
// Function Name: llist (Constructor
//
// Description: Creates a new llist object
//
// Parameters: file(char*): sets filename
//
// Return Value: llist object 
//
/*********************************************************/

llist::llist(char file[])
{
    #ifdef DEBUGMODE
        cout <<"*******************\n";
        cout << "Entering list(char*)\n";
        cout <<"*******************\n";
    #endif
    start = NULL;
    charArrayCopy(filename,file);
    callReadFile();
}

/**********************************************************
//
// Function Name: ~list (Destructor)
//
// Description: Deallocates memory for records stored in llist
//
// Parameters: N/A
//
// Return Value: N/A 
//
/*********************************************************/

llist::~llist()
{
    writefile();
    struct record * curr = start;
    struct record * temp = start;
    while(curr != NULL)
    {
        curr = curr->next;
        delete temp;
        temp = curr;
    }
    
}

/**********************************************************
//
// Function Name: charArrayCopy
//
// Description: Copies contents of one array to another
//
// Parameters: dest(char*): Destination array
//             src(char*): Source array
//
// Return Value: N/A
//
/*********************************************************/

void llist::charArrayCopy(char dest[],char src[])
{
    #ifdef DEBUGMODE
        cout <<"*******************\n";
        cout << "Entering charArrayCopy(char*,char*)\n";
        cout <<"*******************\n";
    #endif
    int i = 0;
    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

/**********************************************************
//
// Function Name: addRecord
//
// Description: creates a record and adds it to the llist
//
// Parameters: accNo(int): Account Number
//             nme(char*): Name
//             addrss(char*): Address
//             yob(int): Year of Birth            
//
// Return Value: int (not used)
//
/*********************************************************/

int llist::addRecord(int accNo, char nme[],char addrss[],int yob)
{
    #ifdef DEBUGMODE
        cout <<"*******************\n";
        cout << "Entering addRecord(int,char*,char*,int)\n";
        cout << "Parameter: " << accNo << ", "<< nme << ", " << addrss << ", " << yob <<'\n';
        cout <<"*******************\n";
    #endif
    struct record * curr;
    struct record * prev;
    struct record * temp;
    int endlist = 1;
    int currYob; 
   
    if(start == NULL)
    {/* CASE: List is empty */
        start = new record();
        start->accountno = accNo;
        charArrayCopy(start->name,nme);
        charArrayCopy(start->address,addrss);
        start->yearofbirth = yob;
    }
    else
    {
        curr = start;
        currYob = curr->yearofbirth;
        while(yob < currYob && endlist)
        {
            if(curr->next != NULL)
            {
                prev = curr;
                curr = curr->next;
                currYob = curr->yearofbirth;
            }
            else
            {
                endlist = 0;
            }
        }/* end of while */ 
        if(endlist == 0)
        {/* CASE: adding to the end of the list */
            curr->next = new record();
            curr = curr->next;
        }
        else if(start == curr)
        {/* CASE: adding to the start of the list */
            start = new record();
            start->next = curr;
            curr = start;
        }
        else
        {/* CASE: adding between two records */
            temp = prev->next;
            prev->next = new record();
            curr = prev->next;
            curr->next = temp;
        }
        curr->accountno = accNo;
        charArrayCopy(curr->name,nme);
        charArrayCopy(curr->address,addrss);
        curr->yearofbirth = yob;
    }
}

/**********************************************************
//
// Function Name: printRecord
//
// Description: prints all records with the given account number
//
// Parameters: accNo(int): Account Number
//
// Return Value: int (not used) 
//
/*********************************************************/

int llist::printRecord(int accNo)
{
    #ifdef DEBUGMODE
        cout <<"*******************\n";
        cout << "Enterin printRecord(int)\n";
        cout << "Parameter: " << accNo << '\n';
        cout <<"*******************\n";
    #endif
    struct record * curr = start;
    while(curr != NULL)
    {
        if(curr->accountno == accNo)
        {
            cout << "--------------------\n";
            cout << "Account Number: " << curr->accountno << "\n";
            cout << "Name: " << curr->name << "\n";
            cout << "Address: " <<curr->address << "\n";
            cout << "Year of Birth: " << curr->yearofbirth << "\n";
        }
        curr = curr->next;
    }
    cout << "--------------------\n";
}

/**********************************************************
//
// Function Name: modifyRecord
//
// Description: changes the address of records with given 
//              account number
//
// Parameters: accNo(int): Account Number
//             addrss(char*): New Address
//
// Return Value: int (not used) 
//
/*********************************************************/

int llist::modifyRecord(int accNo, char addrss[]) 
{
    #ifdef DEBUGMODE
        cout <<"*******************\n";
        cout << "Entering modifyRecord(int,char*)\n";
        cout << "Parameter: " << accNo << ", " << addrss << '\n';
        cout <<"*******************\n"; 
    #endif
    struct record * curr = start;
    while(curr != NULL)
    {
        if(accNo == curr->accountno)
        {
            charArrayCopy(curr->address,addrss); 
        }
        curr = curr->next; 
    }
}

/**********************************************************
//
// Function Name: printAll
//
// Description: prints the contents of every record in the llist
//
// Parameters: N/A
//
// Return Value: N/A 
//
/*********************************************************/

void llist::printAll()
{
    #ifdef DEBUGMODE
        cout <<"*******************\n";
        cout << "Entering printAll()\n";
        cout <<"*******************\n";
    #endif
    struct record * curr = start;
    while(curr != NULL)
    {
        cout << "--------------------\n";
        cout << "Account Number: " << curr->accountno << "\n";
        cout << "Name: " << curr->name << "\n";
        cout << "Address: " <<curr->address << "\n";
        cout << "Year of Birth: " << curr->yearofbirth << "\n";
        curr = curr->next;
    }
    cout << "--------------------\n";
}

/**********************************************************
//
// Function Name: deleteRecord
//
// Description: removes all records with the given account number
//
// Parameters: accNo(int): Account Number
//
// Return Value: int (not used) 
//
/*********************************************************/

int llist::deleteRecord(int accNo)
{
    #ifdef DEBUGMODE
        cout <<"*******************\n";
        cout << "Entering deleteRecord(int)\n";
        cout << "Parameter: " << accNo << '\n'; 
        cout <<"*******************\n";
    #endif
    struct record * curr;
    struct record * prev;
    struct record * temp;
    int currAccNo;
 
    if(start != NULL)
    {
        currAccNo = start->accountno;
        if(accNo == currAccNo)
        {
            if(start->next != NULL)
            {
/*cout << "FIRST ONE IN LIST\n";*/
    	        temp = start->next;
    	        delete start;
                start = temp;
                prev = NULL;
            }
            else 
            {	
/*cout << "ONLY ONE IN LIST\n"; */
                delete start;
                start = NULL;
            }
        }
        curr = start;
        while(curr != NULL)
        {
            currAccNo = curr->accountno;
            if(accNo == currAccNo)
            {
                if(prev != NULL)
                {
                    if(curr->next != NULL)     
                    {
/* cout << "SOMETHING IN MIDDLE\n";*/
                        temp = curr->next;
                        delete curr;
                        prev->next = temp;
                        curr = temp;
                    }
                    else
                    {
/* cout << "END OF LIST\n";*/
                        delete curr;
                        prev->next = NULL;
                        curr = NULL; 
                    }
                }
                else
                {  
                    if(curr->next != NULL)
                    {
/*cout << "AT THE START OF LIST,NEXT NOT NULL\n";*/
                        temp = curr->next;
                        delete curr;
                        curr = temp;
                        start = curr;
                    }
                    else
                    {
/* cout << "LAST ONE IN LIST\n"; */
                        delete curr;
                        start = NULL;
                        curr = NULL;
                    }
                }
            }
            else
            {
/*cout << "MOVE UP\n";*/
                prev = curr;
                curr = curr->next;
            }
        }
    }
}

/**********************************************************
//
// Function Name: reverse
//
// Description:  calls the recursive reverse method
//
// Parameters: N/A
//
// Return Value: N/A 
//
/*********************************************************/

void llist::reverse()
{
    #ifdef DEBUGMODE
        cout <<"*******************\n";
        cout << "Entering reverse()\n";
        cout <<"*******************\n";
    #endif
    reverse(start);    
}

/**********************************************************
//
// Function Name: reverse
//
// Description: reverses the order of the records in the list 
//
// Parameters: curr(record*):Current record being reversed 
//
// Return Value: rec(record*): the current record being reversed
//
/*********************************************************/

record * llist::reverse(record * curr)
{
    #ifdef DEBUGMODE
        cout <<"*******************\n";
        cout << "Entering Recursive reverse(record*)\n";
        cout << "Parameter: Record with Year of Birth - " << curr->yearofbirth << '\n';
        cout <<"*******************\n"; 
    #endif
    record * rec;
    if(curr == NULL)
    {
        rec = NULL;
    }
    else if(curr->next == NULL)
    {
        start = curr;
        rec = curr;
    }
    else
    {
        rec = curr;
        curr = reverse(curr->next);
        rec->next = NULL;
        curr->next = rec;
    }
    return rec;
}

/**********************************************************
//
// Function Name: readfile
//
// Description: reads the contents of filename and creates records
//
// Parameters: N/A
//
// Return Value: int (not used) 
//
/*********************************************************/

int llist::readfile()
{
    #ifdef DEBUGMODE
        cout <<"*******************\n";
        cout << "Entering readfile()\n";
        cout <<"*******************\n";
    #endif
    fstream in;
    char input;
    char accNo[20];
    char name[25];
    char address[80];
    char yob[20]; 
    int charCount = 0;
    bool loop = false;
    struct record * curr;

    curr = start;
    in.open(filename);
    if(in.is_open())
    {
        loop = true;
    } 
    while(loop && !in.eof())
    {
        in.getline(accNo,20);
        in.getline(name,25);
        while(input != '!' && charCount < 80)
        {
            in.get(input);
            if(input != '!')
            {
                address[charCount] = input; 
                charCount++;
            }
        }
        in.get(input);
        address[charCount] = '\0';
        in.getline(yob,20);
        if(!in.eof())
        {
            addRecord(atoi(accNo),name,address,atoi(yob)); 
        }
        address[0] = '\0';
        charCount = 0;
    } /* end of while(loop) */
    if(loop)
    {
        in.close();
    }
}
void llist::callReadFile()
{
    readfile();
} 

/**********************************************************
//
// Function Name: writefile
//
// Description: puts the contents of every record into filename
//
// Parameters: N/A
//
// Return Value: int (not used)
//
/*********************************************************/

int llist::writefile()
{
    #ifdef DEBUGMODE
        cout <<"*******************\n"; 
        cout << "Entering writefile()\n";
        cout <<"*******************\n";
    #endif
    fstream out;
    struct record * curr;
    bool loop = false;
    
    curr = start;
    out.open(filename);
    if(out.is_open())
    {
        loop = true;
    }
    while(curr != NULL && loop)
    {
        out << curr->accountno << "\n";
        out << curr->name << "\n";
        out << curr->address << "!\n";
        out << curr->yearofbirth << "\n";
        curr = curr->next;
    }
    if(loop)
    {
         out.close();
    }
}

void llist::callWriteFile()
{
    writefile();
}

/**********************************************************
//
// Function Name: operator<<
//
// Description: overloads << to printAll contents of a llist 
//
// Parameters: out(ostream&): ostream object used to  print
//             list(llist&): llist object being printed
//
// Return Value: out(ostream&):ostream object used to print 
//
/*********************************************************/

ostream & operator<<(ostream & out, llist & list)
{
    #ifdef DEBUGMODE
        cout <<"*******************\n";
        cout << "Entering operator<<\n";
        cout <<"*******************\n";
    #endif
    struct record * curr = list.start;
    while(curr != NULL)
    {
        out << "--------------------\n";
        out << "Account Number: " << curr->accountno << "\n";
        out << "Name: " << curr->name << "\n";
        out << "Address: " <<curr->address << "\n";
        out << "Year of Birth: " << curr->yearofbirth << "\n";
        curr = curr->next;
    }
    out << "--------------------\n";
    return out;
} 
