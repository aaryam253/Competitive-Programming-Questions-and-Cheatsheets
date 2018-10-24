#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <set>

using namespace std;


int main () {
    // villagers will only increment if bard is present
    // villagers must have same number as bard
    map<int, set<int> > incremental;
    
    int N, E; cin >> N >> E;
    int curr_song = 1;
    
    for (int i = 0; i < E; i++) {
        int num; cin >> num;
        vector<int> present;
        int bard = 0;
        while (num--) {
            int input;
            cin >> input;
            present.push_back(input);
            if (input == 1) {
                bard = 1;
            }
        }
        
        if (bard) {
            incremental[1].insert(curr_song); // give them unique song IDs
            for (auto it : present) {
                incremental[it].insert(curr_song);
            }
            curr_song++; // Set the stage for the next song
        }else {
            // Exchange all songs
            set<int> common_set;
            for (auto it : present) {
                for (auto it2 = incremental[it].begin(); it2 != incremental[it].end() ; it2++) {
                    common_set.insert(*it2);
                }
            }
            // Dump everything into everyone
            for (auto it : present) {
                for (auto it2 : common_set) {
                    incremental[it].insert(it2);
                }
            }
        }
        
        
        
    }
    for (auto it : incremental) {
        if (it.second == incremental.begin()->second) {
            // same songs known as bard
            cout << it.first << endl;
        }
    }
}
