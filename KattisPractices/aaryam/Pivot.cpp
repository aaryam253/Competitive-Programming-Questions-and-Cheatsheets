#include <iostream>
using namespace std;

int main() {
    int elements, pivots = 0;
    cin >> elements;
    //three arrays will be used to reduce the time complexity, one which contains the elements, left will contain the maximum elements to the left corresponding to each element, right will contain the minimum elements to the right corresponding to each element
    int arr[elements], left[elements], right[elements];
 
    int maximum; cin >> maximum;
    left[0] = maximum; arr[0] = maximum;
    
    //finding the maximum element for each element in arr[], and storing them in left[]
    int element;
    for (int i = 1; i < elements; i++){
        cin >> element;
        if(element > maximum) {
            maximum = element;
        }
        left[i] = maximum;
        arr[i] = element;
    }
    
    int minimum = arr[elements-1]; right[elements-1] = minimum;
    
    //finding the minimum element for each element in arr[], and storing them in right[]
    for (int i = elements - 2; i >= 0; i--) {
        if(arr[i] < minimum) {
            minimum = arr[i];
        }
        right[i] = minimum;
    }
    
    //findind the number of pivots depending on whether value of the pivot is greater than the max to its left, and less than the mim to its right
    for(int i = 0; i < elements; i++) {
        if(left[i] <= arr[i] && right[i] >= arr[i])
            pivots++;
    }
    
    cout << pivots << endl;
    return 0;
}
