
// How do we use custom data structs and still have comparison abilities in sorting/ priority queue

// 1st method
struct special_int {
    int x;
    special_int(int _x) {
        x = _x;
    }
    // Create an operator overload
    bool operator < (const special_int& b) const {
        return x > b.x;
    }
};

// 2nd method - use pairs
auto i = make_pair(0, make_pair(1, 1)); // 0 will be used as the comparison integer



// Juggle priority 

int main () {
    priority_queue<pair<int, string > , vector<pair<int, string>>, greater<pair<int, string>>> juggle;
    juggle.push(make_pair(0, "CHINCHIN"));
    juggle.push(make_pair(0, "TSUNDERE"));
    
    // CHINCHIN will increase by 3 every iteration
    // TSUNDERE will increase by 5 every iteration.
    
    // Whichever has a smaller value will take priority first
    
    for (int i = 0; i < 5; i++) {
        auto out = juggle.top();
        cout << out.first << " " << out.second << endl;
        juggle.pop();
        if (out.second == "CHINCHIN") out.first += 3;
        else out.first += 5;
        
        juggle.push(out); // push it back
    }
}


// Convert int to string 

string itos(int i)  // convert int to string
{
    stringstream s;
    s << i;
    return s.str();
}


// Add multiple actions in a while loop while only caring about the last condition

int main () {
    int n, t;
    // This will only care about the second condition in the while loop, that is it will break when n == t
    while (scanf("%d %d", &n, &t), (n == t)) {
        // Perform operations here 
    }
}



// Custom comparator functions 

// Create the comparator function
// This will only compare the first value of the pairs
bool comparePairs (const pair<int, int> &lhs, pair<int, int> &rhs) {
    return lhs.first > rhs.first;
}

// Create the comparator function for sets
class compare {
public:
    bool operator()(const int lhs,const int rhs) const {
        return lhs > rhs; // When this is true, it will trigger the sort/ swap
    }
};

// Note that we cannot compare by the second of map similar to sets
class compare_map {
public:
    bool operator()(const int lhs,const int rhs) const {
        return lhs > rhs;
    }
};

// Compare only second value of PQ
class compare_pq {
public:
    bool operator()(const pair<int, int> lhs,const pair<int, int> rhs) const {
        return lhs.second > rhs.second;
    }
};


int main () {
    // Syntax 
    vector<pair<int, int > > test;
    set<int, compare> test_set;
    map<int, int, compare_map> test_map;
    priority_queue<pair<int, int>, vector<pair<int, int>> , compare_pq> test_pq;

}

// Unique identification and removal in hash table

void remove_key (int key, unordered_map<int, int> * myMap) {
    // If key does not exist, return
    if (myMap->find(key) == myMap->end()) return;
    // Remove the key
    myMap->at(key)--;
    // If key turns to ZERO, completely erase it
    if (myMap->at(key) == 0) {
        myMap->erase(key);
    }
}


int main () {
    unordered_map<int, int> countUnique;
    
    for (int i = 0 ; i < 6; i++) {
        countUnique[testcase[i]]++;
    }
    cout << countUnique.size() << endl; // 4 unique values

    remove_key(3, &countUnique);
    remove_key(3, &countUnique);

    cout << countUnique.size() << endl; // Only 3 unique values left
}


// Calculate sum of numbers - without sorting 

int calculate () {
    int testcase [6] = {1,3,2,5,3,1}, number_i_want;
    unordered_map<int, int> number_count;
    number_i_want = 4;
    // TODO: Write algo for determining sum of pairs using hash table
    for (int i = 0; i < 6; i++) {
        number_count[testcase[i]]++;
        if (number_count.find(number_i_want - testcase[i]) != number_count.end()) {
            cout << "Found: ";
            cout << number_count.find(number_i_want - testcase[i])->first << " ";
            cout << testcase[i] << endl;
        }
    }

}

// Sum of bits to calculate parity 

short test = 100; // 1100100

int main () {
    int bits = 8; // num of bits
    
    short mask = 0b1000000; // 8 bit max
    int count = 0;
    while (bits--, bits >= -1) {
        if (test & mask) count++;
        mask >>= 1;
    }
    cout << count << endl; // Output sum of 1's bits 

}


// Cutting edges that exceed a certain k-val using BFS 

void BFS (int vertex, int k, int dest) {
    AL = AL_prime; // We do not wish to affect the original graph
    unordered_map<int, int> visited;
    queue<int> q;
    int curr = vertex;
    q.push(curr); // Initial push
    visited[curr] = 1; // Mark as visited
    vector<int> distances (V, 1);
    
    while (!q.empty()) {
        curr = q.front();
        q.pop();
        visited[curr] = 1;
        //cout << curr << " " << distances[curr] << endl;
        if (distances[curr] + 1 >= k) {
            for (auto it = AL[curr].begin(); it != AL[curr].end();) {
                if (it->second != dest || distances[curr] + 1 > k) {
                    cout << "cut: " << curr << " " << it->second << endl;
                    it = AL[curr].erase(it);
                }else {
                    it++;
                }
            }
            
        }else {
            for (auto it = AL[curr].begin(); it != AL[curr].end(); it++) {
                if (visited.find(it->second) == visited.end()) {
                    distances[it->second] = distances[curr] + 1;
                    q.push(it->second);
                }
            }
        }
    }    
}


// Search surroundings - without repeating yourself 

void search_surrounding (int arr[MAX][MAX], int x, int y) {
    int i, d;
    for (i = -1; i < 2; i++) {
        for (d = -1; d < 2; d++) {
            if (x+d < col && x+d >= 0 && y+d < row && x+d >= 0) {
                if (i == 0 && d == 0) {
                // position is at original coords
                }else {
                    printf("%d ", arr[y+i][x+d]);
                }
            }
        }
    }
    printf("\n");
}
