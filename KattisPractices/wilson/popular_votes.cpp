#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int TC;
    cin >> TC;
    while (TC--) {
        int num;
        cin >> num;
        int total = 0;
        vector<pair<int, int>> vote_pair;
        for (int i = 0; i < num; i++) {
            int votes;
            cin >> votes;
            total += votes;
            vote_pair.push_back(make_pair(votes, i));
        }
        
        sort(vote_pair.begin(), vote_pair.end());
        
        if (vote_pair[num-1].first == vote_pair[num-2].first) {
            cout << "no winner" << endl;
        } else if (vote_pair[num-1].first > total/2){
            cout << "majority winner ";
            cout << (vote_pair[num-1].second + 1 ) << endl;
        } else {
            cout << "minority winner ";
            cout << (vote_pair[num-1].second + 1 ) << endl;
        }
        

    }
}

