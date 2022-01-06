/** 
 * Daniel Ty
 * TCSS 333
 * Programming assignment 4
 * Tested in cssgate server
 */  

#ifndef PREFERENCESADT_H
#define PREFERENCESADT_H

typedef struct preferences* Preferences;
Preferences createPrefs(int theId, int theMinBeds, int theMinBaths, int theMaxPrice,
    int theNeighborhood);
int getPrefsID(Preferences thePrefs);
int getPrefsBeds(Preferences thePrefs);
int getPrefsBaths(Preferences thePrefs);
int getPrefsPrice(Preferences thePrefs);
int getPrefsNhood(Preferences thePrefs);
Preferences copyPrefs(Preferences thePrefs);
void printPrefs(Preferences thePrefs);

#endif