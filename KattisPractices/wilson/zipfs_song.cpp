#include <stdio.h>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;


int main () {
    int index = 50000;
    int numSongs, numRequests;
    cin >> numSongs >> numRequests;
    priority_queue<tuple<unsigned long long, int , string>> songQueue;
    
    for (int i = 1; i <= numSongs; i++) {
        unsigned long long f;
        string name;
        cin >> f >> name;
        
        songQueue.push(make_tuple((f*i), index--, name));
    }
    
    for (int i = 0; i < numRequests; i++) {
        cout << get<2>(songQueue.top()) << endl;
        songQueue.pop();
    }
    
}
