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

struct contestants {
    int problems, penalty, time, bonus, entry, score;
};
// Please dont use tuples, it was a nightmare

bool compare (contestants a, contestants b) {
    if (a.problems != b.problems) return a.problems < b.problems;
    if (a.penalty != b.penalty) return a.penalty < b.penalty;
    return a.time < b.time;
}

bool entryCompare(contestants a, contestants b) {
    return a.entry < b.entry;
}

// Similarity check as per the question requirement
bool isSimilar (contestants a, contestants b) {
    if (a.problems == b.problems && a.penalty == b.penalty && a.time == b.time) return true;
    return false;
}


int main() {
    int n; cin >> n;
    vector<contestants> v;
    for (int i = 0; i < n; i++) {
        int s, p ,f, o; cin >> s >> p >> f >> o;
        v.push_back({-s, p, f, o, i, 0});
    }
    sort(v.begin(), v.end(), compare);
    
    //        for (auto it : v) {
    //            cout << get<0>(it) << " " << get<1>(it) << " " << get<2>(it) << " " << get<3>(it) << endl;
    //        }
    
    
    int scores[] = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24,
        22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    for (int i = 0; i < v.size(); i++) {
        vector<int> similarScores;
        
        int index_end = i;
        int index_start = i;
        
        // If the next index is similar then we highlight the entire range
        while (index_end+1 < v.size() && isSimilar(v[index_end], v[index_end+1])) {
            i++;
            index_end++;
        }
        int sum = 0;

        // Sum up the ranking scores of that entire highlighted range
        for (int d = index_start; d <= index_end; d++) {
            if (d < 30) sum += scores[d];
        }
        
        // Find the sum
        sum = ceil((double)sum/(index_end-index_start + 1));
        
        // Update the scores of the individual contestants
        for (int d = index_start; d <= index_end; d++) {
            v[d].score = sum + v[d].bonus;
        }
        
    }

    // Sort them again based on how they were inserted - trap part
    sort(v.begin(), v.end(), entryCompare);
    for (auto it : v) {
        cout << it.score << endl;
    }
    
    
}
