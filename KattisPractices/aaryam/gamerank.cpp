#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;

int rankstars(int rank) {
    if (rank <= 25 && rank >= 21) return 2;
    else if (rank <= 20 && rank >= 16) return 3;
    else if (rank <= 15 && rank >= 11) return 4;
    else if (rank <= 10 && rank >= 1) return 5;
    else return -1000;
}

int main (void) {
    int stars = 0, rank = 25;
    int winstreak = 0;
    
    string games;
    getline(cin, games);
    
    for (int i = 0; i < games.size(); i++) {
        int addstar = 0;
        
        if (games[i] == 'W') {
            winstreak++;
            addstar = winstreak >= 3 && rank <= 25 && rank >= 6 ? 2 : 1;
            stars += addstar;
            
            if (stars > rankstars(rank)) {
                stars -= rankstars(rank);
                rank--;
            }
        }
        else if (games[i] == 'L') {
            winstreak = 0;
            
            if (rank < 20 || (rank == 20 && stars != 0)) {
                stars--;
            }
            
            if (stars < 0) {
                rank++;
                stars = rankstars(rank) - 1;
            }
        }
        
        if (rank == 0) {
            cout << "Legend" << endl;
            break;
        }
    }
    
    if (rank != 0) {
        cout << rank << endl;
    }
    
    return 0;
}
