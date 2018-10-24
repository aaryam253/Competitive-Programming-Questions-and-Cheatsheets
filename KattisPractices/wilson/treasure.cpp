#include <iostream>
#define MAX 200


using namespace std;

int runMap (char matrix[][MAX], int r, int c) ;
void readMap (char matrix[][MAX], int* r, int* c);

int main(int argc, char const *argv[])
{
	int r, c;
	char matrix [MAX][MAX];

	readMap (matrix, &r, &c);
	int num_turns = runMap(matrix, r, c);

	switch (num_turns) {
		case -2:
		cout << "Out" << endl;
		break;
		case -1:
		cout << "Lost" << endl;
		break;
		default:
		cout << num_turns << endl;
	}
	return 0;
}

void readMap (char matrix[][MAX], int* r, int* c) {
	cin >> *r >> *c;
	int i, d;
	for (i = 0; i < *r; i++) {
		for (d = 0; d < *c; d++) {
			cin >> matrix[i][d];
		}
	}
}

int runMap (char matrix[][MAX], int r, int c) {
	int i = 0, d = 0, count = 0; 
	int arr[MAX][MAX] = {{0}};
	while (1) {
		switch (matrix[i][d]) {
			// Movement 
			case 'N':
			i--;
			break;
			case 'S':
			i++;
			break;
			case 'W':
			d--;
			break;
			case 'E':
			d++;
			break;
			case 'T':
			return count;
		}
		count++;
		// Out
		if (i < 0) return -2;
		if (d < 0) return -2;
		if (d >= c) return -2;
		if (i >= r) return -2;

		if (arr[i][d]) {
			return -1;
		}
		else {
			arr[i][d] = 1;
		}
	}
	
}
