#ifndef LLIST_H_
#define LLIST_H_
#include <iostream>
#include "record.h"
using namespace std;
class llist
{
    private:
        record * start;
        char     filename[16];
        int      readfile();
        int      writefile();
        record * reverse(record *);
        void     cleanup();

    public:
        llist();
        llist(char[]);
        ~llist();
        int addRecord (int, char [ ],char [ ],int);
        int printRecord (int);
        int modifyRecord ( int, char [ ]);
        void printAll();
        int deleteRecord(int);
        void reverse();
        void charArrayCopy(char[],char[]);
        void callReadFile();
        void callWriteFile(); 
        friend ostream &operator<<(ostream &, llist &);
};
#endif
