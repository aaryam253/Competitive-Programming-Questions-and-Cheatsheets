#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <math.h>
using namespace std;

int main(void) {
    int time; string question, result;
    unordered_set<string> unsolved;
    unordered_set<string> done;
    unordered_map<string, int> penalty;
    int solved = 0, total = 0;
    
    while (1) {
        cin >> time; if (time == -1) break;
        cin >> question >> result;
        if (result == "right") {
            if (unsolved.find(question) == unsolved.end() && done.find(question) == done.end()) {
                solved++; total += time; done.insert(question);
            }
            else if (unsolved.find(question) == unsolved.end() && done.find(question) != done.end()) {
                continue;
            }
            else {
                solved++; total += time + (20 * penalty[question]);
                unsolved.erase(question); done.insert(question);
            }
        }
        else if (result == "wrong") {
            if (unsolved.find(question) == unsolved.end()) {
                unsolved.insert(question); penalty[question]++;
            }
            else {
                penalty[question]++;
            }
        }
    }
    
    cout << solved << " " << total << endl;
    return 0;
}
