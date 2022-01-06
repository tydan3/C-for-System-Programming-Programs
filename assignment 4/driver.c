/** 
 * Daniel Ty
 * TCSS 333
 * Programming assignment 4
 * Tested in cssgate server
 */  

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "clientADT.h"
#include "preferencesADT.h"

void loadClients(Client* theClientList, FILE* theClientFile, int* thelistSize);
void loadPrefs(Client* theClientList, FILE* thePrefsFile, int thelistSize);
void outputMatches(Client* theClientList, FILE* theHousesFile, int thelistSize);

int main(void) {
    int listSize = 0;       // number of actual clients in list
    Client clientList[10];  // list of clients

    FILE* filePtr;
    
    // open client file and load clients
    if ((filePtr = fopen("clients.txt", "r")) == NULL) {
        puts("File couuld not be opened");
    } else {
        loadClients(clientList, filePtr, &listSize);
        fclose(filePtr);
    }

    // open preferences file and load preferences
    if ((filePtr = fopen("preferences.txt", "r")) == NULL) {
        puts("File couuld not be opened");
    } else {
        loadPrefs(clientList, filePtr, listSize);
        fclose(filePtr);
    }

    // open houses file and match to clients
    if ((filePtr = fopen("houses.csv", "r")) == NULL) {
        puts("File couuld not be opened");
    } else {
        outputMatches(clientList, filePtr, listSize);
        fclose(filePtr);
    }    

}

void loadClients(Client* theClientList, FILE* theClientFile, int* thelistSize) {
    Client myClient;
    int id;
    char name[30];
    char email[30];
    char phoneNum[13];

    fscanf(theClientFile, " %i", &id);
    fscanf(theClientFile, " %[^\n]*c", &name);
    fscanf(theClientFile, " %[^\n]*c", &email);
    fscanf(theClientFile, " %[^\n]*c", &phoneNum);

    myClient = createClient(id, name, email, phoneNum);
    theClientList[(*thelistSize)++] = myClient;

    while(!feof(theClientFile)) {
        fscanf(theClientFile, " %i", &id);
        fscanf(theClientFile, " %[^\n]*c", &name);
        fscanf(theClientFile, " %[^\n]*c", &email);
        fscanf(theClientFile, " %[^\n]*c", &phoneNum);

        myClient = createClient(id, name, email, phoneNum);
        theClientList[(*thelistSize)++] = myClient;
    }
}

void loadPrefs(Client* theClientList, FILE* thePrefsFile, int thelistSize) {
    Preferences myPrefs;
    int id;
    int minBeds;
    int minBaths;
    int maxprice;
    int neighborhood;

    fscanf(thePrefsFile, "%i\n", &id);
    fscanf(thePrefsFile, "%i%i%i%i", &minBeds, &minBaths, &maxprice,
        &neighborhood);
    myPrefs = createPrefs(id, minBeds, minBaths, maxprice, neighborhood);

    int i;
    for (i = 0; i < thelistSize; i++) {
        if (getClientID(theClientList[i]) == getPrefsID(myPrefs)) {
            addPrefs(theClientList[i], myPrefs);
        }
    }

    while(!feof(thePrefsFile)) {
        fscanf(thePrefsFile, "%i\n", &id);
        fscanf(thePrefsFile, "%i%i%i%i", &minBeds, &minBaths, &maxprice,
            &neighborhood);
        myPrefs = createPrefs(id, minBeds, minBaths, maxprice, neighborhood);

        for (i = 0; i < thelistSize; i++) {
            if (getClientID(theClientList[i]) == getPrefsID(myPrefs)) {
                addPrefs(theClientList[i], myPrefs);
            }
        }
    }
}

void outputMatches(Client* theClientList, FILE* theHousesFile, int thelistSize) {
    FILE* output = fopen("houseView.csv", "w");
    // char* myHeader = (char*) malloc(sizeof (char) * 100);
    char myHeader[100]; 
    char myMatch[100];
    int beds;
    int baths;
    int price;
    int nhood;

    // skip
    fgets(myHeader, 100, theHousesFile); // %*[^\n]\n
    myHeader[strcspn(myHeader, "\n")] = '\0'; 

    strcat(myHeader, ", ,Client ID,Name");
    fprintf(output, "%s\n", myHeader);

    while(!feof(theHousesFile)) {
        fgets(myMatch, 100, theHousesFile);
        myMatch[strcspn(myMatch, "\n")] = 0;

        char* token = strtok(myMatch, ",");
        int i;
        for(i = 0; i < 8; i++) {
            token = strtok(NULL, ",");
            switch (i) {
                case 3:
                    beds = atoi(token);
                    break;
                case 4:
                    baths = atoi(token);
                    break;
                case 5:
                    price = atoi(token);
                    break;
                case 6:
                    nhood = atoi(token);
                    break;                         
            }
        }

        Preferences myPrefs;
        Client myClient;
        for (i = 0; i < thelistSize; i++) {
            myClient = theClientList[i];
            myPrefs = getPrefs(myClient);
            if (beds > getPrefsBaths(myPrefs) && baths > getPrefsBaths(myPrefs) &&
                price < getPrefsPrice(myPrefs) && (nhood >= getPrefsNhood(myPrefs) - 10
                &&  nhood <= getPrefsNhood(myPrefs) + 10)) {

                char id[5];
                char* name;
                sprintf(id, "%i", getClientID(myClient));
                name = getClientName(myClient);
                fprintf(output, "%s", myMatch);
                fprintf(output, ", ,%s,%s\n", id, name);
            }
        }
    }
}