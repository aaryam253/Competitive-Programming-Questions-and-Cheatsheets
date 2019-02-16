class bellman_ford_graph {
    // Time complexity: O (V * E)
    // Allow -ve weights
    // Limitations:
    /*
     - Can contain -ve weights but not -ve cycles
     */
protected:
    list<pair<int, int> > AL[10];
    unordered_map<int, int> predecessor;
    int numv;
    
public:
    bellman_ford_graph (int size) {
        this->numv = size;
    }
    
    void connect (int v, int v2, int weight) {
        AL[v].push_back(make_pair(weight, v2));
        // This one uses an edge list
    }
    
    int bellman_ford (int s, int d) {
        // Init them all to max
        vector<int> added_weight (numv, 1000000);
        
        added_weight[s] = 0; // The source should have zero weight

        // 3 for loops :o 
        for (int i = 0; i < numv - 1; i++) { 
            // Relax the edges numv - 1 times (max number of possible edges is numv - 1)

            for (int d = 0; d < numv; ++d)
            {
                int v = d;
                for (auto it = AL[d].begin(); it != AL[d].end(); it++) {

                    int v2 = it->second;
                    int w = it->first;
                    
                    // Relax
                    if (added_weight[v2] > added_weight[v] + w) {
                        added_weight[v2] = added_weight[v] + w;
                        predecessor[v2] = v;
                    }
                    
                }
                
            }
        }
        // Neg cycles checker
        bool hasNegativeCycle = false;
        for (int u = 0; u < numv; u++) {                         
            // one more pass to check
            for (auto it : AL[u]) {
                if (added_weight[it.second] > added_weight[u] + it.first) {               
                    // should be false
                    hasNegativeCycle = true;     // but if true, then negative cycle exists
                }
            }
        }
        
        if (hasNegativeCycle) cout << "Contains -ve cycles" << endl;


        // To precisely find out exactly which one contains the neg cycle
        unordered_set<int> neg_cycle;
        bool ch = true;
        while (ch) {
            ch = false;
            for (int u = 0; u < numv; u++) {
                // one more pass to check
                if (added_weight[u] >= INF) continue;
                for (auto it : AL[u]) {
                    if (added_weight[it.second] > added_weight[u] + it.first && neg_cycle.find(it.second) == neg_cycle.end()) {
                        // should be false
                        //neg_cycle->insert(u);
                        added_weight[it.second] = -INF;
                        ch = true;
                        neg_cycle.insert(it.second);
                    }
                }
            }
        }
        
        return added_weight[d];
    }

    // Top-down bellman ford
    void modified_bellman_ford (int s, int d) {
        int added_weight_2 [numv][numv];
        for (int i = 0; i < numv; i++) {
            for (int d = 0; d < numv; d++) {
                added_weight_2[i][d] = 1000000;
            }
        }

        added_weight_2[0][s] = 0; // Source should have zero weight


        for (int i = 1; i < numv; i++) { // Relax the edges numv - 1 times
            for (int d = 0; d < numv; ++d)
            {
                int v = d;
                for (auto it = AL[d].begin(); it != AL[d].end(); it++) {
                    
                    int v2 = it->second;
                    int w = it->first;
                    
                    // Relax
                    if (added_weight_2[i][v2] > added_weight_2[i-1][v] + w) {
                        added_weight_2[i][v2] =  added_weight_2[i-1][v] + w;
                    }
                    
                }
                
            }
        }

        // This will print out the matrix to help visualise where its possible to travel to shortest path within k nodes
        for (int i = 0; i < numv; i++) {
            for (int d = 0; d < numv; d++) {
                cout << added_weight_2[i][d] << " ";
            }
            cout << endl;
        }
    }

    // Bellman_ford can be used to detect if there are negative edges too by checking if at least one value in added_weight [v] fails to converge
};



class bfs {
    // Limitations:
    /*
     - All weights must be constant
     - Means can't use on graph with negative edges too
     - If used without constant weights, will produce WA 
     */
    // Time complexity: O (V + E)
protected:
    list<pair<int, int> > AL[10];
    unordered_map<int, int> predecessor; // only used for tracking
    int numv;
    
    void relax (int v, int v2, int w) {
    }
public:
    bfs (int size) {
        this->numv = size;
    }
    
    void connect (int v, int v2, int weight) {
        AL[v].push_back(make_pair(weight, v2));
        // This one uses an edge list
    }
    
    
    int BFS (int source, int dest) {
        queue<int> q;
        q.push(source);
        vector<int> added_weight (numv, 1000000);
        added_weight[source] = 0;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            
            for (auto it = AL[current].begin(); it != AL[current].end(); it++) {
                // Notice this is impt, we only push in unvisited vertices, removing it will cause infinite loop
                if (added_weight[it->second] == 1000000) {
                    // Unvisited
                    // Relax
                    int v = current;
                    int v2 = it->second;
                    int w = it->first;
                    
                    if (added_weight[v2] > added_weight[v] + w) {
                        added_weight[v2] = added_weight[v] + w;
                        predecessor[v2] = v;
                    }
                    q.push(it->second);
                }
            }
        }
        return added_weight[dest];
    }
};

class dijkstra {
    // Limitations:
    /*
        - Must have no negative edge cycles at all, it will cause infinite loop
    */
    // Time complexity: O ((V+E) logV)
protected:
    list<pair<int, int> > AL[10];
    vector<int> added_weight;

    unordered_map<int, int> predecessor;
    int numv;
    
    
public:
    dijkstra (int size) {
        this->numv = size;
    }
    
    void connect (int v, int v2, int weight) {
        AL[v].push_back(make_pair(weight, v2));
        // This one uses an edge list
        
        // Need to initialise them all to int maximum
    }
    
    // O((V+E)logV)
    void perform_dijkstra (int source) {
        // Init a vector of sized numv all with values of 1000000
        vector<int> added_weight(numv, 1000000);

        priority_queue<pair<int, int>, vector<int, int>, greater<> > q; // Becareful of this
        // Init source to 0
        added_weight[source] = 0;
        q.push(make_pair(0, source));
        
        while (!q.empty()) {
            pair<int, int> curr = q.top();
            int current = curr.second;
            q.pop();

            // If added weight is smaller than weight itself, don't process
            if (added_weight[current] < curr.first) continue; 


            for (auto it = AL[current].begin(); it != AL[current].end(); it++) {

                // Relax 
                if (added_weight[it->second] > added_weight[current] + it->first) {
                    added_weight[it->second] = added_weight[current] + it->first;
                    predecessor[it->second] = current;
                    // Keeps pushing into the pq, may contain duplicates
                    q.push(make_pair(added_weight[it->second], it->second));
                }
                // Update PQ - sorta
                // Greedy
            }
        }
        this->added_weight = added_weight;
    }
    
    void get_weight (int v) {
        cout << added_weight[v] << endl;
    }
    
};


class dijkstra_original {
    // Limitations:
    /*
        - Must have no negative edge weights at all
    */
    // Time complexity: O ((V+E) logV)
protected:
    list<pair<int, int> > AL[10];
    vector<int> added_weight;
    
    unordered_map<int, int> predecessor;
    int numv;
    
    
public:
    dijkstra_original (int size) {
        this->numv = size;
    }
    
    void connect (int v, int v2, int weight) {
        AL[v].push_back(make_pair(weight, v2));
        // This one uses an edge list
        
        // Need to initialise them all to int maximum
    }
    
    
    void perform_dijkstra (int source) {
        // Init a vector of sized numv all with values of 1000000
        vector<int> added_weight(numv, 1000000);
        
        // Notice we use a BST instead for this one
        set<pair<int, int> > q;
        // Init source to 0
        added_weight[source] = 0;
        q.insert(make_pair(0, source));
        
        while (!q.empty()) {
            pair<int, int> curr = q.begin();
            int current = curr.second;

            q.erase(q.begin());

            // This line is impt 
            if (added_weight[current] < curr.first) continue; 
            
            for (auto it = AL[current].begin(); it != AL[current].end(); it++) {
                
                // Relax
                int v = it->second;
                int weight_curr = added_weight[current];

                // We cannot flip this to find longest path algo, it will result in an infinite loop when there are +ve cycles
                if (added_weight[v] > weight_curr + it->first) {
                    added_weight[v] = weight_curr + it->first;
                    predecessor[v] = current;
                    q.insert(make_pair(added_weight[v], it->second));
                }
                // Update PQ - sorta
                // Greedy
            }
        }
        this->added_weight = added_weight;
    }
    
    void get_weight (int v) {
        cout << added_weight[v] << endl;
    }
    
};




// DFS - can be used for trees only, already O (V + E) because each vertice only has one unique path 

class DP {
    // Limitations:
    /*
        - Only on DAGs
    */
    // Time complexity: O ((V+E))
protected:
    int numv;
    list<pair<int, int>> AL[10];
    unordered_map<int, int> added_weight;
    unordered_map<int, int> predecessor;

    
    void DFS_recur (int vertex, unordered_map<int, int> *visited, list<int> * topo_list) {
        // Mark visited
        visited->insert(make_pair(vertex, 1));
        // Show its visits
        for (auto it = AL[vertex].begin(); it != AL[vertex].end(); it++) {
            // Traverse thru the columns on the same row
            if (visited->find(it->second) == visited->end()) {
                // unvisited vertex
                DFS_recur(it->second, visited, topo_list);
            }
            // Else skip it
        }
        // Finish DFS, add to back of list
        topo_list->push_back(vertex);
    }

    
    void relax (int v, int v2, int w) {
        if (added_weight[v2] > added_weight[v] + w) {
            added_weight[v2] = added_weight[v] + w;
            predecessor[v2] = v;
        }
    }


public:
    
    DP (int size) {
        this->numv = size;
    }
    
    
    void connect (int v, int v2, int weight) {
        AL[v].push_back(make_pair(weight, v2));
        added_weight[v] = 1000000;
        added_weight[v2] = 1000000;
        
    }
    
    void topo_sort_dfs (int v) {
        list<int> topo;
        unordered_map<int, int> visited;
        DFS_recur(v, &visited, &topo);
        topo.reverse();
        
        // One pass bellman ford 
        added_weight[v] = 0;
        while (!topo.empty()) {
            // Relax all outgoing edges for curr
            int curr = *topo.begin();
            topo.erase(topo.begin());
            for (auto it = AL[curr].begin(); it != AL[curr].end(); it++) {
                relax(curr, it->second, it->first);
            }
        }
    }
    
    
    void get_weight (int v) {
        cout << added_weight[v] << endl;
    }
    
    int get_distance (int source, int destination) {
        topo_sort_dfs(source);
        return added_weight[destination];
    }

};



// Some notes: 

/* Raw outline of all the graph algorithms we've learnt:
    DFS:
        1. Graph Traversal Algorithm
        2. Can be used for SSSP on weighted tree
        3. Used to count number of CCs, sizes of those CCs, Topological Sort on DAG
        4. Can check if we can reach from one source to destination
        5. Using AL: O (V + E), AM: O (V^2), EL: O(VE)
    BFS:
        1. Another Graph Traversal Algorithm
        2. Used for flood fill, number and size of CCs, Bipartite Graph Check
        3. Can solved SSSP on unweighted graph
        4. Can check if we can reach from one source to destination
        5. Using AL: O (V + E), AM: O (V^2), EL: O(VE)
    Modified Dijkstra:
        1. SSSP on Weighted Graph with negative weight
        2. Greedy Algorithm
        3. Uses a priority queue to store pairs of vertex information, employs Lazy Deletion
        4. Calculates shortest path from source vertex to all the other vertices reachable in the graph
        5. O ((V+E) log V)
    Bellman Ford:
        1. SSSP on Weighted Graph with negative weight cycle
        2. Can be used to detect presence of negative cycle
        3. Calculates shortest path from source vertex to all the other vertices reachable in the graph
        4. If Graph is a DAG, we can find toposort order using DFS, then run a one-pass Bellman Ford O (V + E) 
        5. O(VE)

*/
/* 
    1. Negative cycles can be a mixed cycle of positive weights and -ve weights. However, it is only a negative cycle when the sum of 
       all the weights in the cycle is NEGATIVE. If the sum of all the weights is greater than or equal to 0, it is just a regular cycle.


    2. Sequence of vertices such that when all the outgoing edges of these vertices are relaxed in this order using One-Pass Bellman-Ford's algorithm, 
       the SSSP problem can be solved in O(V+E) time.
       - Use topological sort kahn's technique to find. (Basically tackle those with no incoming edges first then delete edges and repeat step)
    

    3. Find D[V] after how many passes of bellman ford 
        - If the graph contains -ve edges to get to V then its infinity 
        - Else identify the number of possible paths to the destination from source first and see which one takes priority 

    4. Bellman ford killer 
        - Straight line L-shaped graph where 0th vertex connects to last vertex 

    5. Djikstra killer 
        - Triangles graph   
        
    6. Djikstra Appliaction
        - If you have two sets, set A and set B, and you are required to find the shortest distance from any node in set A to ANY node in set B,
        - Set a virtual node, called node V, and have it such that the weight from node V to every single node in set B is 0
        - Then run Djikstra from this virtual node V to find the shortest path
*/

