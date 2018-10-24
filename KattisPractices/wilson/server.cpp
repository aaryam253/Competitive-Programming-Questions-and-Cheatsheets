#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int tasks, T;
	cin >> tasks >> T;

	int c = tasks;
	while (c--) {
		int m;
		cin >> m;
		T -= m;
		if (T < 0){
			cout << tasks-c-1 << endl;
			return 0;
		}
	}

	cout << tasks << endl;
	
	return 0;
}
