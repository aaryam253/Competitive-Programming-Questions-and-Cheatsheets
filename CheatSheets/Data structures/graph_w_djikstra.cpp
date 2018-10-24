class Graph {
private:
    int V;
    typedef pair<int, int> vertex;
    list<pair<int, int> > *adj_weight;
public:
    Graph (int size) {
        V = size;
        adj_weight = new list<vertex> [V]; // array of lists
    }
    
    void makePair (int u, int v, int w) {
        // u = vertice 1
        // v = vertice 2
        // w = weight
        adj_weight[v].push_back(make_pair(w, u));
        adj_weight[u].push_back(make_pair(w, v));
    }
    
    void printWeights () {
        for (int i = 0; i < V; i++) {
            if (!adj_weight[i].empty()) {
                printf("Node: %d\n", i);
                printf("----------------------\n");
                for (auto d = adj_weight[i].begin(); d != adj_weight[i].end() ; d++) {
                    printf("%d %d\n", d->second, d->first);
                }
                printf("----------------------\n");
            }
            
        }
    }
    
    int generateShortestPath (int src, int dest) {
        // Note: We will indirectly find the shortest distance to all the nodes in the process
        
        priority_queue< vertex, vector <vertex> , greater<vertex> > pq;
        vector<int> dist(V, INF); // Initialise all vertices distances to infinite
        pq.push(make_pair(0, src)); // 0 weight
        dist[src] = 0;

        
        while (!pq.empty())
        {
            
            int u = pq.top().second;
            pq.pop();
            
            // 'i' is used to get all adjacent vertices of a vertex
            for (auto i = adj_weight[u].begin(); i != adj_weight[u].end(); ++i)
            {
                // Get vertex label and weight of current adjacent
                // of u.
                int v = i->second;
                int weight = i->first;
                
                //  If there is shorter path to v through u.
                
                // Extremely crucial
                if (dist[v] > dist[u] + weight)
                {
                    // Updating distance of v
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        return dist[dest];
    }
    
};