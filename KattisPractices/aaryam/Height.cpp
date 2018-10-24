#include <bits/stdc++.h>
using namespace std;

int insertionSort(int arr[],int size, int *moves){
	int i,j,temp;
	
	for (i=0;i<size;i++){
		temp = arr[i];
		j = i-1;
		while ((j>=0) && (temp<arr[j])){
			arr[j+1] = arr[j];	
			(*moves)++;
			j--;
		}
		arr[j+1] = temp;
	}
}


int main (void) {
    int test_cases; cin >> test_cases;
    int answers[test_cases];
    
    for (int i = 1; i <= test_cases; i++) {
        cin >> i;
        int heights[20], moves = 0;
        for (int j = 0; j < 20; j++) {
            cin >> heights[j];
            insertionSort(heights, j+1, &moves);
        }
        answers[i - 1] = moves;
    }
    
    for (int i = 0; i < test_cases; i++) {
        cout << i + 1 << " " << answers[i] << endl;
    }
    return 0;
}
