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
    char mtx[101][101] = {};
    int c; cin >> c;
    int it = 0;
    string input; cin >> input;
    
    vector<pair<int, int> > myIs;
    
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < c; j++) {
            if (input[it] == 'I') {
                myIs.push_back(make_pair(i, j));
            }
            mtx[i][j] = input[it++];
        }
    }
    
    stack<tuple<int, int, int> > myStack;
    
    string target = "ICPCASIASG";
    //    cout << targetSet.size() << endl;
    
    int dx[8] = {1,2,2,1,-1,-2,-2,-1};
    int dy[8] = {-2,-1,1,2,2,1,-1,-2};
    
    //    cout << checkSet.size() << endl;
    
    for (auto it : myIs) {
        myStack.push(make_tuple(it.first, it.second, 0));
        
        while (!myStack.empty()) {
            tuple<int, int, int> curr = myStack.top();
            myStack.pop();
            
            if (mtx[get<0>(curr)][get<1>(curr)] != '0') {
                for (int i = 0; i < 8; i++) {
                    int x = get<1>(curr) + dx[i];
                    int y = get<0>(curr) + dy[i];
                    int currentIndex = get<2>(curr);
                    
                    if (x < c && x >= 0) {
                        if (y < c && y >= 0) {
                            if (mtx[y][x] == target[currentIndex + 1]) {
                                //                                    cout << "hit" << " " << mtx[y][x] << endl;
                                myStack.push(make_tuple(y, x, currentIndex + 1));
                            }
                            
                            if (mtx[y][x] == target[currentIndex + 1] && currentIndex + 1 == target.length() - 1) {
                                cout << "YES" << endl;
                                return 0;
                            }
                            
                        }
                    }
                }
            }
            
        }

    }
    
//    for (int i = 0; i < c; i++) {
//        for (int j = 0; j < c; j++) {
//
//        }
//    }
    
    
    cout << "NO" << endl;
    return 0;
    
}
