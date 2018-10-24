#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int arr[1001] = {0}, biggest = 0, smallest = 1000;
	int numBus;
	scanf ("%d", &numBus);
	for (int i = 0; i < numBus; ++i)
	{
		int num;
		scanf ("%d", &num);
		// Counting sort
		arr[num] = 1;
		if (num > biggest) biggest = num;
		if (num < smallest) smallest = num;
	}
	for (int i = smallest; i <= biggest; ++i)
	{
		int d = 0, flag = 0;
		if (arr[i]) {
			for (d = i+1; d <= biggest; ++d)
			{
				if (arr[d]) {
					flag++;
				}else {
					break;
				}
			}
			if (flag > 1) {
				printf("%d-%d ", i, d-1);
				i = d;
			}else {
				printf("%d ", i);
			}
		}
		
	}

	printf("\n");


	return 0;
}