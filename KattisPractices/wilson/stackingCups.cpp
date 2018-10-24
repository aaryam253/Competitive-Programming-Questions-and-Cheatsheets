#include <iostream>
#include <cstring>
#define MAX 100000

using namespace std;

typedef struct {
	char name[MAX];
	int unit;
}cups;

int readCups(cups* array) {
	int size;
	cin >> size;
	for (int i = 0; i < size; ++i)
	{
		char placeholder[MAX], placeholder2[MAX]; 
		cin >> placeholder >> placeholder2;
		cups thisCup;
		if (atoi(placeholder)) {
			// Radius detected
			thisCup.unit = atoi(placeholder)/2;
			strcpy(thisCup.name, placeholder2);
		}else{
			strcpy(thisCup.name, placeholder);
			thisCup.unit = atoi(placeholder2);
		}
		array[i] = thisCup;
	}
	return size;
}

void bubbleSort (cups* arr, int n) {
	for (int c = 0; c < n; c++) {
		for (int d = 0; d < (n-c-1); d++) {
			if (arr[d].unit > arr[d+1].unit) {
				cups t = arr[d+1];
				arr[d+1] = arr[d];
				arr[d] = t;
			}
		}
	}
}

void printCups (cups* arr, int size) {
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i].name << endl;
	}
}

int main(int argc, char const *argv[])
{
	cups array[20];
	int size = readCups(array);	

	bubbleSort(array, size);
	printCups (array, size);
	return 0;
}