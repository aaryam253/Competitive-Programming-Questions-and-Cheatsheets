#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <iterator>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <utility>
#define LSOne(S) (S & (-S))
#define NOTHING -1
#define INTMAX 9999999999
using namespace std;

typedef unsigned long long ull;
typedef pair<int, string> ps;
typedef pair<int, int> p;
typedef pair<double, double> pd;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> vvll;
typedef priority_queue<int, vector<int>, greater<>> pqmin;

struct cmp {
    bool operator()(const pair<string, int> s1, const pair<string, int> s2) {
        if (s1.second == s2.second) return s1.first < s2.first;
        return s1.second > s2.second;
    }
};

int main() {
    cmp c;
    string line;
    unordered_set<string> students;
    unordered_map<string, unordered_set<string>> studs;
    string currproject = "";
    
    while (1) {
        getline(cin, line);
        if (line == "0") break;
        else if (line == "1") {
            vector<pair<string, int>> ans;
            for (auto& i : studs) {
                ans.push_back(make_pair(i.first, i.second.size()));
            }
            
            sort(ans.begin(), ans.end(), c);
            for (auto& i : ans) {
                cout << i.first << " " << i.second << endl;
            }
            
            students.clear();
            studs.clear();
        }
        else if (isupper(line[0])) {
            currproject = line;
            unordered_set<string> dummy;
            studs[currproject] = dummy;
        }
        else {
            if (students.find(line) != students.end()) {
                for (auto& i : studs) {
                    if (i.first == currproject) continue;
                    if (i.second.find(line) != i.second.end()) {
                        auto idx = studs[i.first].find(line);
                        studs[i.first].erase(idx);
                    }
                }
            } else {
                students.insert(line);
                studs[currproject].insert(line);
            }
        }
    }
    
    return 0;
}
