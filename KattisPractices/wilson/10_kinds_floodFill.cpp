#include <stdio.h>
#include <iostream>

using namespace std;

void fill (int matrix[][1000], int x, int y, int r, int c, int paint, int current) {
    matrix[y][x] = paint;
    // For decimal
    if (x+1 < c && matrix[y][x+1] == current)
        fill (matrix, x+1, y, r, c, paint, current);
    if (x-1 >= 0 && matrix[y][x-1] == current)
        fill (matrix, x-1, y, r, c, paint, current);
    if (y-1 >= 0 && matrix[y-1][x] == current)
        fill (matrix, x, y-1, r, c, paint, current);
    if (y+1 < r && matrix[y+1][x] == current)
        fill (matrix, x, y+1, r, c, paint, current);
}


void printMap (int arr[][1000], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int d = 0; d < c; d++) {
            printf("%2d", arr[i][d]);
        }
        printf("\n");
    }
}

int main () {
    int r, c;
    int arr[1000][1000] = {0};

    scanf("%d %d" ,&r, &c);
    
    for (int i = 0;  i < r; i++) {
        printf("Progress: %d\n", i);
        char mynum[1001];
        scanf("%s", mynum);
        for (int d = 0; d < c; d++) {
            arr[i][d] = mynum[d] - '0';
        }
    }
    
    printf("Done generating map\n");
    int num;
    scanf("%d", &num);
    
    int binary = 0;
    int decimal = 1;

    for (int i = 0; i < num; i++) {
        int y1, x1, y2, x2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        
        if (arr[y1-1][x1-1] == arr[y2-1][x2-1] && arr[y1-1][x1-1] != 0 && arr[y1-1][x1-1] != 1) {
            if (arr[y1-1][x1-1] <= 0) {
                printf("binary\n");
            }else {
                printf("decimal\n");
            }
            
            continue;
        }
        
        if (arr[y1-1][x1-1] >= 1) {
            decimal++;
            int current = arr[y1-1][x1-1];
            fill(arr, x1-1, y1-1, r, c, decimal, current);
        }else if (arr[y1-1][x1-1] <= 0){
            binary--;
            int current = arr[y1-1][x1-1];
            fill(arr, x1-1, y1-1, r, c, binary, current);
        }
        
        if (arr[y1-1][x1-1] == arr[y2-1][x2-1]) {
            if (arr[y1-1][x1-1] <= 0) {
                printf("binary\n");
            }else {
                printf("decimal\n");
            }
        }else {
            printf("neither\n");
        }
    }
    /*

    printMap(arr, r, c);
    for (int i = 0; i < 1000; i++) {
        for (int d = 0; d < 1000; d++) {
            printf("%d", 1);
        }
        printf("\n");
    }
     */
}
