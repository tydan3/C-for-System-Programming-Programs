/** 
 * Daniel Ty
 * TCSS 333
 * Programming assignment 4
 * Tested in cssgate server
 */  
#include "preferencesADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct preferences {
    int id;
    int minBeds;
    int minBaths;
    int maxprice;
    int neighborhood;
};

Preferences createPrefs(int theId, int theMinBeds, int theMinBaths, int theMaxPrice,
    int theNeighborhood) {
    Preferences prefs = malloc(sizeof(struct preferences));
    if (prefs != NULL) {
        prefs->id = theId;
        prefs->minBeds = theMinBeds;
        prefs->minBaths = theMinBaths;
        prefs->maxprice = theMaxPrice;
        prefs->neighborhood = theNeighborhood;        
    }
    return prefs;
}

int getPrefsID(Preferences thePrefs) {
    return thePrefs->id;
}

int getPrefsBeds(Preferences thePrefs) {
    return thePrefs->minBeds;
}

int getPrefsBaths(Preferences thePrefs) {
    return thePrefs->minBaths;
}

int getPrefsPrice(Preferences thePrefs) {
    return thePrefs->maxprice;
}

int getPrefsNhood(Preferences thePrefs) {
    return thePrefs->neighborhood;
}


Preferences copyPrefs(Preferences thePrefs) {
    return createPrefs(thePrefs->id, thePrefs->minBeds, thePrefs->minBaths, 
        thePrefs->maxprice, thePrefs->neighborhood);
}


void printPrefs(Preferences thePrefs) {
    printf("%i\n", thePrefs->id);
    printf("%i\n", thePrefs->minBeds);
    printf("%i\n", thePrefs->minBaths);
    printf("%i\n", thePrefs->maxprice);
    printf("%i\n", thePrefs->neighborhood);
}