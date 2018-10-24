#include <iostream>
#include <string>
#include <list>


using namespace std;


class largeNumber{
public:
	string input;
	largeNumber() {
	}
	void increment() {
		input.at(input.length() - 1) += 1;
		for (int i = input.length() - 1; i >= 1; --i)
		{
			if (input.at(i) > '9') {
				input.at(i) = '0';
				input.at(i-1) += 1;
			}
		}
		// TODO: Implement carry to front and shift back when the first char is more than '9'
	}

	/*
	largeNumber operator+ (largeNumber other) {
		
	}
	*/

	bool operator< (largeNumber other) {
		if (other.input.length() == input.length()) {
			if (input < other.input) return true;
		}
		else if (input.length() < other.input.length()){
			return true;
		}
		return false;
	}

	bool operator== (largeNumber other) {
		if (other.input.length() == input.length()) {
			if (input == other.input) return true;
		}
		return false;
	}

	int getSum () {
		int sum = 0;
		for (int i = 0; i < input.length(); ++i)
		{
			if (!(input.at(i) < '0') && !(input.at(i) > '9'))
				sum += input.at(i) - '0';
		}
		return sum;
	}

private:
};



int main(int argc, char const *argv[])
{
	largeNumber number;
	largeNumber other;
	string input;	
	cin >> number.input;
	other.input = "999";

	//cout << getSum(input) << endl;
	while (number < other) {
		number.increment(); 
	}
	cout << number.getSum() << endl;

	return 0;
}