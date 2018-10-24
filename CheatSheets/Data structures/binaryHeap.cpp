// Impt notes: 
/*
1. i left = 2i+1
2. i right = 2i+2
3. i parent = (i-1)/2 (floored)
*/


class binHeap {
private:
    vector<int> heap;
    
    
    // Recursive
    void maxHeapify (int index, int maxSize) {
        // Compare childs
        if (2*index+1 < heap.size() && 2*index+2 < maxSize) {
            // Both child exist
            if (heap[2*index+1] > heap[2*index+2]) {
                // Left child larger than right child
                if (heap[2*index+1] > heap[index]) {
                    swap(heap[index], heap[2*index+1]);
                    maxHeapify(2*index+1, maxSize);
                }
            }else {
                // Left child smaller or equals to right child
                if (heap[2*index+2] > heap[index]) {
                    swap(heap[index], heap[2*index+2]);
                    maxHeapify(2*index+2, maxSize);
                }
            }
        }
        else if (2*index+1 < maxSize) {
            // Left child exist
            if (heap[2*index+1] > heap[index]) {
                swap(heap[index], heap[2*index+1]);
                maxHeapify(2*index+1, maxSize);
            }
        }
        // This is redundant, left child cannot exist when right child does not exist 
        else if (2*index+2 < maxSize) {
            // Right child exist
            if (heap[2*index+2] > heap[index]) {
                swap(heap[index], heap[2*index+2]);
                maxHeapify(2*index+2, maxSize);
            }
        }
        else {
            // No child left
            return;
        }
        
    }
    void shiftDown (int index) {
        // Compare parent
        if (heap[index] > heap[(index-1)/2]) {
            // more than parent
            swap(heap[index], heap[(index-1)/2]);
            shiftDown((index-1)/2);
        }else {
            return;
        }
    }
    
public:
    binHeap(vector<int> myVector) {
        buildHeap(myVector);
    }
    
    binHeap() {}
    
    
    
    void insert (int value) {
        heap.push_back(value);
        shiftDown(heap.size() - 1);
    }
    
    int top () {
        if (heap.empty()) return -1;
        return heap[0];
    }
    
    void removeTop () {
        swap(heap[0], heap[heap.size() - 1]);
        heap.erase(--heap.end());
        if (heap.empty()) return;
        maxHeapify(0, heap.size());
    }
    
    void printVector () {
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
    
    void buildHeap_slow (vector<int> myVector) {
        for (auto i = myVector.begin(); i != myVector.end(); i++) {
            insert(*i); // Insert and fixTree
            // O(NLogN)
        }
    }
    
    void buildHeap (vector<int> myVector) {
        heap = myVector;
        for (int i = heap.size()/2; i >= 0; i--) {
            maxHeapify(i, heap.size()); // uses maxHeapify, basically start from the first half of the array and heapify from there
            // O(N)
        }
    }
    /*
        1. Remove all the leaf nodes
        2. start from the last parent, bubble down/ maxHeapify 
        3. Do until the first element (index = 0)
    */
    
    void heap_sort (vector<int> *myVector) {
        heap = *myVector;
        buildHeap(heap);
        for (int i = 0; i < myVector->size() ; i++) {
            swap(heap[0], heap[heap.size()-1 - i]);
            maxHeapify(0, heap.size()-1 - i);
        }
        
        *myVector = heap;
    }

    // DFS
    void find_elements_above (int k, int index) {
        if (index >= heap.size()) return; // So it does not traverse out of array
        
        cout << heap[index] << endl;
        
        if (heap[2*index+1] > k) find_elements_above(k, 2*index+1);
        if (heap[2*index+2] > k) find_elements_above(k, 2*index+2);
    }
    
};

// Some notes on binary heap
/*
    1. Vertices less than a given vertice basically just means all smaller nodes in the whole tree. 
    2. Min num comparisons made in buidHeap O(n) is just N elements - 1
    3. Worst case insertion: Log(N), N = height of tree
    4. Best case insertion: O(1)
    5. HeapSort speed is O(NlogN)
    6. Max number of comparisons in a binHeap = numSubTrees * numComparisons(indicated below) + 1
        subtree:
                            p           p
                        3: / \      2: /
                          c   c       c
        n elements: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
                    --------------------------------------------
       comparisons: 1 3 4 6 7 7 8 11 14 15 16 18 20 21 22 24 25 27 28 30
       
    7. Max swaps recorded so far for buildHeap O(N)
        n elements: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
                    --------------------------------------------
             swaps: 0 1 1 3 3 4 4 7 7  8  8 10 10 11 11 13 14 16
*/
