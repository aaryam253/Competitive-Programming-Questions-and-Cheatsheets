// Num shortest paths using dijsktra - efficient

int countPaths () {
    vector<int> added_weight(V, MAX);
    set<pair<int, int>> q; // Use set instead of PQ
    
    q.insert({0,s});
    added_weight[s] = 0;
    int ways[15000] = {};
    ways[s] = 1;
    
    while (!q.empty()) {
        pair<int, int> curr = *q.begin();
        q.erase(q.begin());
        int current = curr.second;
        
        if (added_weight[current] < curr.first) continue;
        
        for (auto it : AL[current]) {
            if (added_weight[it.second] > added_weight[current] + it.first) {
                
                added_weight[it.second] = (added_weight[current] + it.first);
                ways[it.second] = ways[current]; // Replace replace with the true shortest path is combined weight is smaller
                q.insert(make_pair(added_weight[it.second], it.second));

            } else if (added_weight[it.second] == added_weight[current] + it.first) {
                
                ways[it.second] += ways[current]; // Add on if the added weights are equal
            }
        }
    }    
    return ways[t];
}

