#include <iostream>

using namespace std;

int num_bottles (int num_calories);


int main(int argc, char const *argv[])
{
	int num_calories;
	int num_cases;
	cin >> num_cases;

	for (int i = 0; i < num_cases; i++) {
		cin >> num_calories;
		cout << num_bottles (num_calories) << endl;
	}

	return 0;
}


int num_bottles (int num_calories) {
	float bottles = num_calories/400.0;
	int bottles_int = bottles;

	if (bottles - bottles_int > 0) {
		bottles_int++;
	}
	return bottles_int;
}