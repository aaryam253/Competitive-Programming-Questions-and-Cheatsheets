#include <iostream>

using namespace std;


void bubbleSort (string arr[], int n) {
	for (int c = 0; c < n; c++) {
		for (int d = 0; d < (n-c-1); d++) {
			string t_1; 
			string t_2;

			for (int i = 0; i < arr[d].length(); ++i)
			{
				t_1 += tolower(arr[d].at(i));
			}
			for (int i = 0; i < arr[d+1].length(); ++i)
			{
				t_2 += tolower(arr[d+1].at(i));
			}

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
	int r, c;

	do {
		string arr[15];
		char arr_t[15][15];
		scanf ("%d %d", &r, &c);
		for (int i = 0; i < r; ++i)
		{
			for (int d = 0; d < c; ++d)
			{
				cin >> arr_t[d][i];
			}
		}

		for (int i = 0; i < c; ++i)
		{
			string str(arr_t[i]);
			arr[i] = str;
		}

		bubbleSort (arr, c);
		for (int i = 0; i < r; ++i)
		{
			for (int d = 0; d < c; ++d)
			{
				cout << arr[d][i];
			}
			cout << endl;
		}
		cout << endl;
	}while (r != 0 && c != 0);
	
	return 0;
}