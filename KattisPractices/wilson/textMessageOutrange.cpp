#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;


void countingSort_2 (int* arr, int n, int exp) {
	list<int> count[10]; // There exists only 10 possible lists from 0 - 9
	// FIFO
	// First in...
	for (int i = 0; i < n; ++i)
	{
		int num = (arr[i]/exp) % 10;
		count[num].push_back(arr[i]);
	}
	int index = 0;
	// First out
	for (int i = 0; i <= 9; ++i)
	{
		while (count[i].size()) {
			arr[index++] = count[i].front(); // Throw it back to the main array
			count[i].pop_front();
		}
	}
}

void radixSort_2 (int* arr, int size, int biggest) {
	for (int exp = 1; biggest/exp > 0; exp *= 10) {
		countingSort_2 (arr, size, exp);

	}
}




int main(int argc, char const *argv[])
{
	int N, P, K, L;
	scanf ("%d", &N);
	for (int c = 0; c < N; ++c)
	{
		int arr[1000*1000] = {0};
		int largestNum = 0;

		scanf ("%d %d %d", &P, &K, &L);
		for (int i = 0; i < L; ++i)
		{
			scanf("%d", &arr[i]);
			if (arr[i] > largestNum) largestNum = arr[i];
		}

		radixSort_2 (arr, L, largestNum);
		unsigned long long count = 0; // This gets me everytime. Sometimes numbers can go out of int range. As practice, whenever we see large numbers just use unsigned long long
		int index = L-1;
		for (int i = 1; i <= P; ++i)
		{
			for (int d = 0; d < K && index >= 0; ++d)
			{
				count += (arr[index--] * i);
			}
		}

		printf("Case #%d: %llu\n", c+1, count);
	}
	


	return 0;
}