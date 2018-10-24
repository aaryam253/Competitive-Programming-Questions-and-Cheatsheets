#include <bits/stdc++.h>

using namespace std;


int isSorted_dec (string arr[], int size) {
	int i;

	for (i = 0; i< size - 1; i++) {
		if (arr[i] > arr[i+1]) {
			return 0;
		}
	}
	return 1;
}

int isSorted_inc (string arr[], int size) {
	int i;

	for (i = 0; i< size - 1; i++) {
		if (arr[i] < arr[i+1]) {
			return 0;
		}
	}
	return 1;
}



int main(int argc, char const *argv[])
{
	string arr[20];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}	

	if (isSorted_dec(arr, n)) {
		cout << "INCREASING" << endl;
		return 0;
	}

	if (isSorted_inc(arr, n)) {
		cout << "DECREASING" << endl;
		return 0;
	}

	cout << "NEITHER" << endl;

	return 0;
}