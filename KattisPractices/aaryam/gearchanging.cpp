#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    float limit = (float) p/100;

    vector<float> teeth_crank(n);
    vector<float> teeth_back(m);

    for (auto &i: teeth_crank) {
        cin >> i;
    }
    
    for (auto &i: teeth_back) {
        cin >> i;
    }

    set<float> cadence;
    
    for (auto i : teeth_crank) {
        for (auto j: teeth_back) {
            cadence.insert(i/j);
        }
    }

    float curr = *cadence.begin();
    cadence.erase(curr);

    bool can_change = true;

    for (auto i : cadence) {
        if (curr + curr*limit < i) {
            can_change = false;
        }
        curr = i;
    }

    if (can_change) {
        cout << "Ride On!" << endl;
    } else {
        cout << "Time to change gears!" << endl;
    }
    
    return 0;
}
