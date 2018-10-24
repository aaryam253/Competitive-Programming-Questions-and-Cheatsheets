#include <iostream>

using namespace std;

int calculate (int* arr) {
	int total = 0;
	int arr3[8] = {1,2,6,30,210,2310,30030,510510};
	int arr2[8] = {1,2,4,6,10,12,16,18};
	for (int i = 0; i < 8; ++i)
	{
		total += (arr2[i] - arr[i]) * arr3[i];
	}
	return total;
}

void readInput (int* arr) {
	int i;
	for (i = 0; i < 8; i++) {
		cin >> arr[i];
	}
}

int main(int argc, char const *argv[])
{
	int arr[8];
	readInput (arr);
	int result = calculate (arr);
	cout << result << endl;	
	return 0;
}