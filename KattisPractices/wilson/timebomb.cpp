#include <iostream>
#include <cstdio>

#define MAX 10000

using namespace std;

void print_num (char numbers[][4]);
void read_mtx (char mtx[5][MAX]);
int splitter (char mtx[5][MAX], char split_mtx[MAX][5][4]);
int check (char a[5][4], char b[5][4]);
int checker (char split_mtx[MAX][5][4], char numbers[10][5][4], int size);



int main(int argc, char const *argv[])
{
	char numbers[10][5][4] = {{"***", "* *", "* *", "* *", "***"}, 
	{"  *", "  *", "  *", "  *", "  *"}, 
	{"***", "  *", "***", "*  ", "***"}, 
	{"***", "  *", "***", "  *", "***"}, 
	{"* *", "* *", "***", "  *", "  *"}, 
	{"***", "*  ", "***", "  *", "***"}, 
	{"***", "*  ", "***", "* *", "***"}, 
	{"***", "  *", "  *", "  *", "  *"}, 
	{"***", "* *", "***", "* *", "***"}, 
	{"***", "* *", "***", "  *", "***"}};
	char mtx [5][MAX];
	char split_mtx [MAX][5][4];

	
	read_mtx (mtx);
	int size = splitter (mtx, split_mtx);
	/**
	for (int i = 0; i < size; i++) 
		print_num (split_mtx[i]);
	*/
	int condition = checker (split_mtx, numbers, size);

	if (condition == 1) cout << "BEER!!" << endl;
	else cout << "BOOM!!" << endl;


	return 0;
}


void print_num (char numbers[][4]) {
	int i, d;
	for (i = 0; i < 5; i++) {
		cout << numbers[i] << endl;
	}
	cout << endl;
}


void read_mtx (char mtx[5][MAX]) {
	int i, d;
	for (i = 0; i < 5; i++) {
		fgets(mtx[i] ,MAX, stdin);
		for (d = 0; mtx[i][d] != '\0'; d++) {
			if (mtx[i][d] == '\n') mtx[i][d] = '\0';
		}
	}
}

int splitter (char mtx[5][MAX], char split_mtx[MAX][5][4]) {
	int i = 3, index = 0;
	int d, c;
	while (mtx[0][i] != '\0') {
		for (d = 0; d < 5; d++) {
			int f = 0;
			for (c = i - 3; c < i; c++) {
				split_mtx[index][d][f++] = mtx[d][c];
			}
			split_mtx[index][d][f] = '\0';
		}
		index++;
		i += 4;
	}
	// Incomplete
	for (d = 0; d < 5; d++) {
		int f = 0;
		for (c = i - 3; c < i; c++) {
			split_mtx[index][d][f++] = mtx[d][c];
		}
		split_mtx[index][d][f] = '\0';
	}
	index++;
	return index;
}

int checker (char split_mtx[MAX][5][4], char numbers[10][5][4], int size) {
	string numbers_str;
	int i;
	for (i = 0; i < size; i++) {
		int d;
		// Check thru all the numbers in the numbers bank
		for (d = 0; d < 10; d++) {
			if (check(split_mtx[i], numbers[d])) {
				numbers_str += d + '0';
				break;
			}else if (d == 9) return -1;
		}
	}

	if (stoi(numbers_str)%6 == 0) return 1;

	return 0;
}


int check (char a[5][4], char b[5][4]) {
	int i, d;
	for (i = 0; i < 5; i++) {
		for (d = 0; b[i][d] != '\0'; d++) {
			if (b[i][d] != a[i][d]) {
				return 0;
			}
		}
	}
	return 1;
}