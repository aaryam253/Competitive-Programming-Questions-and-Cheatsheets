#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

char arr[11][7][6] = {{"xxxxx", "x...x", "x...x", "x...x", "x...x" ,"x...x" ,"xxxxx"},
    {"....x","....x","....x","....x","....x","....x","....x"},
    {"xxxxx","....x","....x","xxxxx","x....","x....","xxxxx"},
    {"xxxxx","....x","....x","xxxxx","....x","....x","xxxxx"},
    {"x...x","x...x","x...x","xxxxx","....x","....x","....x"},
    {"xxxxx","x....","x....","xxxxx","....x","....x","xxxxx"},
    {"xxxxx","x....","x....","xxxxx","x...x","x...x","xxxxx"},
    {"xxxxx","....x","....x","....x","....x","....x","....x"},
    {"xxxxx","x...x","x...x","xxxxx","x...x","x...x","xxxxx"},
    {"xxxxx","x...x","x...x","xxxxx","....x","....x","xxxxx"},
    {".....","..x..","..x..","xxxxx","..x..","..x..","....."}
};

char translation [11] = {'0','1','2','3','4', '5', '6', '7', '8', '9', '+'};


void display (char input[7][6]) {
    for (int i = 0; i < 7; i++) {
        printf("%s\n", input[i]);
    }
}

int checkMtx (char arr[][7][6], char input[][6]) {
    int d;
    for (d = 0; d < 11; d++) {
        int count = 0;
        for (int i = 0; i < 7; i++) {
            if (!strcmp(arr[d][i], input[i])) {
                count++;
            }
        }
        if (count == 7) return d;
    }
    
    return -1;
}

int main () {
    char input[7][1000000];
    
    for (int i = 0; i < 7; i++) {
        scanf("%s", input[i]);
    }
    int num1_index = 0, num2_index = 0;
    char num1[1000] = "\0";
    char num2[1000] = "\0";
    int flag = 1;
    
    for (int i = 0; input[0][i] != '\0'; i += 6) {
        char send[7][6];
        for (int d = 0; d < 7; d++) {
            for (int c = 0; c < 5; c++) {
                send[d][c] = input[d][c+i];
            }
        }
        int status = checkMtx(arr, send);
        if (status == 10) {
            flag = 0;
            continue;
        }
        
        if (flag) {
            num1[num1_index++] = status+ '0';
        }else {
            num2[num2_index++] = status + '0';
        }
        
    }
    
    num2[num2_index] = '\0';
    num1[num1_index] = '\0';
    
    int result = atoi(num1) + atoi(num2);
    
    //printf("%d\n", result);
    char resultant[7][1000];
    char resultant_str [1000];
    int resultant_str_index = 0;
    // Number splitter
    int stop = 0;
    while (result) {
        resultant_str[resultant_str_index++] = (result%10 + '0');
        result /= 10;
    }
    resultant_str[resultant_str_index] = '\0';
    
    for (int x = strlen(resultant_str)-1; x >= 0; x--) {
        for (int i = 0; i < 7; i++) {
            for (int d = 0; d < 5; d++) {
                resultant[i][d+stop] = arr[resultant_str[x]-'0'][i][d];
            }
        }
        // Add the divider, but not for the last one
        stop += 6;
        if (x != 0) {
            for (int i = 0; i < 7; i++) {
                resultant[i][stop-1] = '.';
            }
        }
        
        
    }
    
    for (int i = 0; i < 7; i++) {
        printf("%s\n", resultant[i]);
    }
}

