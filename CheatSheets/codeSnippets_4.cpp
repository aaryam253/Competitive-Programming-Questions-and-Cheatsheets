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


void SieveOfEratosthenes(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          cout << p << " "; 
}


// Check for prime numbers, the faster way

bool isPrime (long long num) {
    if (num == 2) return true;
    for(long long i=2; i < sqrt(num)+1; i++)
        if (num % i == 0)
            return false;
    
    return true;
}


// Majority element algorithm (streaming algorithm)

/* Function to find the candidate for Majority */
int findCandidate(int a[], int size) { 
    int maj_index = 0, count = 1; 
    for (int i = 1; i < size; i++) { 
        if (a[maj_index] == a[i]) 
            count++; 
        else
            count--; 
        if (count == 0) { 
            maj_index = i; 
            count = 1; 
        } 
    } 
    return a[maj_index]; 
} 
  
/* Function to check if the candidate 
   occurs more than n/2 times */
bool isMajority(int a[], int size, int cand) { 
    int count = 0; 
    for (int i = 0; i < size; i++) 
      
    if (a[i] == cand) 
    count++; 
          
    if (count > size/2) 
    return 1; 
      
    else
    return 0; 
} 


// String addition (no integers involved)
string addUp (string input1, string input2) {
    size_t n = max(input1.size(), input2.size());
    if (n > input1.size())
        input1 = string(n-input1.size(), '0') + input1;
    if (n > input2.size())
        input2 = string(n-input2.size(), '0') + input2;
    
    string result(n+1, '0');
    
    char carry = 0;
    
    std::transform(input1.rbegin(),input1.rend(),input2.rbegin(),
                   result.rbegin(),[&carry]( char x,  char y){
                       char z = (x-'0')+(y-'0') + carry;
                       if (z > 9)
                       {
                           carry = 1;
                           z -= 10;
                       }
                       else
                       {
                           carry = 0;
                       }
                       return z + '0';
                   });
    
    result[0] = carry + '0';
    
    n = result.find_first_not_of("0");
    if (n != string::npos)
    {
        result = result.substr(n);
    }
    
    return result;
}

