// So far concept is similar, just pay attention to the sign changes in minHeapify and Shiftup 

class minbinHeap {
private:
    vector<int> heap;
    
    
    // Recursive
    void minHeapify (int index, int maxSize) {
        // Compare childs
        if (2*index+1 < heap.size() && 2*index+2 < maxSize) {
            // Both child exist
            if (heap[2*index+1] < heap[2*index+2]) {
                if (heap[2*index+1] < heap[index]) {
                    swap(heap[index], heap[2*index+1]);
                    minHeapify(2*index+1, maxSize);
                }
            }else {
                if (heap[2*index+2] < heap[index]) {
                    swap(heap[index], heap[2*index+2]);
                    minHeapify(2*index+2, maxSize);
                }
            }
        }
        else if (2*index+1 < maxSize) {
            // Left child exist
            if (heap[2*index+1] < heap[index]) {
                swap(heap[index], heap[2*index+1]);
                minHeapify(2*index+1, maxSize);
            }
        }
        else if (2*index+2 < maxSize) {
            // Right child exist
            if (heap[2*index+2] < heap[index]) {
                swap(heap[index], heap[2*index+2]);
                minHeapify(2*index+2, maxSize);
            }
        }
        else {
            // No child left
            return;
        }
        
    }
    void shiftUp (int index) {
        // Compare parent
        if (heap[index] < heap[(index-1)/2]) {
            // more than parent
            swap(heap[index], heap[(index-1)/2]);
            shiftUp((index-1)/2);
        }else {
            return;
        }
    }
    
public:
    minbinHeap(vector<int> myVector) {
        buildMinHeap(myVector);
    }
    
    void insert (int value) {
        heap.push_back(value);
        shiftUp(heap.size() - 1);
    }
    
    int top () {
        if (heap.empty()) return -1;
        return heap[0];
    }
    
    void removeTop () {
        swap(heap[0], heap[heap.size() - 1]);
        heap.erase(--heap.end());
        if (heap.empty()) return;
        minHeapify(0, heap.size());
    }
    
    void printVector () {
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
    
    void buildMinHeap (vector<int> myVector) {
        for (auto i = myVector.begin(); i != myVector.end(); i++) {
            insert(*i); // Insert and fixTree
            // NLog(N)
        }
    }
};