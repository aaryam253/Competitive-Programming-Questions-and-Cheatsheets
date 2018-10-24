#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	string input;
	cin >> input;
	int count_whitespace = 0, count_lower = 0, count_upper = 0, count_symbol = 0;

	for (int i = 0; i < input.size(); ++i)
	{
		if (input.at(i) > 64 && input.at(i) < 91) count_upper++;
		else if (input.at(i) > 96 && input.at(i) < 123) count_lower++;
		else if (input.at(i) == '_') count_whitespace++;
		else count_symbol++;
	}

	double percentage_whitespace = (double)count_whitespace/input.size();
	double percentage_lower = (double)count_lower/input.size();
	double percentage_upper = (double)count_upper/input.size();
	double percentage_symbol = (double)count_symbol/input.size();

	printf("%.16lf\n", percentage_whitespace);
	printf("%.16lf\n", percentage_lower);
	printf("%.16lf\n", percentage_upper);
	printf("%.16lf\n", percentage_symbol);

	return 0;
}