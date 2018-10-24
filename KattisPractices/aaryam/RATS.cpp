#include <bits/stdc++.h>
using namespace std;

string GRATS (string current) {
    string input = current;
    reverse(current.begin(), current.end());
    
    unsigned long long num = stoull(current) + stoull(input);
    string output = to_string(num);
    stable_sort(output.begin(), output.end());
    
    while (*output.begin() == 0) {
        output.erase(output.begin());
    }
    
    return output;
}

int main () {
    int TC; cin >> TC;
    
    while(TC--) {
        int K, M; string RATS;
        cin >> K >> M >> RATS;
        
        vector<unsigned long long> sequence;
        unordered_set<unsigned long long> num;
        
        sequence.push_back(stoull(RATS));
        num.insert(stoull(RATS));
        
        bool cycle = false;
        bool creeper = false;
        int index;
        
        for (int i = 0; i < M; i++) {
            unsigned long long j = sequence.back();
            string curr = GRATS(to_string(j));
            unsigned long long check = stoull(curr);
            
            if (num.find(check) != num.end()) {
                cycle = true;
                index = (int)sequence.size() + 1;
            }
            else if (curr.size() >= 8){
                bool holds = false, holds2 = false;
                if (curr.compare(0,4,"1233") == 0 && curr.compare(curr.size()-4,4,"4444") == 0) {
                    for (int i = 4; i < (int)curr.size() - 4; i++) {
                        if (curr[i] != '3') {
                            holds = false; break;
                        }
                        else holds = true;
                    }
                }
                else if (curr.compare(0,4,"5566") == 0 && curr.compare(curr.size()-4,4,"7777") == 0) {
                    for (int i = 4; i < (int)curr.size() - 4; i++) {
                        if (curr[i] != '7') {
                            holds = false; break;
                        }
                        else holds = true;
                    }
                }
                if (holds == true || holds2 == true) creeper = true;
                index = (int)sequence.size();
            }
            
            if (cycle == true || creeper == true) break;
            
            sequence.push_back(check); num.insert(check);
        }
        
        if (cycle) {
            cout << K << " R " << index << endl;
        }
        else if (creeper) {
            cout << K << " C " << index << endl;
        }
        else cout << K << " " << sequence[M-1] << endl;
    }
    return 0;
}
