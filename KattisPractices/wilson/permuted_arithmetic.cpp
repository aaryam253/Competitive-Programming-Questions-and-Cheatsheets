#include <iostream>
#define MAX 100
using namespace std;

void bubbleSort (int* arr, int n) {
	for (int c = 0; c < n; c++) {
		for (int d = 0; d < (n-c-1); d++) {
			if (arr[d] > arr[d+1]) {
				int t = arr[d+1];
				arr[d+1] = arr[d];
				arr[d] = t;
			}
		}
	}
}

int processArithmetic (int* arr, int size) {
	int spaces = arr[1] - arr[0];
	for (int i = 0; i < size-1; ++i)
	{
		if (arr[i+1] - arr[i] != spaces) return 0;
	}
	return 1;
}


int main(int argc, char const *argv[])
{
	int numCases, arr[MAX];
	cin >> numCases;

	for (int i = 0; i < numCases; ++i)
	{
		int size;
		cin >> size;
		for (int d = 0; d < size; ++d)
		{
			cin >> arr[d];
		}
		if (processArithmetic(arr,size)){
			cout << "arithmetic" << endl;
			continue;
		} 
		bubbleSort(arr, size);
		if (processArithmetic (arr, size)) {cout << "permuted arithmetic" << endl;} 
		else {cout << "non-arithmetic" << endl;}
	}
	return 0;
}