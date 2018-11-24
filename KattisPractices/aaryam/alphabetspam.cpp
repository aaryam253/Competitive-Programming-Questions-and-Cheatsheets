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
#include <math.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main (void) {
    int w = 0, l = 0, u = 0, s = 0;
    string sentence; getline(cin, sentence);
    
    for (int i = 0; i < sentence.size(); i++) {
        if (sentence[i] == '_') w++;
        else if (!isalpha(sentence[i])) s++;
        else if (islower(sentence[i])) l++;
        else u++;
    }
    
    printf("%.6lf\n", (float)w/(float)sentence.size());
    printf("%.6lf\n", (float)l/(float)sentence.size());
    printf("%.6lf\n", (float)u/(float)sentence.size());
    printf("%.6lf\n", (float)s/(float)sentence.size());
}
