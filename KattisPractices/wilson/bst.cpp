#include <iostream>
#include <stdio.h>
#include <unordered_map>


using namespace std;

unordered_map<int, int> myHeight; // key to height pair

int parents [300000] = {0};
pair<int, int> left_parent [300000] ; // First is the key itself, second is the index in the parents arr
pair<int, int> right_parent [300000] ;


int curr_index = 0;



// TODO: Implement 3 arrays where arr_right, left and parent will share the same index
// or implement an unordered map where they will share the same index too
int insert (int key) {
    if (curr_index == 0) {

        parents[curr_index++] = key;
        myHeight[key] = 0;
        return 0 ;
    }
    
    int index = 0;
    // This takes too many traversals 
    while (true) {
        if (key > parents[index]) {
            // traverse right
            if (right_parent[index].first == 0) {
                // found insertion pt
                right_parent[index] = make_pair(key, curr_index);
                parents[curr_index++] = key;
                
                myHeight[key] = myHeight[parents[index]] + 1;
                return myHeight[key];
            }
            // TODO: Find a way to bridge this part, to move to the next parent
            index = right_parent[index].second;
            //cout << index << endl;
        }
        // TODO: continue conversion
        else if (key < parents[index]) {
            // traverse left
            if (left_parent[index].first == 0) {
                // found insertion pt
                left_parent[index] = make_pair(key, curr_index);
                parents[curr_index++] = key;
                myHeight[key] = myHeight[parents[index]] + 1;
                return myHeight[key];
            }
            index = left_parent[index].second;
            //cout << index << endl;
        }
        else{
            return 0;
        }
    }
}



int main () {
    
    int count = 0;
    int num; cin >> num;
    for (int i = 1; i <= num; i++) {
        int key; cin >> key;
        count += insert(key);
        cout << count << endl;
    }

}
