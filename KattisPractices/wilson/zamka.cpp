#include <iostream>

using namespace std;

int getSum (int input) {
	int total = 0;
	while(input) {
		total += input%10;
		input/=10;
	}
	return total;
}


int main(int argc, char const *argv[])
{
	int L, D, X;
	cin >> D >> L >> X;
	// Starts from the bottom range first
	for (int i = D; i <= L; ++i)
	{
		if (getSum(i) == X) {
			cout << i << endl;
			break;
		}
	}
	// Then start from the higher range
	for (int i = L; i >= D; --i)
	{
		if (getSum(i) == X) {
			cout << i << endl;
			break;
		}
	}

	return 0;
}