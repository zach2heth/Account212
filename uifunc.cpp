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
// FILE: uifunc.cpp
//
// DESCRIPTION: This file contains the user interface functions
//
//**********************************************************/

#include <iostream>
#include "uifunc.h"
using namespace std;

/**********************************************************
//
// Function Name: getname
//
// Description: prompts user for a name  
//
// Parameters: array(char*):Where it will be stored
//
// Return Value: void 
//
/*********************************************************/

void getname(char array[])
{
    #ifdef DEBUGMODE
        cout <<"*******************\n";
        cout << "Entering getname(char*)\n";
        cout <<"*******************\n";
    #endif 
    int charCount = 0;
    char input;
    cout << "Enter a name\n>";
    while(input != '\n')
    {
        cin.get(input);
        if(input != '\n')
        {
            array[charCount] = input;
            charCount++;
        }
        else
        {
            array[charCount] = '\0';
        }
    }
}

//*********************************************************
//
// Function Name: getaddress
//
// Description: prompts user to type in address information
//
// Parameters: array[](char): where address will be stored
//
// Return Values: void
//
//********************************************************\

void getaddress(char array[])
{ 
    #ifdef DEBUGMODE
        cout <<"*******************\n";
        cout << "Entering getaddress(char*)\n";
        cout <<"*******************\n";
    #endif
    char input;
    int charCount = 0;
    cout << "Enter an address. Input '!' and hit enter when finished\n>";
    while(input != '!')
    {
        cin.get(input);
        if(input != '!')
        {
            array[charCount] = input;
            charCount++;
            if(input == '\n')
                cout << ">";
        }
        else
        {
            array[charCount] = '\0';
        }
    }
}

//*********************************************************
//
// Function Name: getaccountno
//
// Description: prompt the user for account number information
//
// Parameters:input(int): where account number will be stored
//
// Return Values: void
//
//********************************************************\

void getaccountno(int * accNo)
{
    #ifdef DEBUGMODE
        cout <<"*******************\n";
        cout << "Entering getaccountno(int*)\n";
        cout <<"*******************\n";
    #endif
    bool loop = true;
    cout << "Enter the account number\n>";
    while(loop)
    {
        cin >> *accNo;
        if(cin.fail() || accNo <= 0) 
        {
            cout << "Enter a positive number\n>";
            cin.clear();
            cin.ignore(20,'\n');
        }
        else
        {
            loop = false; 
        }
    }  
    cin.ignore(1);
}

//*********************************************************
//
// Function Name: getyearofbirth
//
// Description: prompt the user for birth date information
//
// Parameters:yob(int): where birth date will be stored
//
// Return Values: void
//
//********************************************************\

void getyearofbirth(int * yob)
{
    #ifdef DEBUGMODE
        cout <<"*******************\n";
        cout << "Entering getyearofbirth(int*)\n";
        cout <<"*******************\n";
    #endif  
    bool loop = true;
    cout << "Enter the year of birth\n>";
    while(loop)
    {
        cin >> *yob;
        if(cin.fail() || yob <= 0) 
        {
            cout << "Enter a positive number\n>";
            cin.clear();
            cin.ignore(20,'\n');
        }
        else
        {
            loop = false; 
        }
    }  
    cin.ignore(1);
}
