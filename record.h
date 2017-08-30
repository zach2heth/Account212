#ifndef RECORD_H_ 
#define RECORD_H_ 
struct record
{
    int accountno;
    char name[25];
    char address[80];
    int yearofbirth;
    struct record* next;
};
#endif
