#include <iostream>
#include <cstring>
#include <math.h>

#define MAX 100
#define STR_MAX 10000

using namespace std;

void decode (char matrix[][MAX], int size) ;
int matrix_convert (char input[], char matrix[][MAX]);
void matrix_read (char output[], char matrix[][MAX], int size);
void print_matrix (int size, char matrix[][MAX]);

int main(int argc, char const *argv[])
{	
	int num_case;
	cin >> num_case;

	for (int i = 0; i < num_case; i++) {

		char input[STR_MAX];
		char matrix [MAX][MAX];
		cin >> input;

		int size = matrix_convert(input, matrix);
		// Need to rotate 3 times
		decode (matrix, size);
		decode (matrix, size);
		decode (matrix, size);

		matrix_read(input, matrix, size);

		cout << input << endl;
	}
	

	return 0;
}


void decode (char matrix[][MAX], int size) {
	char matrix_dupe[MAX][MAX];

	int i, d;
	// Clone and transpose
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			// Starts from bottom row first column
			matrix_dupe[i][d] = matrix[size - d - 1][i];
		}
	}

	// Fix the transposition back to the original array 
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			matrix[i][d] = matrix_dupe[i][d];
		}
	}
}

int matrix_convert (char input[], char matrix[][MAX]) {
	int size = strlen(input);
	size = pow(size,0.5);
	int i, d, index = 0;
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			matrix[i][d] = input[index++];
		}
	}
	return size;
}

void matrix_read (char output[], char matrix[][MAX], int size) {
	int i, d, index = 0;
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			output[index++] = matrix[i][d];
		}
	}
}

void print_matrix (int size, char matrix[][MAX]) {
	int i, d;
	for (i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			cout << matrix[i][d];
		}
		cout << endl;
	}
}