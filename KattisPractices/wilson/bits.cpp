#include <iostream>
#include <string>
#include <bitset>
#define MAX 31

using namespace std;


int count_ones (string input);
int count_max_ones (string input);

int main(int argc, char const *argv[])
{
	int num_cases;
	string input;
	char str[MAX];
	cin >> num_cases;

	for (int i = 0; i < num_cases; i++) {
		cin >> input;

		cout << count_max_ones(input) << endl;
	}
	
	return 0;
}


int count_ones (string input) {
	int index = 0, count = 0;
	for (auto it = input.begin() ; it < input.end(); ++it, ++index) {
		if (input[index] == '1') {
			count++;
		}
	}

	return count;
}


int count_max_ones (string input) {
	int max = 0, index = 0;
	string stash;
	for (auto it = input.begin() ; it < input.end(); ++it, ++index) {
		stash += input[index];
		int num = stoi (stash), internal;
		internal = count_ones(bitset<MAX>(num).to_string());
		if (internal > max) {
			max = internal;
		}

	}
	return max;
}