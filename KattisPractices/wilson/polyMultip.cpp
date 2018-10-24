#include <iostream>
#define MAX 100000

using namespace std;


int calculate (int* poly1, int* poly2, int* resultPoly, int deg1, int deg2) {
	int deg3 = deg1 + deg2;

	for (int i = 0; i <= deg1; ++i)
	{
		for (int d = 0; d <= deg2 ; ++d)
		{
			resultPoly[i+d] += poly1[i]*poly2[d];
		}

	}

	return deg3;
}

void clearArray (int* resultPoly, int deg) {
	for (int i = 0; i <= deg; ++i)
	{
		resultPoly[i] = 0;
	}
} 


int main(int argc, char const *argv[])
{
	int numTestCase, deg1, deg2, poly1[MAX], poly2[MAX], resultPoly[MAX];

	cin >> numTestCase;

	for (int i = 0; i < numTestCase; ++i)
	{
		int d;
		cin >> deg1;
		for (d = 0; d <= deg1; d++) {
			cin >> poly1[d];
		}
		cin >> deg2;
		for (d = 0; d <= deg2; d++) {
			cin >> poly2[d];
		}
		int deg3 = calculate (poly1, poly2, resultPoly, deg1, deg2);
		cout << deg3 << endl;
		for (int i = 0; i <= deg3; ++i)
		{
			cout << resultPoly[i] << " ";
		}
		cout << endl;
		clearArray (resultPoly, deg3);
	}
	
	return 0;
}