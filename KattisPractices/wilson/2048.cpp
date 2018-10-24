#include <stdio.h>
#define SIZE 4



// Move the board upwards and break the backwards traversal of 'c' if an addition is made 
void moveUp (int matrix[][SIZE]) {
	int i, d, c; 
	for (i = 0; i < SIZE; i++) {
		int t = 0;
		for (d = 1; d < SIZE; d++) {
			for (c = d; c > t; c--) {
				if (matrix[c - 1][i] == 0) {
					// Perform moving up
					matrix[c - 1][i] = matrix[c][i];
					matrix[c][i] = 0;
				} else if (matrix[c][i] == matrix[c - 1][i]) {
					// Move up and add 
					matrix[c-1][i] += matrix[c][i];
					matrix[c][i] = 0;
					t = c;
				} 		
			}
		}
	}
}

// Move the board leftwards and break the backwards traversal of 'c' if an addition is made 
void moveLeft (int matrix[][SIZE]) {
	int i, d, c; 
	for (i = 0; i < SIZE; i++) {
		int t = 0;
		for (d = 1; d < SIZE; d++) {
			for (c = d; c > t; c--) {
				if (matrix[i][c - 1] == 0) {
					// Perform moving left
					matrix[i][c-1] = matrix[i][c];
					matrix[i][c] = 0;
				} else if (matrix[i][c] == matrix[i][c-1]) {
					// Move left and add 
					matrix[i][c-1] += matrix[i][c];
					matrix[i][c] = 0;
					t = c;
				} 		
			}
		}
	}
}

void moveDown (int matrix[][SIZE]) {
	int i, d, c; 
	for (i = 0; i < SIZE; i++) {
		int t = SIZE - 1;
		for (d = SIZE - 2; d >= 0; d--) {
			for (c = d;c < t ; c++) {
				if (matrix[c + 1][i] == 0) {
					matrix[c + 1][i] = matrix[c][i];
					matrix[c][i] = 0;
				} else if (matrix[c][i] == matrix[c + 1][i]) {
					matrix[c + 1][i] += matrix[c][i];
					matrix[c][i] = 0;
					t = c; 
				} 		
			}
		}
	}
}

void moveRight (int matrix[][SIZE]) {
	int i, d, c; 
	for (i = 0; i < SIZE; i++) {
		int t = SIZE - 1;
		for (d = SIZE - 2; d >= 0 ; d--) {
			for (c = d;c < t ; c++) {
				if (matrix[i][c + 1] == 0) {
					matrix[i][c + 1] = matrix[i][c];
					matrix[i][c] = 0;
				} else if (matrix[i][c] == matrix[i][c + 1]) {
					matrix[i][c + 1] += matrix[i][c];
					matrix[i][c] = 0;
					// Put a block there when a number is added to prevent more numbers from adding in 
					t = c;
				} 		
			}
		}
	}
}




// Read in the grid
void readGrid(int grid[][SIZE]) {
	int i,j;

	for (i=0; i<SIZE; i++)
		for (j=0; j<SIZE; j++)
			scanf("%d",&grid[i][j]);
}

// Print out the grid
void printGrid(int grid[][SIZE]) {
	int i,j;

	for (i=0; i<SIZE; i++) {
		for (j=0; j<SIZE; j++)
			printf("%d ",grid[i][j]);
		printf("\n");
	}
}

// Will play according to the instructions of numbers entered and checks everytime to see if the wanted number is formed. 
int play(int matrix[][SIZE], int direction) {
	switch (direction) {
		case 1:
		moveUp(matrix);
		break;
		case 0:
		moveLeft(matrix);
		break;
		case 2:
		moveRight(matrix);
		break;
		case 3: 
		moveDown(matrix);
		break;
	}
	return 0;
}

int main() {

	int grid[SIZE][SIZE];
	int directions;

	readGrid(grid);
	
	scanf("%d", &directions);
	play(grid, directions);

	printGrid (grid);

	return 0;
}
