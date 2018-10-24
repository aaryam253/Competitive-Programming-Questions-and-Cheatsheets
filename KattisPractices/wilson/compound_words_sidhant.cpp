#include <iostream>
#include <stdio.h>
#include <stdarg.h>
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


using namespace std;
int main () {
    vector<string> stringArr;
    string input;
    int index = 0;
    while (index < 4) {
        index++;
        cin >> input;
        stringArr.push_back(input);
    }
    
    priority_queue<tuple<string, int, int>, vector<tuple<string, int, int>>, greater<tuple<string, int, int>> > pq;
    
    sort(stringArr.begin(), stringArr.end());
    pq.push(make_tuple(stringArr[0]+stringArr[1], 0 , 1));
    for (int i = 1 ; i < stringArr.size(); i++) {
        //pq.push(make_pair(0, i));
        pq.push(make_tuple((stringArr[i]+stringArr[0]), i, 0));
    }
    
    while (!pq.empty()) {
        tuple<string, int, int> curr = pq.top();
        int first = get<1>(curr), second = get<2>(curr);
        pq.pop();
        cout << (get<0>(curr)) << endl;
        
        int new_second =  (second + 1) % stringArr.size();
        
        if (new_second != first)
            pq.push(make_tuple(stringArr[first] + stringArr[new_second], first, new_second));
        
    }
    
}
