/** 
 * Daniel Ty
 * TCSS 333
 * Programming assignment 4
 * Tested in cssgate server
 */  

#ifndef CLIENTADT_H
#define CLIENTADT_H
#include "preferencesADT.h"


typedef struct client* Client;
Client createClient(int theId, char* theName, char* theEmail, char* thephoneNum);
int getClientID(Client theClient);
char* getClientName(Client theClient);
void addPrefs(Client theClient, Preferences thePrefs);
Preferences getPrefs(Client theClient);
void printClient(Client theClient);

#endif