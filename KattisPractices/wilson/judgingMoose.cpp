#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
	int left, right, result, odd = 0;

	cin >> left;
	cin >> right;

	if (left > right) {
		result = left * 2;
		odd = 1;
	}

	if (left == right) {
		result = left * 2;
	}

	if (left == right && left == 0) {
		result = 0;
		odd = -1;
	}

	if (left < right) {
		result = right * 2;
		odd = 1;
	}

	if (odd == 1) {
		cout << "Odd ";
		cout << result << endl;

	}else if (odd == 0){
		cout << "Even ";
		cout << result << endl;
	}else {
		cout << "Not a moose" << endl;
	}


	return 0;
}