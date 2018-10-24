#include <iostream>
#include <string>

using namespace std;

void collision (string* num1, string* num2, int* number1, int* number2) {
	for (int index = num1->length()-1, index2 = num2->length()-1; index >= 0 && index2 >= 0; index--, index2--) {

		if (num1->at(index) > num2->at(index2)) {
			num2->at(index2) = 'x';
		}
		else if (num1->at(index) < num2->at(index2)) {
			num1->at(index) = 'x';
		}
	}
}

string removeX (string* num) {
	string concatenate;
	int index = 0;
	for (int i = 0; i < num->length(); ++i) {
		if (num->at(i) == 'x') {
			index++;
		}
	}
	if (index == num->length()) return "YODA";

	for (int i = 0; i < num->length(); ++i)
	{
		if (num->at(i) != 'x')
		{
			concatenate += num->at(i);
		}
	}
	return concatenate;
}


int main(int argc, char const *argv[])
{
	string num1, num2;
	cin >> num1	>> num2;
	int one, two;

	collision (&num1, &num2, &one, &two);
	num1 = removeX (&num1);
	num2 = removeX (&num2);
	if (num1 == "YODA") {
		cout << num1 << endl;
	}else {
		cout << stoi(num1) << endl;
	}
	if (num2 == "YODA") {
		cout << num2 << endl;
	}else {
		cout << stoi(num2) << endl;
	}
	return 0;
}

