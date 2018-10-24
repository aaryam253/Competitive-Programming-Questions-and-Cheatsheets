#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <unordered_set>
#include <queue>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

unordered_map<int, int> predecessor;
unordered_map<string, int> name_id;
unordered_map<int, int> visited;
unordered_map<int, string> id_name;

int ids = 0;

unordered_set<int> AL[10000];

void connect (int v, int v2) {
    AL[v2].insert(v);
    AL[v].insert(v2);
}


void bfs (int v) {
    queue<int> q;
    q.push(v);
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        visited[curr] = 1;

        for (auto it = AL[curr].begin(); it != AL[curr].end(); it++) {
            if (visited.find(*it) == visited.end()) {
                predecessor[*it] = curr;
                q.push(*it);
            }
        }
    }
}



int main () {
    int num; cin >> num;
    //cin.ignore(); // IMPORTANT!! Use this to flush out the /n left over from the prev cin >>
    while (num--) {
        string a, b;
        cin >> a;
        cin.ignore();
        if (name_id.find(a) == name_id.end()) {
            id_name[ids] = a;
            name_id[a] = ids++;
        }

        getline(cin, b);
        istringstream iss (b);
        string token;
        while (getline(iss, token, ' ')) {
            if (name_id.find(token) == name_id.end()) {
                id_name[ids] = token;
                name_id[token] = ids++;
            }
            connect(name_id[a], name_id[token]);
        }
    }
    
    
    string input, input2; cin >> input >> input2;
    
    bfs(name_id[input]);
    //cout << predecessor[name_id[input2]] << endl;
    if (visited.find(name_id[input2]) == visited.end()) {
        cout << "no route found" << endl;
    }else {
        vector<string> output;
        // Backtrack
        int curr = name_id[input2];
        while (curr != name_id[input]) {
            output.push_back(id_name[curr]);
            curr = predecessor[curr];
        }
        output.push_back(input);
        //cout << output.size() << endl;
        reverse(output.begin(), output.end());
        for (auto it : output) {
            cout << it << " ";
        }
        cout << endl;
    }
    
}
