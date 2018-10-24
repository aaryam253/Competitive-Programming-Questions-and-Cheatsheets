#include <iostream>

using namespace std;

void bubbleSort (string* arr, int n) {
	for (int c = 0; c < n; c++) {
		for (int d = 0; d < (n-c-1); d++) {
			// concatenate 
			string t_1, t_2;
			t_1 += arr[d][0];
			t_1 += arr[d][1];
			t_2 += arr[d+1][0];
			t_2 += arr[d+1][1];
			if (t_1 > t_2) {
				string t = arr[d+1];
				arr[d+1] = arr[d];
				arr[d] = t;
			}
		}
	}
}



int main(int argc, char const *argv[])
{
	int numInputs;
	string arr[200];

	do {
		scanf ("%d", &numInputs);
		for (int i = 0; i < numInputs; ++i)
		{
			cin >> arr[i];
		}
		bubbleSort (arr, numInputs);
		for (int i = 0; i < numInputs; ++i)
		{
			cout << arr[i] << endl;
		}
		printf("\n");

	}while (numInputs);

	return 0;
}