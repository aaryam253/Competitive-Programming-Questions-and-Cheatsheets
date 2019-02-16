#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include <vector>
#include <queue>

#define MAX 16000

int bubbleSort (int[], int);
int insertionSort (int[], int);
int selectionSort (int[], int);
int enhancedBubble (int[], int);
int shakerSort(int[], int);
int insertionSortV2(int[],int);
void merge (int [], int [], int [], int , int );
int mergeSort (int [], int );
int partition(int *arr, int i, int j);
int quickSort (int *arr, int lowestIndex, int highestIndex);
int countingSort (int* arr, int n, int max);
void countSort(int arr[], int n, int exp);
int radixsort(int arr[], int n, int m);
void countingSort_2 (int* arr, int n, int exp);
int radixSort_2 (int* arr, int size, int biggest);
int quickSort_rand (int *arr, int lowestIndex, int highestIndex);
int partition_random(int *arr, int i, int j);
int enhanced_enhanced_Bubble (int arr[], int n);


using namespace std;


int main () {
    int choice;
    int arr1[1000], arr2[2000], arr4[4000], arr8[8000], arr16[16000];
    
    int arr_t[16000] = {0};
    
    
    printf("1: bubblesort\n2: insertion sort\n3: selection sort\n4: Enhanced bubblesort\n5: Shaker sort\n6: Insertion sort v2\n7: Merge sort\n8: Quick Sort\n9: Random quick sort\n10: Counting sort\n11: Radix sort\n12: Radix sort (Bucket's ver)\n13: Enhanced enhanced bubblesort (Aaryam's ver)\n");
    
    printf("What sort you want?: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Bubble sort selected\n");
            printf("size 1000 : %d \n", bubbleSort(arr1, 1000));
            printf("size 2000 : %d \n", bubbleSort(arr2, 2000));
            printf("size 4000 : %d \n", bubbleSort(arr4, 4000));
            printf("size 8000 : %d \n", bubbleSort(arr8, 8000));
            printf("size 16000 : %d \n", bubbleSort(arr16, 16000));
            printf("-----Best case: O(n), worst case: O(n^2)-----\n");
            break;
        case 2:
            printf("Insertion sort selected\n");
            printf("size 1000 : %d \n", insertionSort(arr1, 1000));
            printf("size 2000 : %d \n", insertionSort(arr2, 2000));
            printf("size 4000 : %d \n", insertionSort(arr4, 4000));
            printf("size 8000 : %d \n", insertionSort(arr8, 8000));
            printf("size 16000 : %d \n", insertionSort(arr16, 16000));
            printf("-----Best case: O(n), worst case: O(n^2)-----\n");
            break;
        case 3:
            printf("Selection sort selected\n");
            printf("size 1000 : %d \n", selectionSort(arr1, 1000));
            printf("size 2000 : %d \n", selectionSort(arr2, 2000));
            printf("size 4000 : %d \n", selectionSort(arr4, 4000));
            printf("size 8000 : %d \n", selectionSort(arr8, 8000));
            printf("size 16000 : %d \n", selectionSort(arr16, 16000));
            printf("-----Best case: O(n^2), worst case: O(n^2)-----\n");
            break;
        case 4:
            printf("Bubble sort selected\n");
            printf("size 1000 : %d \n", enhancedBubble(arr1, 1000));
            printf("size 2000 : %d \n", enhancedBubble(arr2, 2000));
            printf("size 4000 : %d \n", enhancedBubble(arr4, 4000));
            printf("size 8000 : %d \n", enhancedBubble(arr8, 8000));
            printf("size 16000 : %d \n", enhancedBubble(arr16, 16000));
            printf("-----Best case: O(n), worst case: O(n^2)-----\n");
            break;
        case 5:
            printf("Shaker sort selected\n");
            printf("size 1000 : %d \n", shakerSort(arr1, 1000));
            printf("size 2000 : %d \n", shakerSort(arr2, 2000));
            printf("size 4000 : %d \n", shakerSort(arr4, 4000));
            printf("size 8000 : %d \n", shakerSort(arr8, 8000));
            printf("size 16000 : %d \n", shakerSort(arr16, 16000));
            printf("-----Best case: O(n), worst case: O(n^2)-----\n");
            break;
        case 6:
            printf("Insertion sort V2 selected\n");
            printf("size 1000 : %d \n", selectionSort(arr1, 1000));
            printf("size 2000 : %d \n", selectionSort(arr2, 2000));
            printf("size 4000 : %d \n", selectionSort(arr4, 4000));
            printf("size 8000 : %d \n", selectionSort(arr8, 8000));
            printf("size 16000 : %d \n", selectionSort(arr16, 16000));
            printf("-----Best case: O(n), worst case: O(n^2)-----\n");
            break;
        case 7:
            printf("Merge sort selected\n");
            printf("size 1000 : %d \n", mergeSort(arr4, 1000));
            printf("-----O(n log(n))-----\n");
            break;
        case 8:
            printf("Quick sort selected\n");
            printf("size 1000 : %d \n", quickSort(arr1, 0, 999));
            printf("size 2000 : %d \n", quickSort(arr2, 0,1999));
            printf("size 4000 : %d \n", quickSort(arr4, 0,3999));
            printf("size 8000 : %d \n", quickSort(arr8, 0,7999));
            printf("size 16000 : %d \n", quickSort(arr16, 0,1599));
            printf("-----Best case: O(n log(n)), worst case: O(n^2)-----\n");
            break;
        case 9:
            printf("Random Quick sort selected\n");
            printf("size 1000 : %d \n", quickSort_rand(arr1, 0, 999));
            printf("size 2000 : %d \n", quickSort_rand(arr2, 0,1999));
            printf("size 4000 : %d \n", quickSort_rand(arr4, 0,3999));
            printf("size 8000 : %d \n", quickSort_rand(arr8, 0,7999));
            printf("size 16000 : %d \n", quickSort_rand(arr16, 0,1599));
            printf("-----Best case: O(n log(n)), worst case: O(n^2)-----\n");
            break;
        case 10:
            printf("Counting sort selected\n");
            printf("size 16000 : %d \n", countingSort(arr_t, 16000, 0));
            printf("-----Best case: O(n), worst case: O(n^2)-----\n");
            break;
        case 11:
            printf("Radix sort selected\n");
            printf("size 16000 : %d \n", radixsort(arr_t, 16000, 0));
            printf("-----O(n)-----\n");
            break;
        case 12:
            printf("Radix sort (Bucket's ver) selected\n");
            printf("size 16000 : %d \n", radixSort_2(arr_t, 16000, 0));
            printf("-----O(n)-----\n");
            break;
        case 13:
            printf("Enhanced enhanced Bubble sort selected\n");
            printf("size 1000 : %d \n", enhanced_enhanced_Bubble(arr1, 1000));
            printf("size 2000 : %d \n", enhanced_enhanced_Bubble(arr2, 2000));
            printf("size 4000 : %d \n", enhanced_enhanced_Bubble(arr4, 4000));
            printf("size 8000 : %d \n", enhanced_enhanced_Bubble(arr8, 8000));
            printf("size 16000 : %d \n", enhanced_enhanced_Bubble(arr16, 16000));
            printf("-----Best case: O(n), worst case: O(n^2)-----\n");
            break;
        default:
            printf("Bubble sort selected\n");
            printf("size 1000 : %d \n", bubbleSort(arr1, 1000));
            printf("size 2000 : %d \n", bubbleSort(arr2, 2000));
            printf("size 4000 : %d \n", bubbleSort(arr4, 4000));
            printf("size 8000 : %d \n", bubbleSort(arr8, 8000));
            printf("size 16000 : %d \n", bubbleSort(arr16, 16000));
            printf("-----Best case: O(n), worst case: O(n^2)-----\n");
    }
    
    return 0;
}


/**
 Pros: Good to use for small arrays
 */

int bubbleSort (int arr[], int n) {
    clock_t start, finish;
    
    start = clock();
    for (int c = 0; c < n; c++) {
        for (int d = 0; d < (n-c-1); d++) {
            if (arr[d] > arr[d+1]) {
                swap(arr[d], arr[d+1]);
            }
        }
    }
    
    finish = clock();
    
    return (int)((finish - start));
}


/**
 Pros: Good to use for small arrays
 */

int insertionSort (int arr[], int n) {
    int d, c, t;
    clock_t start, finish;
    start = clock();
    for (c = 0; c < n; c++){
        d = c;
        while (d > 0 && arr[d] < arr[d-1]){
            swap(arr[d], arr[d+1]);
            d--;
        }
    }
    finish = clock();
    
    return (int)(finish - start);
}


/**
 Pros: Good to use for small arrays
 */

int selectionSort (int arr[], int n) {
    int i, smallestIndex, t;
    clock_t start, finish;
    
    start = clock();
    for (i = 0; i < n - 1; i++) {
        smallestIndex = i;
        int j;
        for (j = i; j < n; j++){
            // Searches for the position for the smallest element in the array
            if (arr[smallestIndex] > arr[j]){
                smallestIndex = j;
            }
        }
        // Swaps the smallest element with the element (i) you're currently on
        swap(arr[i], arr[smallestIndex]);
    }
    
    finish = clock();
    
    return (int)(finish - start);
}

int enhancedBubble (int arr[], int n) {
    int i, isNotSorted = 1, t;
    clock_t start, finish;
    
    start = clock();
    for (i = 0; (i < n - 1) && isNotSorted; i++){    // IsNotSorted will cause the loop to break if there is no swaps occurring.
        int j;
        isNotSorted = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                isNotSorted = 1;
            }
        }
    }
    
    finish = clock();
    
    return (int)(finish - start);
}

int enhanced_enhanced_Bubble (int arr[], int n) {
    int isNotSorted = 1;
    int lastSwap = n, temp;
    
    clock_t start, finish;
    
    start = clock();
    
    //boolean variable to check for swapping
    while (isNotSorted) {
        isNotSorted = 0;
        //only iterates to the last known location of a swap, doesn't bother checking the rest as it'll
        //already be sorted
        for (int j = 0; j < lastSwap; j++) {
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                temp = j;
                isNotSorted = 1;
            }
        }
        lastSwap = temp;
    }
    
    finish = clock();
    return (int)(finish - start);
}


int shakerSort(int array[], int size) {
    clock_t start, finish;
    int swapped = 0;
    start = clock();
    for (int i = 0; i < size/2; i++) {
        swapped = 0;
        for (int j = i; j < size - i - 1; j++) { //one way
            if (array[j] < array[j+1]) {
                swap(array[j], array[j+1]);
                swapped = 1;
            }
        }
        for (int j = size - 2 - i; j > i; j--) { //and back
            if (array[j] > array[j-1]) {
                swap(array[j], array[j+1]);
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
    finish = clock();
    
    return (int)(finish - start);
}

int insertionSortV2(int arr[],int size){
    clock_t start,finish;
    int i,j,temp;
    
    start = clock();
    for (i=0;i<size;i++){
        temp = arr[i];
        j = i-1;
        while ((j>=0) && (temp<arr[j])){
            arr[j+1] = arr[j];        // Only does one assignment each time it looks for the space for the element.
            j--;
        }
        arr[j+1] = temp;             // Once it finds the location then assign. FASTER than doing swapping as swapping does 3 actions each time.
    }
    finish = clock();
    return (int)(finish-start);
}



/**
 Pros: Constant O(N log N)
 Cons: Not memory efficient and requires O(N) space
 */

// Due to the memory usage of this algo, it cannot be timed without causing a crash :(
int mergeSort (int arr[], int size) {
    clock_t start, finish;
    start = clock();
    int arrL[1000] = {0};
    int arrR[1000] = {0};
    int pivot = size/2;
    int i, d;
    if (size > 1) {
        
        for (i = 0; i < pivot; i++) {
            // Copy to left
            arrL[i] = arr[i];
        }
        i = 0;
        for (d = pivot; d < size; d++) {
            // Copy to right
            arrR[i++] = arr[d];
        }
        mergeSort (arrL, pivot);
        mergeSort (arrR, i); // I used 'i' because it was post incremented earlier on
    }
    merge (arrL, arrR, arr, pivot, i);
    finish = clock();
    return (int)(finish-start);
}


void merge (int arrL[], int arrR[], int arr[], int left_size, int right_size) {
    int i = 0, j = 0, index = 0;
    while (i < left_size && j < right_size) {
        // Insert in increasing order
        if (arrL[i] > arrR[j]) {
            arr[index++] = arrR[j++];
        }
        
        if (arrL[i] < arrR[j]) {
            arr[index++] = arrL[i++];
        }
        // When they are both equal
        if (arrL[i] == arrR[j]) {
            arr[index++] = arrR[j++];
            arr[index++] = arrL[i++];
        }
    }
    // Settle the left overs
    while (left_size - i) {
        arr[index++] = arrL[i++];
    }
    while (right_size - j) {
        arr[index++] = arrR[j++];
    }
}


/**
 Pros: best case - O(N log N), worst case - O(n^2)
 */


int partition(int *arr, int i, int j) {
    int p = arr[i]; // Pivot (fixed pivot)
    int m = i; // S1 and S2 are initially empty, so potential pivot just dump it at the lowest index
    for (int k = i+1 ; k <= j; ++k)
    {
        if (arr[k] < p) {
            m++; // Increase and bring up the potential pivot point
            swap (arr[k], arr[m]); // swap that higher than p value with the potential pivot
        }
    }
    swap (arr[i], arr[m]); // Eventually swap the potential pivot point with the original pivot at i.
    return m; // Mid point
}

int quickSort (int *arr, int lowestIndex, int highestIndex) {
    clock_t start, finish;
    start = clock();
    
    if (lowestIndex < highestIndex) {
        int pivot = partition(arr, lowestIndex, highestIndex); // partion and give me the pivot
        quickSort (arr, lowestIndex, pivot-1); // Sort everything below the pivot
        quickSort (arr, pivot+1, highestIndex); // sort everything above the pivot
        // Note that this excludes the pivot
    }
    finish = clock();
    return (int)(finish-start);
}



/**
 Pros: O(N log N)
 Its cool cause its random
 */

int partition_random(int *arr, int i, int j) {
    int r = i + rand()%(j-i+1);
    swap (arr[i], arr[r]); // Swap i with a random pivot
    
    int p = arr[i];
    int m = i; // S1 and S2 are initially empty, so potential pivot just dump it at the lowest index
    for (int k = i+1 ; k <= j; ++k)
    {
        if (arr[k] < p) {
            m++; // Increase and bring up the potential pivot point
            swap (arr[k], arr[m]); // swap that higher than p value with the potential pivot
        }
    }
    return m; // Returns midpoint
}



int quickSort_rand (int *arr, int lowestIndex, int highestIndex) {
    clock_t start, finish;
    start = clock();
    
    if (lowestIndex < highestIndex) {
        int pivot = partition_random(arr, lowestIndex, highestIndex); // partion and give me the pivot
        quickSort (arr, lowestIndex, pivot-1); // Sort everything below the pivot
        quickSort (arr, pivot+1, highestIndex); // sort everything above the pivot
        // Note that this excludes the pivot
    }
    finish = clock();
    return (int)(finish-start);
}




/* -------------------------------- Beginning of non compare type sorting techniques -------------------------------- */

/**
 Pros: Close to O(N)
 Cons: Not memory efficient, need to know largest number and can only be done for +ve numbers
 Time complexity: O(n + k) k number of unique elements
 */

int countingSort(int arr[], int size, int range) {
    clock_t start, finish;
    start = clock();
    
    // The output integer array that will have sorted arr
    int output[size];
    
    // Create a count array to store count of inidividual
    // integers and initialize count array as 0
    
    // means the range is only up to 1000 MAKE SURE TO CHANGE THIS AMOUNT TO WHAT YOU NEED
    int count[1000 + 1] = {};
    int i;
    
    // Store count of each number
    for(i = 0; i < size; ++i)
        count[arr[i]]++;
    
    // Change count[i] so that count[i] now contains actual
    // position of this integers in output array
    for (i = 1; i <= range; ++i)
        count[i] += count[i-1];
    
    // Build the output integer array
    for (i = 0; i < size; ++i)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }
    
    // To make it stable
    for (i = size-1; i>=0; --i)
    {
        output[count[arr[i]]] = arr[i];
        --count[arr[i]];
    }
    
    // Copy the output array to arr, so that arr now
    // contains the sorted integers
    for (i = 0; i < size; ++i)
        arr[i] = output[i];
    
    finish = clock();
    return (int)(finish-start);
}




void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};
    
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
    
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
    
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

/**
 Time complexity: O(dN) d is the max number of digits - so worst case can potentially be O(N^2)
 Radixsort uses countSort as an aux sort technique
 */
int radixsort(int arr[], int n, int m)
{
    clock_t start, finish;
    start = clock();
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
    
    finish = clock();
    return (int)(finish-start);
}



// Radix sort, Bucket's version, using FIFO

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

int radixSort_2 (int* arr, int size, int biggest) {
    clock_t start, finish;
    start = clock();
    for (int exp = 1; biggest/exp > 0; exp *= 10) {
        countingSort_2 (arr, size, exp);
        
    }
    finish = clock();
    return (int)(finish-start);
}


// Heap sort
// Uses vectors for this one

void maxHeapify (int index, int maxSize, vector<int> *heap) {
    // Compare childs
    if (2*index+1 < heap->size() && 2*index+2 < maxSize) {
        // Both child exist
        if (heap->at(2*index+1) > heap->at(2*index+2)) {
            // Left child larger than right child
            if (heap->at(2*index+1) > heap->at(index)) {
                int t = heap->at(index);
                heap->at(index) = heap->at(2*index+1);
                heap->at(2*index+1) = t;
                maxHeapify(2*index+1, maxSize, heap);
            }
        }else {
            // Left child smaller or equals to right child
            if (heap->at(2*index+2) > heap->at(index)) {
                int t = heap->at(index);
                heap->at(index) = heap->at(2*index+2);
                heap->at(2*index+2) = t;
                maxHeapify(2*index+2, maxSize, heap);
            }
        }
    }
    else if (2*index+1 < maxSize) {
        // Left child exist
        if (heap->at(2*index+1) > heap->at(index)) {
            int t = heap->at(index);
            heap->at(index) = heap->at(2*index+1);
            heap->at(2*index+1) = t;
            maxHeapify(2*index+1, maxSize, heap);
        }
    }
    else if (2*index+2 < maxSize) {
        // Right child exist
        if (heap->at(2*index+2) > heap->at(index)) {
            int t = heap->at(index);
            heap->at(index) = heap->at(2*index+2);
            heap->at(2*index+2) = t;
            maxHeapify(2*index+2, maxSize, heap);
        }
    }
    else {
        // No child left
        return;
    }
    
}

void buildHeap (vector<int>* myVector) {
    for (int i = myVector->size()/2; i >= 0; i--) {
        maxHeapify(i, myVector->size(), myVector); // uses maxHeapify, basically start from the first half of the array and heapify from there
        // O(N)
    }
}

void heap_sort (vector<int> *myVector) {
    buildHeap(myVector);
    for (int i = 0; i < myVector->size() ; i++) {
        int t = myVector->at(0);
        myVector->at(0) = myVector->at(myVector->size()-1 - i);
        myVector->at(myVector->size()-1 - i) = t;
        maxHeapify(0, myVector->size()-1 - i, myVector);
    }
}



// Counting sort with bucket
// This function sorts a string with its index in order

vector<pair<char, int>> countingSort (string input, int n, int max) {
    queue<pair<char, int>> myqueue[128];
    vector<pair<char, int>> myvec;
    for (int i = 0; i < n; ++i)
    {
        myqueue[input[i]].push(make_pair(input[i], i));
    }
    for (int i = 0; i <= max; ++i)
    {
        // Empty the bucket
        while (!myqueue[i].empty()) {
            myvec.push_back(myqueue[i].back());
            myqueue[i].pop();
        }
    }
    
    return myvec;
}


/**
 
 Some extra notes:
 1. In-place sorting algorithms require no extra space/ temp arrays unlike merge sort.
 2. A sorting algorithm is called stable if the relative order of elements with the same key value is preserved by the algorithm after sorting is performed.
 this usually affects when there are two items of the same value but different keys
 */


/*
 
 For some quick thinking tips:
 
 (num comparisons)***** - hardest
 1. Bubble sort num comparisons = (n-1)(n/2) iff no breaks else find out at which pass it broke.
 2. Selection sort = n + n-1 + n-2 + ... + 1
 3. Insertion sort (with break;)
 Steps:
 1. Identify first one from the left that needs to swap,
 2. If (number does not shift to back most) Count number of indexes it needs to travel + 1
 3. Else count number of indexes to the last one
 4. The rest except (0th index) give it 1 comparison
 
 
 
 (num swaps)
 1. If an array is ordered, zero swaps will be made for all comparison based sorting algos
 2. As for others, its best to analyse one by one.
 
 
 (content of array after n passes)
 1. Bubble sort - have to manually trace
 2. Selection sort - draw a line at the last index to be sorted, trace from start to there (swap necessarily)
 3. Insertion sort - draw a line at the last index to be sorted, all those before this line will be sorted properly
 
 
 (num possible pivots on first pass - quicksort)
 Look at each number carefully, pivots can only have left side all smaller than itself and right side all bigger or equals to itself.
 
 
 */
