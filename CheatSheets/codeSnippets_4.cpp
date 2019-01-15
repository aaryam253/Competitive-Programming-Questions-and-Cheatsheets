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
                ways[it.second] = ways[current]; // Replace replace with the true shortest path if combined weight is smaller
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

// Find min swaps in an array, swaps need not be adjacent to each other

int minSwaps(int arr[], int n) 
{ 
    // Create an array of pairs where first 
    // element is array element and second element 
    // is position of first element 
    pair<int, int> arrPos[n]; 
    for (int i = 0; i < n; i++) 
    { 
        arrPos[i].first = arr[i]; 
        arrPos[i].second = i; 
    } 
  
    // Sort the array by array element values to 
    // get right position of every element as second 
    // element of pair. 
    sort(arrPos, arrPos + n); 
  
    // To keep track of visited elements. Initialize 
    // all elements as not visited or false. 
    vector<bool> vis(n, false); 
  
    // Initialize result 
    int ans = 0; 
  
    // Traverse array elements 
    for (int i = 0; i < n; i++) 
    { 
        // already swapped and corrected or 
        // already present at correct pos 
        if (vis[i] || arrPos[i].second == i) 
            continue; 
  
        // find out the number of  node in 
        // this cycle and add in ans 
        int cycle_size = 0; 
        int j = i; 
        while (!vis[j]) 
        { 
            vis[j] = 1; 
  
            // move to next node 
            j = arrPos[j].second; 
            cycle_size++; 
        } 
  
        // Update answer by adding current cycle.  
        if (cycle_size > 0) 
        { 
            ans += (cycle_size - 1); 
        } 
    } 
  
    // Return result 
    return ans; 
} 


// Count number of swaps in O(NlogN), only adjacent swaps are allowed

long long swaps = 0;

void merge(long long arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    
    /* create temp arrays */
    long long L[n1], R[n2];
    
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            
            arr[k] = L[i];
            i++;
        }
        else
        {
            swaps += n1 - i; // Swap with the remaining guys from the first side*********
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    /* Copy the remaining elements of L[], if there
     are any */
    while (i < n1)
    {
//        swaps++;
        arr[k] = L[i];
        i++;
        k++;
    }
    
    /* Copy the remaining elements of R[], if there
     are any */
    while (j < n2)
    {
//        swaps++;
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
 sub-array of arr to be sorted */
void mergeSort(long long arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        
        merge(arr, l, m, r);
    }
}

// To set a precision point eg. 2 decimal placing

cout << fixed << setprecision(2) << y << endl;


// Linear Algorithms and examples - For Mini 01

// 1. Bracket Matching (Use a stack) - O(n)
/* function to check if paranthesis are balanced
    in any string expression */
bool isBalanced(string expression) {
    stack<char> s;
    char x;

    // scan through expression
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i]=='('||expression[i]=='['||expression[i]=='{') {
            // push element in stack
            s.push(expression[i]);
            continue;
        }
        // If current character is not opening bracket, it must be a 
        // closing bracket. So stack cannot be empty at this point
        switch(expression[i]) {
            case ')':
                // check whether top of stack is pair of current closing bracket
                x = s.top();
                s.pop();
                if (x == '{' || x == '[') return false;
                break;

            case ']':
                // check whether top of stack is pair of current closing bracket
                x = s.top();
                s.pop();
                if (x == '{' || x == '(') return false;
                break;

            case '}':
                // check whether top of stack is pair of current closing bracket
                x = s.top();
                s.pop();
                if (x == '[' || x == '(') return false;
                break;
        }
    }

    // check whether stack is empty -- if no. of characters is odd, cannot be balanced anyway
    return (s.empty());
}

// 2. Inversion Index - O(n log n)



// 3. Postfix Calculator and Conversion (Shunting yard)




// 4. (Static) Selection Problem




// 5. Sorting in Linear Time




// 6. Sliding Window




// 7. Max 1D Range Sum/Kadane's Algorithm




// 8. LIS - O(n log k)




// 9. Graham Scan's algorithm





