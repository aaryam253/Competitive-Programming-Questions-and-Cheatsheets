#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <tuple>
#include <string.h>
#include <sstream>

#define MAX 2147483640

using namespace std;

list<int> child [1000];
list<int> parent[1000]; 
// We stored the parent just for fun to show that we can use 2 adj lists to create a tree
vector<vector<int>> orders;


// Pre order traversal
void preorder (int node, vector<int> order) {
    order.push_back(node);
    orders.push_back(order);
    
    for (auto it : child[node]) {
        preorder(it, order);
    }
    
}

int main () {
    // Assume they have unique identifiers
    child[3].push_back(5);
    child[3].push_back(8);
    child[3].push_back(6);
    parent[5].push_back(3);
    parent[8].push_back(3);
    parent[6].push_back(3);
    child[5].push_back(7);
    parent[7].push_back(5);
    child[7].push_back(8);
    child[7].push_back(9);
    parent[8].push_back(7);
    parent[9].push_back(7);
    child[6].push_back(20);
    child[6].push_back(10);
    parent[10].push_back(6);
    parent[20].push_back(6);
    
    vector<int> order;
    preorder(3, order);
    
    // Now we just need to binary search each of them to find a node that is >= P-value and closest to its ancestor (if its parent has other children)
    for (auto it : orders) {
        for (auto it2 : it) {
            cout << it2 << " ";
        }
        cout << endl;
    }
    
}
