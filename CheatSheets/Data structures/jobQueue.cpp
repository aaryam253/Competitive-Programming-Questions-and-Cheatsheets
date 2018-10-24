#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>

using namespace std;

class jobQueue {
private:
    tuple<int, int , string> heap[1000]; // priorityVal, ID, identifier(name)
    int size;
    int id_index [1000];
    unordered_map<string, int> name_index; // for easier look up for name to ID
    void maxheapify (int index, int maxSize) {
        // Compare childs
        if (2*index+2 < maxSize) {
            // Both child exist
            if (heap[2*index+1] > heap[2*index+2]) {
                // Left child larger than right child
                if (heap[2*index+1] > heap[index]) {
                    swap(heap[index], heap[2*index+1]);
                    
                    // ID swap are needed to be made in the id_index so that it is updated.
                    id_index[get<1>(heap[index])] = index;
                    id_index[get<1>(heap[2*index+1])] = 2*index+1;
                    
                    maxheapify(2*index+1, maxSize);
                }
            }else {
                // Left child smaller or equals to right child
                if (heap[2*index+2] > heap[index]) {
                    swap(heap[index], heap[2*index+2]);
                    
                    id_index[get<1>(heap[index])] = index;
                    id_index[get<1>(heap[2*index+2])] = 2*index+2;
                    
                    maxheapify(2*index+2, maxSize);
                }
            }
        }
        else if (2*index+1 < maxSize) {
            // Left child exist
            if (heap[2*index+1] > heap[index]) {
                swap(heap[index], heap[2*index+1]);
                
                id_index[get<1>(heap[index])] = index;
                id_index[get<1>(heap[2*index+1])] = 2*index+1;
                
                
                maxheapify(2*index+1, maxSize);
            }
        }
        else {
            // No child left
            return;
        }
        
    }
    void shiftUp (int index) {
        // Compare parent
        if (heap[index] > heap[(index-1)/2]) {
            // more than parent
            swap(heap[index], heap[(index-1)/2]);
            
            id_index[get<1>(heap[index])] = index;
            id_index[get<1>(heap[(index-1)/2])] = (index-1)/2;
            
            
            shiftUp((index-1)/2);
        }else {
            return;
        }
    }
    
    
public:
    jobQueue (){
        size = 0;
    }
    
    
    void insert (int priorityVal, int id ,string name) {
        name_index[name] = id; // Allocate a name for that id
        id_index[id] = size;
        heap[size] = make_tuple(priorityVal, id, name);
        shiftUp(size);
        id--;
        size++;
    }
    
    tuple<int, int, string> top () {
        if (!size) return make_tuple(-1,-1,"#");
        return heap[0];
    }
    
    void removeTop () {
        swap(heap[0], heap[size - 1]);
        
        id_index[get<1>(heap[0])] = 0;
        id_index[get<1>(heap[size-1])] = size-1;
        size--;
        if (!size) return;
        maxheapify(0, size);
    }
    
    bool modify (string name, int value) {
        // To modify the priorityValue only
        int index = id_index[name_index[name]]; // might take the longest
        
        get<0>(heap[index]) = value;
        
        // After modification, we will see if we need to shiftUp or down.
        if (heap[index] > heap[(index-1)/2]) {
            shiftUp(index);
            return true;
        }else {
            maxheapify(index, size);
            return true;
        }
        return false; // if unsucessful
    }
    
};



int main () {
    int id = 1000;
    jobQueue myJobs;
    myJobs.insert(60, id--, "ARJO");
    // Since this is a max heap, I will reduce the id numbers so that those who arrive first will have a larger ID number
    myJobs.insert(50, id-- ,"TZEGUANG");
    myJobs.insert(70, id-- ,"WILSON");
    
    cout << get<2>(myJobs.top())  << " " << get<0>(myJobs.top())<< endl; // Will print Wilson
    myJobs.removeTop(); // Pop Wilson off
    cout << get<2>(myJobs.top())  << " " << get<0>(myJobs.top())<< endl; // Will print Arjo
    
    myJobs.modify("TZEGUANG", 100); // Modifying Tze Guang's priority
    
    cout << get<2>(myJobs.top()) << " " << get<0>(myJobs.top()) << endl; // Will print Tze Guang
    
}
