#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <sstream>

using namespace std;

list<int> mytree[101];


void dfs (int source) {
    cout << source << " ";
    for (auto it : mytree[source]) {
        dfs(it);
    }
}



int main () {
    int cat; cin >> cat;
    int parent;
    while (true) {
        cin >> parent;
        cin.ignore();
        if (parent == -1) break;
        int children;
        
        string line;
        
        getline(cin, line);
        istringstream iss (line);
        string token;
        while (getline(iss, token, ' '))
        {
            mytree[stoi(token)].push_back(parent);
        }
        
        /*
        while (cin >> children) {
            mytree[children].push_back(parent);
        }
        */
    }
    dfs(cat);
    cout << endl;

}
