#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
	int arr[100] = {0};

	int numRooms, numBooked;
	cin >> numRooms >> numBooked;

	for (int i = 0; i < numBooked; ++i)
	{
		int num;
		cin >> num;
		arr[num-1] = 1;
	}


	for (int i = 0; i < numRooms; ++i)
	{
		if (!arr[i]) {
			cout << i+1 << endl;
			return 0;
		}
	}

	cout << "too late" << endl;

	return 0;
}