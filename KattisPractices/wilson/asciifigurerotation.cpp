#include <stdio.h>
#include <iostream>
#include <string.h>


#define MAX 1000
using namespace std;


void rotate (char mtx[][MAX], int size, int largest) {
    char newMtx [MAX][MAX];
    for (int i = 0; i < largest; i++) {
        for (int d = size-1; d >= 0 ; d--) {
            // Starts from bottom row first column
            
            char myprint = mtx[d][i];
            
            if (myprint == '|') newMtx[i][size-d-1] = '-';
            else if (myprint == '-') newMtx[i][size-d-1] = '|';
            else newMtx[i][size-d-1] = myprint;
        }
    }
    
    // Cleaning and removing whitespaces
    for (int i = 0; i < largest; i++) {
        for (int d = size-1; d >= 0; d--) {
            if (newMtx[i][d] != ' ') break;
            else newMtx[i][d] = '\0';
        }
    }
    
    printMatrix(newMtx, largest);
}



int main () {
    int lines;
    int flag = 0;
    do {
        
        char mtx[MAX][MAX] = {{0}};
        int largest = 0, i = 0;
        scanf("%d", &lines);
        if (flag && lines != 0) {
            printf("\n");
        }
        //printf("%d\n", lines);
        while (i < lines) {
            char myString [MAX];
            fgets(myString, MAX, stdin);
            if (myString[0] != '\n') {
                strcpy(mtx[i], myString);
                
                if (strlen(mtx[i]) > largest) largest = strlen(mtx[i])-1;
                for (int d = 0; mtx[i][d] != '\0'; d++) {
                    if (mtx[i][d] == '\n') mtx[i][d] = '\0';
                }
                i++;
            }
        }
        
        // Cleaning and adding white spaces
        
        for (i = 0; i < lines; i++) {
            int d;
            for (d = 0; d < largest; d++) {
                if (mtx[i][d] == '\0') mtx[i][d] = ' ';
            }
            mtx[i][d] = '\0';
        }
        
        //printMatrix(mtx, lines);
        
        if (lines != 0) {
            rotate(mtx, lines, largest);
        }
        flag = 1;
        
    }while (lines != 0);
    
}
