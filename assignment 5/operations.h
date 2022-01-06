#ifndef OPERATIONS_H
#define OPERATIONS_H

#pragma pack(1)
struct animal {
    short int id;
    char name[20];
    char species[35];
    char size;
    short int age;
};

void opOne(FILE* theFilePtr);

void opTwo(FILE* theFilePtr);

void opThree(FILE* theFilePtr);

void opFour(FILE* theFilePtr);

void opFive(FILE* theFilePtr);

int seekID(FILE* theFilePtr);

void outputToCsv(FILE* theFilePtr, FILE* theCsvPtr);

void copyRecords(FILE* theDest, FILE* theSource);

#endif