#include <stdio.h>
#include <string.h>

void printMap (int row, int col, char map [][500]) {
    for (int i = 0; i < row; i++) {
        printf("%s\n", map[i]);
    }
}

void backTrack (char directions[][6], char map[][500], int index, int x, int y) {
    map[y][x] = 'S';
    for (int i = 0; i < index; i++) {
        if (!strcmp(directions[i], "down")) {
            y += 1;
            map[y][x] = '*';
        }
        else if (!strcmp(directions[i], "up")) {
            y -= 1;
            map[y][x] = '*';

        }
        else if (!strcmp(directions[i], "left")) {
            x -= 1;
            map[y][x] = '*';

        }
        else if (!strcmp(directions[i], "right")) {
            x += 1;
            map[y][x] = '*';

        }
    }
    map[y][x] = 'E';
}


int main () {
    // Assume S is at 0, 0
    int x = 0, y = 0, index = 0;
    int largestX = 0, minX = 0;
    int largestY = 0, minY = 0;
    char directions [500][6];
    char map[500][500];
    char direction[6];


    while (scanf("%s", direction) == 1) {
        strcpy(directions[index++], direction);
        
        if (!strcmp(direction, "down")) {
            y += 1;
            if (y > largestY) {
                largestY = y;
            }
            if (y < minY) {
                minY = y;
            }
        }
        else if (!strcmp(direction, "up")) {
            y -= 1;
            if (y > largestY) {
                largestY = y;
            }
            if (y < minY) {
                minY = y;
            }
        }
        else if (!strcmp(direction, "left")) {
            x -= 1;
            if (x > largestX) {
                largestX = x;
            }
            if (x < minX) {
                minX = x;
            }
        }
        else if (!strcmp(direction, "right")) {
            x += 1;
            if (x > largestX) {
                largestX = x;
            }
            if (x < minX) {
                minX = x;
            }
        }
    }    
        
    int row = largestY- minY + 3;
    int col = largestX - minX + 3;
    // TODO: Fix path tracing, adjust the row and columns here with respect to largest and smallest
    /*
    printf("%d %d\n", largestX, minX);
    printf("%d %d\n", largestY, minY);
    */

    for (int i = 0; i < row; i++) {
        for (int d =  0; d < col; d++) {
            if (i == 0 || i == row-1) {
                map[i][d] = '#';
            }
            else if (d == 0 || d == col-1) {
                map[i][d] = '#';
            }
            else {
                map [i][d] = ' ';
            }
            
        }
    }
    backTrack(directions, map, index, 0 - minX+1, 0 - minY+1);
    
    printMap(row, col, map);
    
}

