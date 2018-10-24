#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{

	int num;
	string magic = "Abracadabra";

	cin >> num;

	for (int i = 0; i < num; i++) {
		cout << (i + 1) << " " << magic << endl;
	}

	
	return 0;
}