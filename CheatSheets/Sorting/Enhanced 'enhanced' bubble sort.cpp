#include <bits/stdc++.h>
using namespace std;

int main() {
  int arr[10] = {8,4,5,3,7,12,11,6,19,1};
  bool isNotSorted = true;
  int lastSwap = 9, temp;
  
	clock_t start, finish;
	
	start = clock();	
  
  //boolean variable to check for swapping
	while (isNotSorted) {
		isNotSorted = false;
    //only iterates to the last known location of a swap, doesn't bother checking the rest as it'll 
    //already be sorted
		for (int j = 0; j < lastSwap; j++) {
			if (arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
				temp = j;
				isNotSorted = true;
			}
		}
		lastSwap = temp;
	}

	finish = clock();
	
	for (int i = 0; i < 10; i++) cout << arr[i] << endl;
	return 0;
  
}
