#include "stdio.h"
#define MAX 1002

using namespace std;


int count_perim = 0;


void flood (char arr[][MAX], int x, int y, int row, int col) {
    arr[y][x] = '*';
    if (y + 1 < row && arr[y+1][x] == '1') count_perim++;
    if (x + 1 < col && arr[y][x+1] == '1') count_perim++;
    if (y - 1 >= 0 && arr[y-1][x] == '1') count_perim++;
    if (x - 1 >= 0 && arr[y][x-1] == '1') count_perim++;

    if (y + 1 < row && arr[y+1][x] != '*' && arr[y+1][x] != '1') {
        flood (arr, x, y+1, row, col);
    }else if (arr[y+1][x] != '*' && arr[y+1][x] != '1'){
        //arr[y+1][x] = '&';
    }
    if (x + 1 < col && arr[y][x+1] != '*' && arr[y][x+1] != '1') {
        flood(arr, x+1, y, row, col);

    }else if (arr[y][x+1] != '*' && arr[y][x+1] == '1'){
    }
    if (x - 1 >= 0 && arr[y][x-1] != '*' && arr[y][x-1] != '1') {
        flood(arr, x-1, y, row, col);

    }else if (arr[y][x-1] != '*' && arr[y][x-1] == '1'){
        //arr[y][x-1] = '&';
    }
    if (y - 1 >= 0 && arr[y-1][x] != '*' && arr[y-1][x] != '1') {
        flood(arr, x, y-1, row, col);

    }else if (arr[y-1][x] != '*' && arr[y-1][x] == '1'){
        //arr[y-1][x] = '&';
    }
    
}

void print_array (char arr[][MAX], int row, int col) {
    int i, d;
    for (i = 0; i < row; i++) {
        for (d = 0; d < col; d++) {
            printf("%c", arr[i][d]);
        }
        printf("\n");
    }
}


int main () {
    char arr [MAX][MAX];
    int i, d, perimeter, area;
    int row, col;
    scanf("%d %d", &row, &col);
    
    // Scanf with introducing sentinels
    for (int i = 0; i < row; i++) scanf("%s", arr[i + 1]+1);
    for (int i = 0; i < row + 2; i++)
    {
        arr[i][0] = '0';
        arr[i][col+1] = '0';
    }
    for (int i = 0; i < col + 2; i++)
    {
        arr[0][i] = '0';
        arr[row+1][i] = '0';
    }
    
    
    
    flood(arr, 0, 0, row+2, col+2);
    
    //print_array(arr, row+2, col+2);
    
    printf("%d\n", count_perim);
    
}


