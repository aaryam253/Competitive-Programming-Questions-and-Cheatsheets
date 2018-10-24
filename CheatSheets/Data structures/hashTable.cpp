#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;


class HT_direct {
private:
    string arr[1000];
    
public:
    HT_direct (){}
    
    // All basic operations must be O(1)
    
    void insert (int num, string data) {
        arr[num] = data;
    }
    
    string search (int num) {
        return arr[num];
    }
    
    void remove (int num) {
        arr[num] = "";
    }
};


class HT_seperate {
private:
    int size; // Size its best to keep it to prime numbers
    list<int> arr[1000]; // This must be a doubly linked list
    
    
public:
    
    HT_seperate (int input) {size = input;}
    
    // Basic operations are done in O(1+alpha)
    
    void insert (int data) {
        int base = data%size; // obtain the base
        if (search(data)) {
            return; // Does not store duplicates
        }else {
            arr[base].push_back(data);
        }
    }
    
    // Basic search, can be modified to return a tuple too to store satellite data
    bool search (int data) {
        int base = data%size;
        auto it = find(arr[base].begin(), arr[base].end(), data);
        if (it == arr[base].end()) {
            return false;
        }
        return true;
    }
    
    
    void remove (int data) {
        int base = data%size;
        auto it = find(arr[base].begin(), arr[base].end(), data);
        if (it != arr[base].end()) {
            // Data found
            arr[base].erase(it);
        }
    }
    
    double loadFactor() {return (double)size/1000;} // 1000 because array size is 1000
};


class HT_open {
    
    // Precond: All integers are positive, -1 is used to signify empty slot, -2 is used to signify deleted slot
    // Switch the probing style to your liking i.e uncommment it
    
private:
    int arr[1000] = {0};
    int size; // Size its best to keep it to prime numbers
    
public:
    HT_open (int input) {
        size = input;
        
        for (int i = 0; i < size; i++) {
            arr[i] = -1; // init to all -1
        }
    }
    
    void insert (int data) {
        int base = data%size;
        int step = 0;
        while (true) {
            int i = (base + step) % size;
            /*
             int i = (base + step*step) % size; // Quadratic probing
             
             int base2 = data%SOMETHING;
             int i = (base + step * base2) % size;
             */
            
            if (arr[i] == -1 || arr[i] == -2) {
                arr[i] = data;
                break;
            } else {
                step++; // to find the next best spot
            }
        }
    }
    
    bool search (int data) {
        int base = data%size;
        int step = 0;
        while (true) {
            int i = (base * step) % size;
            
            /*
             int i = (base + step*step) % size; // Quadratic probing
             
             int base2 = data%SOMETHING;
             int i = (base + step * base2) % size;
             */
            
            
            if (arr[i] != -1) {
                if (arr[i] == data)
                    return true;
                else step++;
            } else {
                return false; // not found
            }
        }
        return false;
    }
    
    
    void remove (int data) {
        int base = data%size;
        int step = 0;
        while (true) {
            int i = (base * step) % size;
            
            /*
             int i = (base + step*step) % size; // Quadratic probing
             
             int base2 = data%SOMETHING;
             int i = (base + step * base2) % size;
             */
            
            if (arr[i] == data) {
                arr[i] = -2;
                break;
            }else {
                step++;
            }
        }
    }
    
    double loadFactor() {return (double)size/1000;} // 1000 because array size is 1000
};


/* Hashtable types:
 
 1. Direct addressing table - for small data sets with distinct values
 2. Seperate chaining
 3. Open addressing - Linear probing, quad probing, double hashing
 
 In summary, a good Open Addressing collision resolution technique needs to:
 
 Always find an empty slot if it exists,
 Minimize clustering,
 Give different probe sequences when 2 different keys collide,
 Fast, O(1).

 */



// Tip for visualgo, 
/*
    If faced with quadratic probing or secondary hashing, try to simplify the formula and count from there 
*/


