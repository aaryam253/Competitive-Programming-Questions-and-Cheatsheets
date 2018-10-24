#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <tuple>

#define MAX 2147483646

using namespace std;

double euclideanDistance (pair<int, int> source, pair<int, int> dest) {
    double differenceY = source.first - dest.first;
    double differenceX = source.second - dest.second;
    
    return sqrt(pow(differenceY, 2) + pow(differenceX, 2));
}


int main () {
//    map<int, pair<int, int>> indexMap;
    vector<pair<int, pair<int, int>>> indexMap;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num; cin >> num;
//            indexMap[num] = make_pair(i, j);
            indexMap.push_back(make_pair(num, make_pair(i, j)));
        }
    }
    sort(indexMap.begin(), indexMap.end());
    
    double complexity = 0;
    for (int i = 1; i < indexMap.size(); i++) {
        complexity += euclideanDistance(indexMap[i-1].second, indexMap[i].second);
    }
//    cout << complexity << endl;
    printf("%0.10lf\n", complexity);
}
