#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;


void calculate () {
    priority_queue<string, vector<string>, greater<string>> pq;
    
    string input;
    int num;
    cin >> num;
    while (num--) {
        cin >> input;
        pq.push(input);
    }
    
    // Get the smallest string first
    string curr = pq.top();
    pq.pop();
    while (pq.size() > 0) {
        string curr_ = pq.top();
        pq.pop();
        // Just compare from start to end, increasing the size of sub_str
        if (curr == curr_.substr(0, curr.size())) {
            cout << "NO" << endl;
            return;
        }
        else curr = curr_;
    }
    
    cout << "YES" << endl;
}


int main () {
    int TC;
    cin >> TC;
    
    while (TC--) {
        calculate();
    }
}


