/** 
 * Daniel Ty
 * TCSS 333
 * Programming assignment 4
 * Tested in cssgate server
 */  

#include "clientADT.h"
#include "preferencesADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct client {
    int id;
    char name[30];
    char email[25];
    char phoneNum[14];
    Preferences prefs;
};

/**
 * Returns pointer to client struct; NULL if struct not created
 * 
 */
Client createClient(int theId, char* theName, char* theEmail,
    char* thePhoneNum) {
    Client client = malloc(sizeof(struct client));
    if (client != NULL) {
        client->id = theId;
        strcpy(client->name, theName);
        strcpy(client->email, theEmail); 
        strcpy(client->phoneNum, thePhoneNum);
    }
    return client;
}

int getClientID(Client theClient) {
    return theClient->id;
}

char* getClientName(Client theClient) {
    return theClient->name;
}

void addPrefs(Client theClient, Preferences thePrefs) {
    theClient->prefs = thePrefs;
}

Preferences getPrefs(Client theClient) {
    return copyPrefs(theClient->prefs);
}

void printClient(Client theClient) {
    printf("%i\n", theClient->id);
    printf("%s\n", theClient->name);
    printf("%s\n", theClient->email);
    printf("%s\n", theClient->phoneNum);
    printPrefs(theClient->prefs);
}