#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

bool sortbysec(const pair<string, int> &a, const pair<string, int> &b) {
    return (a.second < b.second);
}

int main() {
    int n, p, m; scanf("%d %d %d", &n, &p, &m);
    
    string name; int point;
    unordered_map<string, pair<int, int>> points;
    vector<pair<string, int>> output;
    
    while (n--) {
        cin >> name;
        points[name] = make_pair(0, 0);
    }
    
    for (int i = 0; i < m; i++) {
        cin >> name >> point;
        points[name].first = i;
        points[name].second += point;
    }
    
    bool winner = false;
    
    for (auto i : points) {
        if (i.second.second >= p) {
            winner = true;
            output.push_back(make_pair(i.first, i.second.first));
        }
    }
    
    sort(output.begin(), output.end(), sortbysec);
    
    for (auto i : output) cout << i.first << " wins!" << endl;
    
    if (!winner) cout << "No winner!" << endl;
    return 0;
}
