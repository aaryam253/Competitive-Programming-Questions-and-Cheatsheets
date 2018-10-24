#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;


void set (int i, char bits[]) {
    bits[i] = '1';
}

void clear (int i, char bits[]) {
    bits[i] = '0';
}

void AND (int i, int d, char bits[]) {
    if (bits[i] != '?' && bits[d] != '?') {
        // No unknowns
        if (bits[i] == '0' || bits[d] == '0') {
            bits[i] = '0';
        }
    }else{
        bits[i] = '?';
    }
}

void OR (int i, int d, char bits[]) {
    if (bits[i] != '?' && bits[d] != '?') {
        // No unknowns
        if (bits[i] == '1' || bits[d] == '1') {
            bits[i] = '1';
        }
    }else{
        bits[i] = '?';
    }
}

int main () {
    int instr;
    char bits[33];
    do {
        // Init
        for (int i = 0; i < 32; i++) {
            bits[i] = '?';
        }
        bits[32] = '\0';
        
        scanf("%d", &instr);
        
        for (int i = 0; i < instr; i++) {
            char instruction[10];
            int bit, bit2;
            scanf("%s", instruction);
            if (!strcmp(instruction, "CLEAR")) {
                scanf("%d", &bit);
                clear(31 - bit, bits);
            }
            else if (!strcmp(instruction, "SET")) {
                scanf("%d", &bit);
                set(31 - bit, bits);
            }
            else if (!strcmp(instruction, "AND")) {
                scanf("%d %d", &bit, &bit2);
                AND(31 - bit, 31 - bit2, bits);
            }
            else if (!strcmp(instruction, "OR")) {
                scanf("%d %d", &bit, &bit2);
                OR(31 - bit, 31 - bit2, bits);
            }
        }
        if (instr) {
            printf("%s\n", bits);
        }
    }while (instr != 0);
    
    
}
