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


int main () {
    // 1, 2 or 3
    // diamond, squiggles, ovals
    // solid, striped, open fill
    // red, green or purple
    vector<string> cards;
    for (int i = 0; i < 12; i++) {
        string card; cin >> card;
        cards.push_back(card);
    }
    bool haveSet = false;
    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            for (int d = j + 1; d < 12; d++) {
                bool flag = true;
                bool different = false;
                for (int c = 0; c < 4; c++) {
                    if (cards[i][c] == cards[j][c] && cards[d][c] == cards[i][c]) {
                        if (different) flag = false;
                    } else if (cards[i][c] != cards[j][c] && cards[i][c] != cards[d][c] && cards[j][c] != cards[d][c]) {
                        
                    } else {
                        flag = false;
                        different = true;
                    }
                }
                if (flag) {
                    haveSet = true;
                    cout << i+1 << " " << j+1 << " "<< d+1 << endl;
                }
            }
        }
    }
    if (!haveSet) cout << "no sets" << endl;
}
