#include <iostream>

using namespace std;

void printArr (int* arr) {
	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}


void bubbleSort (int* arr, int n) {
	for (int c = 0; c < n; c++) {
		for (int d = 0; d < (n-c-1); d++) {
			if (arr[d] > arr[d+1]) {
				int t = arr[d+1];
				arr[d+1] = arr[d];
				arr[d] = t;
				printArr (arr);
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	int array[5];

	for (int i = 0; i < 5; ++i)
	{
		cin >> array[i];
	}

	bubbleSort (array, 5);

	return 0;
}