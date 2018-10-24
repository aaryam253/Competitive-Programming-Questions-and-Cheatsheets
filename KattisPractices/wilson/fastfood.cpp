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
    int TC; cin >> TC;
    
    while (TC--) {
        int n, m; cin >> n >> m; // Stickers and prizes
        unordered_map<int, int> myTickets;
        unsigned long long total = 0;
        queue<pair<unordered_map<int, int>, int>> ticketsAndPrizes;
        
        int m_temp = m;
        while (n--) {
            int k; cin >> k; // num sticker types required to claim the prize
            unordered_map<int, int> types;
            int cashPrize;
            while (k--) {
                int type; cin >> type;
                types[type] = 1;
            }
            cin >> cashPrize;
            ticketsAndPrizes.push(make_pair(types, cashPrize));
        }
        
        for (int i = 1; i <= m_temp; i++) {
            int num; cin >> num;
            myTickets[i] = num;
        }
        
        while (!ticketsAndPrizes.empty()) {
            bool satisfied = true;
            unordered_map<int, int> temp = myTickets;
            
            while (satisfied) {
                for (auto it : ticketsAndPrizes.front().first) {
//                    cout << it.first << " " << temp[it.first] << endl;
                    temp[it.first] -= it.second;
                    if (temp[it.first] < 0) {
                        satisfied = false;
                        break;
                    }
                }
                
                if (satisfied) {
                    myTickets = temp;
                    total += ticketsAndPrizes.front().second;
                }
            }

            ticketsAndPrizes.pop();
        }
        
        cout << total << endl;
    }
    
}
