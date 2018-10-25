//
//  main.cpp
//  Treasure Hunt
//
//  Created by Aaryam Srivastava on 9/1/2018.
//  Copyright © 2018 LearnAppMaking. All rights reserved.
//

#include <iostream>
using namespace std;

void directions (char grid[][200], int* r, int* c);
int travelling (char grid[][200], int r, int c) ;

int main(void) {
    int rows, columns;
    char grid [200][200];
    
    directions (grid, &rows, &columns);
    int moves = travelling(grid, rows, columns);
    
    if (moves == -2) {
         cout << "Out" << endl;
    }
    else if (moves == -1) {
        cout << "Lost" << endl;
    }
    else {
        cout << moves << endl;
    }
   
    return 0;
}

int travelling (char grid[][200], int rows, int columns) {
    int x = 0, y = 0;
    int moves = 0;
    int array[200][200] = {{0}};
    
    //simulates each direction, command
    while (1) {
        switch (grid[x][y]) {
            case 'N':
                x--;
                break;
            case 'S':
                x++;
                break;
            case 'W':
                y--;
                break;
            case 'E':
                y++;
                break;
            case 'T':
                return moves;
        }
        moves++;
        
        //condition when the player moves out of the board
        if (x < 0 || y < 0 || y >= columns || x >= rows) {
            return -2;
        }
        
        if (array[x][y]) {
            return -1;
        }
        else {
            array[x][y] = 1;
        }
    }
}

void directions (char grid[][200], int* rows, int* columns) {
    cin >> *rows >> *columns;
    
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *columns; j++) {
            cin >> grid[i][j];
        }
    }
}
