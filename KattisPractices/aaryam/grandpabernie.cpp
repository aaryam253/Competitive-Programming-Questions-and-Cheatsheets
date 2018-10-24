#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, q;
    cin >> n;
    unordered_map<string, vector<int>> c_data;
    string name; int year;
    
    for (int i = 0; i < n; i++) {
        cin >> name >> year; cin.get();
        c_data[name].push_back(year);
    }
    
    cin >> q;
    for (auto i = c_data.begin(); i != c_data.end(); i++) {
        sort(i->second.begin(), i->second.end());
    }
    
    for (int i = 0; i < q; i++) {
        cin >> name >> year;
        cout << c_data[name][year - 1] << endl;
    }
    
    return 0;
}
