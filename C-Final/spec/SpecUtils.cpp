#include "stdafx.h"
#define NULL 0

//returns true if strings a & b are same.
bool areEqualStrings(char a[], char b[]){
    int i;
    if (a == NULL || b == NULL) {
        if (a == b) {
            return true;
        } else {
            return false;
        }
    }
    for (i = 0; a[i] != '\0' && b[i] != '\0'; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    if (a[i] == '\0' && b[i] == '\0') {
        return true;
    }
    
    return false;
}


bool areEqualArrays(int a[], int b[], int size){
    for (int i = 0; i < size; i++){
        if (a[i] != b[i])
            return false;
    }
    return true;
}

