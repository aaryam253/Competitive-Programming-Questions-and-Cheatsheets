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
#include <iomanip>

#define MAX 2147483640

using namespace std;


int main() {
    while (true) {
        int N, B; cin >> N >> B;
        if (N == -1 && B == -1) break;
        vector<int> cities;
        priority_queue<tuple<int, int, int> > pq;
        for (int i = 0; i < N; i++) {
            int pop; cin >> pop;
            cities.push_back(pop);
            pq.push({pop, pop, 1});
        }
        
        B -= N;
        while (B) {
            int div = get<2>(pq.top());
            int orig = get<1>(pq.top());
            pq.pop();
            B--;
            int new_value = ceil(orig/(double)(div+1));
            pq.push({new_value, orig, div+1});
        }
        
        cout << get<0>(pq.top()) << endl;
    }
    
    
}



