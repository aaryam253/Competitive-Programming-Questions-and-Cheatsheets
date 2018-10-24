#include <iostream>
#include <vector>


using namespace std;


int main(int argc, char const *argv[])
{
	std::vector<int> v;
	std::vector<string> v_string;

	int num;
	scanf ("%d", &num);
	// Do the triple first
	for (int d = 3; d >= 1; --d)
	{
		for (int i = 20; i >= 1; --i)
		{
			string type;
			switch (d) {
				case 3:
				type = "triple";
				break;
				case 2: 
				type = "double";
				break;
				case 1: 
				type = "single";
			}
			while (num /(d*i)) {
				v.push_back(i);
				v_string.push_back(type);
				num -= (d*i);
				if (v.size() > 3) {
					printf("impossible\n");
					return 0;

				}

			}
		}
	}

	if (num) {
		printf("impossible\n");
		return 0;
	}

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v_string[i] << " " << v[i] << endl;
	}
	return 0;
}