#include <iostream>
#define MAX 30

using namespace std;



int getNum (int* array, int size) {
	for (int i = 0; i < size; i++) {
		cin >> array[i];
	}


	return size;
}

int findMax (int* array, int size) {
	int max = array[0];
	for (int i = 0; i < size; ++i)
	{
		if (array[i] > max) max = array[i];
	}
	return max;
}

int findMin (int* array, int size) {
	int min = array[0];
	for (int i = 0; i < size; ++i)
	{
		if (array[i] < min) min = array[i];
	}
	return min;
}

int findRange (int* array, int size) {
	return findMax (array, size) - findMin (array, size);
}


int main(int argc, char const *argv[])
{
	int array[MAX];
	int size, i;
	// Prime example for questions that do not specify the num of test cases
	for (i = 1; cin >> size; i++) {
		getNum(array, size);
		cout << "Case " << i << ": ";
		cout << findMin (array, size) << " " << findMax (array, size) << " " << findRange (array, size) << endl;
	}
	return 0;
}
