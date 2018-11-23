#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <queue>
#include <list>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <string.h>
#include <cctype>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,k,p1,p2;
    string m1,m2;
    
    while (1) {
        cin >> n; if (!n) break; cin >> k;
        unordered_map<int, int> wins;
        unordered_map<int, int> losses;
        
        int games = (k*n*(n-1))/2;
        
        for (int i = 0; i < games; i++) {
            cin >> p1 >> m1 >> p2 >> m2; cin.ignore();
            if (m1 == m2) continue;
            
            if ((m1 == "rock" && m2 == "paper") || (m1 == "paper" && m2 == "scissors") || (m1 == "scissors" && m2 == "rock")) {
                wins[p2]++; losses[p1]++;
            } else {
                wins[p1]++; losses[p2]++;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            if (wins[i] == 0 && losses[i] == 0) cout << "-" << endl;
            else {
                float winavg = ((float)wins[i]/((float)wins[i] + (float)losses[i]));
                printf("%.3f\n", winavg);
            }
        }
        cout << endl;
    }
    
    return 0;
}