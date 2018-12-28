// Dikjstra largest factor algorithm 
void perform_dijkstra (int source, int numv, int dest) {
        // Init a vector of sized numv all with values of 1000000
    vector<long double> added_weight(numv, 1000000);

    // Notice we use a BST instead for this one
    set<pair<long double, int> > q;
    // Init source to 0
    added_weight[source] = 0;
    q.insert(make_pair(0, source));

    while (!q.empty()) {
        int current = q.begin()->second;
        q.erase(q.begin());

        for (auto it = AL[current].begin(); it != AL[current].end(); it++) {

            // Relax
            int v = it->second;
            long double weight_curr = added_weight[current];

            // -log10 for larger factor when fraction is smaller
            if (added_weight[v] > weight_curr + -log10(it->first)) {
                added_weight[v] = weight_curr + -log10(it->first);
                q.insert(make_pair(added_weight[v], it->second));
            }
        }
    }
    return added_weight[dest];
}


// Floyd warshall algo
// Time complexity: O(V^3) constant
void floydWarshall (int graph[][V])
{
    /* dist[][] will be the output matrix that will finally have the shortest 
      distances between every pair of vertices */
    int dist[V][V], i, j, k;

    /* Initialize the solution matrix same as input graph matrix. Or 
       we can say the initial values of shortest distances are based
       on shortest paths considering no intermediate vertex. */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    /* Add all vertices one by one to the set of intermediate vertices.
      ---> Before start of a iteration, we have shortest distances between all
      pairs of vertices such that the shortest distances consider only the
      vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
      ----> After the end of a iteration, vertex no. k is added to the set of
      intermediate vertices and the set becomes {0, 1, 2, .. k} */
        for (k = 0; k < V; k++)
        {
        // Pick all vertices as source one by one
            for (i = 0; i < V; i++)
            {
            // Pick all vertices as destination for the
            // above picked source
                for (j = 0; j < V; j++)
                {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    // Print the shortest distance matrix
        printSolution(dist);
    }


// Dijkstra on a grid mtx where you have to derive your own weights 
// This cannot be substituted by BFS as the vertices are grid points and they do not account for rotation.
// Rotation and moving forward is used as edges which could vary when transitioning between vertices
    void perform_dijkstra (char mtx[][20], int row, int col) {
        int direction_mtx[row][col];
        int addedweights[row][col];
        for (int i = 0; i < row; i++) {
            for (int d = 0; d < col; d++) {
                direction_mtx[i][d] = -1;
            addedweights[i][d] = 1000000; // inf
        }
    }
    
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int , int> > >, greater<>> q;
    direction_mtx[0][0] = 1; // Robot's initial direction is facing west
    addedweights[0][0] = 0;
    q.push(make_pair(0, make_pair(0, 0)));
    while (!q.empty()) {
        int dx[4] = {0,1,0,-1};
        int dy[4] = {-1,0,1,0};
        pair<int, pair<int, int>> curr = q.top();
        q.pop();
        int curr_x = curr.second.first;
        int curr_y = curr.second.second;
        for (int i = 0; i < 4; i++) {
            if (curr_x + dx[i] >= 0 && curr_x + dx[i] < col && curr_y + dy[i] >= 0 && curr_y + dy[i] < row) {
                // Termination conditions: if node is visited before, if node is an obstacle
                if (direction_mtx[curr_y + dy[i]][curr_x + dx[i]] > -1) continue;
                if (mtx[curr_y + dy[i]][curr_x + dx[i]] == '#') continue;
                // Constraint, robot can only rotate rightwards
                int rotation = 0;
                if (i > direction_mtx[curr_y][curr_x]) rotation = i - direction_mtx[curr_y][curr_x];
                else if (i < direction_mtx[curr_y][curr_x]) rotation = (4 - direction_mtx[curr_y][curr_x]) + i;
                
                if (addedweights[curr_y + dy[i]][curr_x + dx[i]] > addedweights[curr_y][curr_x] + rotation*2 + 3) {
                    direction_mtx[curr_y + dy[i]][curr_x + dx[i]] = i;
                    addedweights[curr_y + dy[i]][curr_x + dx[i]] = addedweights[curr_y][curr_x] + rotation*2 + 3;
                    q.push(make_pair(addedweights[curr_y][curr_x] + abs(i - direction_mtx[curr_y][curr_x])*2 + 3,
                       make_pair(curr_x + dx[i], curr_y + dy[i])));
                }
            }
        }
    }
    
    cout << addedweights[row-1][col-1] << endl;
    
}


// DFS/ BFS with limits
list<int> AL[10];
unordered_set<int> visited;
int limit;

void dfs (int v, int dist) {
    if (visited.find(v) != visited.end()) return;
    if (dist >= limit) return;
    visited.insert(v);

    for (auto it : AL[v])
    {
        dfs(v, dist + 1);
    }
}

void bfs (int v, int limits) {
    queue<pair<int, int> > q;
    q.push(make_pair(v, 0));

    while(!q.empty()) {
        pair<int, int> curr = q.front();

        if (curr.second >= limit) continue;

        visited.insert(curr.first);

        for (auto it : AL[curr.first])
        {
            if (visited.find(it) == visited.end()) 
                q.push(make_pair(it, curr.second + 1));
        }
    }
}


// Bipartite checker
// O (V(V + E))
void Bipartite_checker_wilson (list<int> AL[], int v) {
    for (int i = 0; i < v; i++) {
        unordered_map<int, int> colouring;
        // Check by colouring the graph and see if it reaches the same colour twice
        queue<int> q;
        q.push(i);
        colouring[i] = 1;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto it : AL[curr]) {
                if (colouring.find(it) == colouring.end() && colouring[curr] == 1) {
                    colouring[it] = 2;
                    q.push(it);
                }
                else if (colouring.find(it) == colouring.end() && colouring[curr] == 2) {
                    colouring[it] = 1;
                    q.push(it);
                }
                else if (colouring[it] == colouring[curr]) {
                    cout << "not bipartite" << endl;
                    return;
                }
            }
        }
    }
}

void Bipartite_checker (int v, list<int> AL[]) {
    vector<int> colouring (v, -1);

    // This is to handle disconnected graphs
    for (int i = 0; i < v; i++) {
        // We only initate the BFS when its not been coloured before
        if (colouring[i] == -1) {
            queue<int> q;
            q.push(i);
            // Only assign a colour when it doesnt have one
            colouring[i] = 1;
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (auto it : AL[curr]) {
                    if (colouring[it] == -1) {
                        colouring[it] = 1 - colouring[curr];
                        q.push(it);
                    }else if (colouring[it] == colouring[curr]) {
                        // If colouring of current is the same as its neighbours, means its not bipartite 
                        cout << "non bipartite" << endl;
                        return;
                    }
                }
            }
        }
    }

}


// BFS to find shortest path in a maze/ grid 
// O (V + E) (faster than dijkstra as no operations needed to extract from a pq)

// Assuming grid size is 10 by 10
void bfs_maze (char grid[10][10], pair<int, int> start, pair<int, int> end) {
    queue<pair<int, int> > q;
    q.push(start);
    vector<vector<int> > added_weights(10, vector<int> (10, 100000));
    
    added_weights[start.second][start.first] = 0;
    
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int dx [4] = {0,1,0,-1};
        int dy [4] = {1,0,-1,0};
        for (int i = 0; i < 4; i++) {
            if (curr.first + dx[i] < 10 && curr.first + dx[i] >= 0 && curr.second + dy[i] >= 0 && curr.second + dy[i] < 10) {
                // If it is an obstable, ignore everything
                if (mtx[curr.second + dy[i]][curr.first + dx[i]] == '#' ) continue;
                
                if (added_weights[curr.second + dy[i]][curr.first + dx[i]] == 100000) {
                    // unvisited and not an obstable
                    if (added_weights[curr.second + dy[i]][curr.first + dx[i]] > added_weights[curr.second][curr.first] + 1) {
                        // Relax
                        added_weights[curr.second + dy[i]][curr.first + dx[i]] = added_weights[curr.second][curr.first] + 1;
                        q.push(make_pair(curr.first + dx[i], curr.second + dy[i]));
                    }
                }
            }
        }
    }
    
    for (auto it : added_weights) {
        for (auto it2 : it) {
            if (it2 == 100000) cout << "INF";
            else cout << it2;
            cout << "\t";
        }
        cout << endl;
    }

    cout << added_weights[end.second][end.first] << endl;
}
// Input: 
/*
..........
..........
.s........
......e...
..........
##########
..........
..........
..........
..........
*/

// Output: 
/*
3   2   3   4   5   6   7   8   9   10  
2   1   2   3   4   5   6   7   8   9   
1   0   1   2   3   4   5   6   7   8   
2   1   2   3   4   5   6   7   8   9   
3   2   3   4   5   6   7   8   9   10  
INF INF INF INF INF INF INF INF INF INF 
INF INF INF INF INF INF INF INF INF INF 
INF INF INF INF INF INF INF INF INF INF 
INF INF INF INF INF INF INF INF INF INF 
INF INF INF INF INF INF INF INF INF INF     
*/


// Topo sort DFS + One pass bellman ford - find longest path (DAG)
// O (V + 2E)
list<pair<int, int> > AL[10000];

void DFS_recur (int vertex, unordered_map<int, int> *visited, list<int> * topo_list) {
    // Mark visited
    visited->insert(make_pair(vertex, 1));
    // Show its visits
    for (auto it : AL[vertex]) {
        if (visited->find(it.second) == visited->end()) {
            DFS_recur(it.second, visited, topo_list);
        }
    }
    // Finish DFS, add to back of list
    topo_list->push_back(vertex);
}

list<int> topo_sort_dfs (int v) {
    list<int> topo;
    unordered_map<int, int> visited;
    DFS_recur(v, &visited, &topo);
    topo.reverse();
    return topo;
}

void one_pass (list<int> sorted, int V) {
    vector<int> added_weights (V, -100000); // We use negative INF instead
    added_weights[0] = 0;
    
    for (auto curr : sorted) {
        for (auto it2 : AL[curr]) {
            // To find the max of combined weights
            if (added_weights[it2.second] < added_weights[curr] + it2.first) {
                added_weights[it2.second] = added_weights[curr] + it2.first;
            }
        }
    }
}


// Next permutation
void permutation () {
    int arr[5] = {1,2,3,4,5};
    
    int count = 0;
    while (next_permutation(arr, arr + 5)) {
        for (auto it :  arr) {
            cout << it << " ";
        }
        cout << endl;
        count++;
    }
    // Will output every permutation of this array 
    cout << count << endl; // Total permutation = 120 (5P5)
}


// Partial sort 
int main () {
    vector<int> myints ({5,4,3,2,1,1,2,3});
    
    partial_sort(myints.begin(), myints.begin()+ 2, myints.end());
    for (auto it : myints) {
        cout << it << " ";
    }
    cout << endl;
    // Output: 1 1 5 4 3 2 2 3
    // Only the first 2 elements got sorted and swapped
    
    /////////////////////////////////////////////////////////////
    sort(myints.begin(), myints.begin() + 2);
    for (auto it : myints) {
        cout << it << " ";
    }
    cout << endl;
    // Output: 4 5 3 2 1 1 2 3
    // Only the first 2 elements got sorted without taking into account the entire array
}



// Water jug problem 
void bfs_everchanging (int target, int a, int b, int c) {
    tuple<int, int, int> initial ({0,0,0});
    set<tuple<int, int, int> > visited;
    queue<tuple<int, int, int> > q;
    map<tuple<int, int, int>, int> steps;
    steps[initial] = 0;
    q.push(initial);
    
    while (!q.empty()) {
        tuple<int, int, int> curr = q.front();
        q.pop();
        visited.insert(curr);
        int curr_a = get<0>(curr);
        int curr_b = get<1>(curr);
        int curr_c = get<2>(curr);
        
        int da[12] =  {0, curr_a, curr_a, a, curr_a, curr_a, curr_a-curr_b, curr_b+curr_a, curr_a-curr_c, curr_c+curr_a, curr_a, curr_a};
        int db[12] =  {curr_b, 0, curr_b, curr_b, b, curr_b, curr_a+curr_b, curr_b-curr_a, curr_b, curr_b, curr_b-curr_c, curr_c+curr_b};
        int dc[12] =  {curr_c, curr_c, 0, curr_c, curr_c, c, curr_c, curr_c, curr_a+curr_c, curr_c-curr_a, curr_b+curr_c, curr_c-curr_b};
        
        // Focal point: Nodes were not defined at the start, they were defined only while it is BFS-ing. This allows for an expanding graph of possibilities
        // Wont run into infinite loop as we have a visited set to keep track.
        for (int i = 0; i < 12; i++) {
            // Duplication point        
            if (i == 6){
                if (da[i] < 0 && db[i] > b) {
                    da[i] = db[i]-b;
                } else if (da[i] < 0) {
                    db[i] += da[i];
                    da[i] = 0;
                } else if (db[i] > b) {
                    da[i] = db[i] - b;
                    db[i] = b;
                }
            }
            // Now write the rest for the transfer of other jugs....


            tuple<int, int, int> modified ({da[i], db[i], dc[i]});
            if (visited.find(modified) == visited.end()) {
                q.push(modified);
                steps[modified] = steps[curr] + 1;
            }else if (steps[modified] > steps[curr] + 1) {
                q.push(modified);
                steps[modified] = steps[curr] + 1;
            }

        }

    }
    // Search and find those with a == d and print out the one with the smallest steps[].
    // If visited set does not conntain any tuple with a == d, means its not possible 
}


// Multiple shortest paths 
// Can only find equal shortest paths
list<pair<int, int> > AL[300];
int numv;


void perform_dijkstra (int source) {
    // Init a vector of sized numv all with values of 1000000
    vector<stack<int> > added_weight(numv);
    for (int i = 0; i < numv; i++) {
        added_weight[i].push(1000000);
    }
    
    priority_queue<pair<int, int>, vector<int, int>, greater<> > q;
    // Init source to 0
    added_weight[source].push(0);
    q.push(make_pair(0, source));
    
    while (!q.empty()) {
        pair<int, int> curr = q.top();
        int current = curr.second;
        q.pop();
        
        // If added weight is smaller than weight itself, don't process
        if (added_weight[current].top() < curr.first) continue;
        
        for (auto it = AL[current].begin(); it != AL[current].end(); it++) {
            // Relax
            if (added_weight[it->second].top() > added_weight[current].top() + it->first) {
                added_weight[it->second].pop(); // Pop out the older value
                added_weight[it->second].push(added_weight[current].top() + it->first);
                // Keeps pushing into the pq, may contain duplicates
                q.push(make_pair(added_weight[it->second].top(), it->second));
            }else if (added_weight[it->second].top() == added_weight[current].top() + it->first) {
                // Dont need to pop off here.
                added_weight[it->second].push(added_weight[current].top() + it->first);
                // Keeps pushing into the pq, may contain duplicates - to handle negative weights as well
                q.push(make_pair(added_weight[it->second].top(), it->second));
            }
        }
    }
    
    cout << added_weight['F'].size() << endl; // 2 shortest paths detected
    while (!added_weight['F'].empty()) {
        cout << added_weight['F'].top() << " ";
        added_weight['F'].pop();
    }
    // Output: 15, 15
    cout << endl;
}


int main () {
    // Simulating two paths with same total weights
    numv = 300;
    AL['A'].push_back(make_pair(5, 'B'));
    AL['A'].push_back(make_pair(5, 'D'));
    AL['B'].push_back(make_pair(5, 'C'));
    AL['C'].push_back(make_pair(5, 'F'));
    AL['D'].push_back(make_pair(5, 'E'));
    AL['E'].push_back(make_pair(5, 'F'));
    AL['A'].push_back(make_pair(30, 'F')); // Another path from A -> F of larger weights 
    AL['F'].push_back(make_pair(0, 'A')); // Cycle from F -> A
    
    perform_dijkstra('A'); // A is our source
}




// Double flood fill 
int mtx[600][600], mtx_prime[600][600];
int col, row;


bool check (stack<pair<int, int> > * check_points, stack<pair<int, int> > *converted_checkpoints, int number) {
    bool lower = false;
    while (!check_points->empty()) {
        converted_checkpoints->push(check_points->top());
        pair<int, int> curr = check_points->top();
        check_points->pop();
        mtx_prime[curr.second][curr.first] = 0;
        //cout << mtx[curr.second][curr.first] << endl;
        int x = curr.first;
        int y = curr.second;
        int dx [4] = {0, 1, 0, -1};
        int dy [4] = {1, 0, -1, 0};
        for (int i = 0; i < 4; i++) {
            if (x + dx[i] < col && y + dy[i] < row && x + dx[i] >= 0 && y + dy[i] >= 0) {
                if (mtx[y+dy[i]][x+dx[i]] == number && mtx_prime[y+dy[i]][x+dx[i]] == -1) {
                    check_points->push(make_pair(x+dx[i], y + dy[i]));
                }else if (mtx[y+dy[i]][x+dx[i]] < number) {
                    lower = true;
                }
            }
        }
    }
    //lower ? cout << "true" << endl : cout << "false" << endl;
    return lower;
}



void dfs_recur (int x, int y) {
    mtx_prime[y][x] = 0; // 0 means visited but not collection point
    int dx [4] = {0, 1, 0, -1};
    int dy [4] = {1, 0, -1, 0};
    bool moves = false;
    for (int i = 0; i < 4; i++) {
        if (x + dx[i] < col && y + dy[i] < row && x + dx[i] >= 0 && y + dy[i] >= 0) {
            if (mtx[y][x] > mtx[y+dy[i]][x+dx[i]]) {
                moves = true;
                if (mtx_prime[y + dy[i]][x + dx[i]] == -1) {
                    dfs_recur(x + dx[i], y + dy[i]);
                }
            }else if (mtx[y][x] == mtx[y + dy[i]][x + dx[i]] && mtx_prime[y + dy[i]][x + dx[i]] == -1) {
                
                // Found a similar node, flood fill that to find out if its a dead end or it can flow elsewhere :/ *******
                
                stack< pair<int, int> > check_points, converted_checkpoints;
                check_points.push(make_pair(x, y));
                if (check(&check_points, &converted_checkpoints, mtx[y][x]) == false) {
                    while (!converted_checkpoints.empty()) {
                        pair<int, int> curr = converted_checkpoints.top();
                        converted_checkpoints.pop();
                        mtx_prime[curr.second][curr.first] = 1;
                    }
                }else{
                    moves = true;
                }
            }
        }
    }
    
    if (!moves) {
        mtx_prime[y][x] = 1;
    }
}


void dfs (int x, int y) {
    dfs_recur(x, y);
}


// DAG Maker 
// Total time complexity: O(V+E)
// Limitations: Cannot be used to find multiple paths, esp when there are two edges from node A -> B
list<pair<int, int> > AL[500];
list<pair<int, int> > AL_backup[500]; // To backup the original AL
list<int > AL_dag[500]; // unweighted DAG

// O (V+E)
void dag_maker (int v, int dest) {
    unordered_set<int> visited;
    stack<int> s;
    s.push(v);
    
    while (!s.empty()) {
        int curr = s.top();
        //cout << (char)curr << endl;
        s.pop();
        visited.insert(curr);
        
        // In this case we do not need to iterate thru all the neighbours and push to stack
        if (!AL[curr].empty()) {
            for (auto it : AL[curr]) {
                // Attempt to find the first non visited node from the list of edges here
                if (visited.find(it.second) == visited.end()) {
                    s.push(it.second);
                    
                    AL_dag[curr].push_back(it.second);
                    AL[curr].erase(AL[curr].begin()); // This will erase parts of the original graph so make sure to keep a copy
                    if (it.second == dest) return; // Return the moment we find destination
                    break;
                }
            }
        }
    }
}

void dag_handler (int src, int dest) {
    // Copy first
    for (int i = 0; i < 500; i++) {
        AL_backup[i] = AL[i];
    }
    
    // If the src still has any edges left 
    while (!AL[src].empty())
        dag_maker (src, dest);

}



// Topo sort DFS + One pass bellman ford - find shortest path with < k nodes (DAG)
// O(V+E)
void dfs_topo (int vertex, unordered_set<int> *visited, list<int> * topo_list) {
    // Mark visited
    visited->insert(vertex);
    // Show its visits
    // Find AL_dag from the algo above
    for (auto it : AL_dag[vertex]) {
        if (visited->find(it.second) == visited->end()) {
            dfs_topo(it.second, visited, topo_list);
        }
    }
    // Finish DFS, add to back of list
    topo_list->push_back(vertex);
}

void one_pass (int source, int dest, int k) {
    unordered_set<int> visited;
    list<int> topo_list;
    vector<int> added_weight (500, 1000000);
    
    dfs_topo(source, &visited, &topo_list);
    topo_list.reverse();
    
    added_weight[source] = 0;
    
    // Limit this one pass to < k nodes
    for (int i = 0; i < k; i++) {
        int curr = topo_list.front();
        topo_list.pop_front();
        for (auto it : AL[curr]) {
            // Relax
            if (added_weight[it.second] > added_weight[curr] + it.first) {
                added_weight[it.second] = added_weight[curr] + it.first;
            }
        }
    }
    cout << added_weight[dest] << endl;
}


// Path tracing on a 2D grid 
void pathfinding () {
    int added_weights [R][C];
    pair<int, int> predecessor [R][C]; // We use a pair 2D matrix of predecessors 
    // so that each cell can store the coords of its predecessors 

    ////////////// Rest of BFS code 

    // Process the predecessor 2D grid to trace back 
}


// Count possible paths WARNING: Only applies to DAG as it does not use a visited set

void dfs_count (int vertex, unordered_map<int, int> *count) {
    for (auto it : AL_dag[vertex]) {
        // Notice no visited set 
        count->operator[](it)++;
        dfs_topo(it, visited, topo_list, count);
    }
}

void dfs_handler () {
    unordered_map<int, int> count;
    dfs_count('A', &count);

    cout << unordered_map['A'] << endl;
}

// To make it visit only unique paths (Do not visit the same vertex twice)
void dfs_topo (int vertex, unordered_set<int> *visited, unordered_map<int, int> *count) {
    // Mark visited
    visited->insert(vertex);
    for (auto it : AL_dag[vertex]) {
        count->operator[](it)++;
        // So it will only go thru each vertex once, discarding all paths that go thru the same vertex
        if (visited->find(it) == visited->end())
            dfs_topo(it, visited, topo_list, count);
    }
}


void dfs_handler () {
    unordered_map<int, int> count;
    unordered_set<int> visited;
    dfs_count('A', &visited,  &count);

    cout << unordered_map['A'] << endl;
}

// Note there are inifnite paths in a graph with cycle
// We can also use BFS to count number of paths to a point 

// A generic LIS (Longest Increasing Subsequence) code, which finds the size of the LIS starting at indices i, ∀ i ∈ [0, n-1]
void calculate_LIS(int arr[], int n) {
     vector<int> lis(n, 1); // stores all LIS values, initialise all values with 1 as each element is an LIS of size 1
     for (int i = n-1; i >= 0; i--) {
             for (int j = i+1; j < n; j++) {
                     if (arr[i] > arr[j] && lis[i] < lis[j] + 1) lis[i] = lis[j] + 1;
             }
     }
}

// A generic LDS (Longest Decreasing Subsequence) code, which finds the size of the LDS starting at indices i, ∀ i ∈ [0, n-1]
void calculate_LDS(int arr[], int n) {
     vector<int> lds(n, 1); // stores all LDS values, initialise all values with 1 as each element is an LDS of size 1
     for (int i = n-1; i >= 0; i--) {
             for (int j = i+1; j < n; j++) {
                     if (arr[i] < arr[j] && lds[i] < lds[j] + 1) lds[i] = lds[j] + 1;
             }
     }
}

// Code to generate LBS (Longest Bitonic Subsequence) __--``--__ OR ``--__--`` (Hill or valley style subsequence)
void calculate_LBS(int arr[], int n) {
        vector<int> lis(n, 1); // assume LIS values have been calculated ∀ i ∈ [0, n-1]
        vector<int> lds(n, 1); // assume LDS values have been calculated ∀ i ∈ [0, n-1]
        
        // LBS is defined as max(LIS(i) + LDS(i) - 1), ∀ i ∈ [0, n-1]
        int lbs = 0;
        for (int i = 0; i < n; i++) {
                lbs = max(lbs, lis[i] + lds[i] - 1);
        }
}
