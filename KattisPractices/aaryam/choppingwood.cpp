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
#include <cstring>
#include <cstdio>
#include <utility>
#define LSOne(S) (S & (-S))
#define INTMAX 99999999
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> edges(n,0), vertices(n,0), visited(n+1, 0);
    int max = n+1;
    
    for (int i = 0; i < n; i++) scanf("%d", &vertices[i]);
    
    if (vertices[n-1] == n+1) {
        // backtrack, add respective edges in reverse order
        for (int i = n-1; i > 0; i--) {
            if (!visited[vertices[i-1]] && (vertices[i-1] < n+1)) {
                edges[i] = vertices[i-1]; visited[vertices[i-1]] = 1;
            } else {
                while (visited[max]) max--;
                edges[i] = max; visited[max++] = true;
            }
        }
        while (visited[max]) max--; edges[0] = max;
        for (auto i : edges) printf("%d\n", i);
        
    } else printf("Error\n");
    
    return 0;
}

