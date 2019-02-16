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

    //NOTE: Change to vector as a boolean array can give MLE...
    vector<bool> prime(n+1, true);
  
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

// Finding GCD and LCM of numbers a and b --> Runs in O(log n) where n = max(a,b)

/*GCD of more than two numbers have be found by calling gcd multiple times
  e.g. gcd(a,b,c) = gcd(a, gcd(b,c)) */
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int lcm(int a, int b) {
    return a / gcd(a,b) * b;
}

// Printing a number to a certain number of decimal points by manipulating the field width
int print_pi_to_ndecimals() {
    double pi = 2*acos(0.0);
    int n; scanf("%d", &n);
    printf("%. *lf\n", n, pi);
}

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
/*
Problem asks for minimum no. of bubble sorts swaps required to make a list sorted. Can be done by modifying
merge sort. 

(i) If the front of the right sorted sublist is taken first rather than the front of the left sorted sublist,
we say that 'inversion occurs'. 
(ii) Add inversion index counter by the size of the current left sublist
*/

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

// 3. Postfix Calculator and Conversion (Shunting yard) - Both O(n)

/*Postfix calculator runs in O(n) using the following algorithm:
(i) Start with an empty stack and scan the expression from left to right
(ii) Each time an operand is found, push it to the stack
(iii) When an operation is found, pop the top two items of the stack, perform the operation, then push the result in the stack
(iv) When all tokens have been read, output the top of the stack*/

int result(char expression, int a, int b) {
    switch(expression) {
        case '+':
            return a+b;
            break;
        case '-':
            return b-a;
            break;
        case '*':
            return a*b;
            break;
        case '/':
            return b/a;
            break;
        default:
            return 0;
            break;
    }
    
    return 0;
}

void Postfix_Calculator(string expression) {
    stack<int> s;
    for (int i = 0; i < expression.length(); i++) {
        if (!isdigit(expression[i])) {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            
            s.push(result(expression[i], a, b));
        } else {
            s.push(expression[i] - '0');
        }
    }
    
    cout << s.top() << endl;
}


/*Prefix calculator is exactly the same as postfix, except the expression is read
  from right to left instead of left to right, still an O(n) algorithm */
void Prefix_Calculator(string expression) {
    stack<int> s;
    for (int i = expression.length() - 1; i >= 0; i--) {
        if (!isdigit(expression[i])) {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            
            s.push(result(expression[i], a, b));
        } else {
            s.push(expression[i] - '0');
        }
    }
    
    cout << s.top() << endl;
}


// 4. (Static) Selection Problem


/*Problem of finding the k-th smallest element of an array of n elements, also known as order statistics.
  Proposed solution is to use the O(n) partition algorithms from QuickSort */

int QuickSelect(int A[], int l, int r, int k) {
    if (l == r) return A[1];
    int q = RandomizedPartition(A, l, r);
    if (q+1 == k) return A[q];
    else if (q+1 > k) return QuickSelect(A, l, q-1, k);
    else return QuickSelect(A, q+1, r, k);
 }


/*Overall complexity is O(n + n/2 + n/4 + ... + n/n) <= O(2n) = O(n), very unlikely to hit worst case of O(N^2)
  Built in C++ STL: nth_element in <algorithm> */

// 5. Sorting in Linear Time

/*
(i) One solution is Counting Sort if there are n integers in a small range [L..R]
(ii) Radix sort when there are n non-negative integers with relatively wide range [L..R] but relatively small no. of digits
*/

 //Assumption: Number of digits of largest integer known
void radix_sort(int arr[], int len)
{
    unsigned int maxDigits=0;
    vector <string> nums (len);
    for (int i=0; i<len; i++)
    {
        nums[i] = to_string(arr[i]);
        if (nums[i].length() > maxDigits)
            maxDigits = nums[i].length(); //Figuring out maxDigits
    }
    
    //padding with 0
    for (int j=0; j<len; j++)
    {
        while (nums[j].length() < maxDigits)
            nums[j] = "0" + nums[j];
    }
    
    
    vector <queue<string>> myQ (10);
    for (int j=0; j<maxDigits; j++) //Iterates over the whole array maxDigits times
    {
        for (int k=0; k<len; k++)    //puts the strNums inside appropriate
            myQ[(int) (nums[k][maxDigits-j-1]-'0')].push(nums[k]);
        
        nums.clear(); //easier to push_back
        nums.reserve(len); //more efficient because you don't need to resize more than once
        
        for (int m=0; m<10; m++)
            while (!myQ[m].empty())
            {
                nums.push_back(myQ[m].front());
                myQ[m].pop();
            }
    }
}


// 6. Sliding Window

/*
Four different variants of Sliding Window algorithm:
(i)Find smallest sub-array size so that sum of sub-array is greater than or equal to a certain
   constant S in O(n)

Solution: maintain window that keeps growing (append current element to right side of window) and 
add value of current element to a running sum or keep shrinking (remove from left side) as long as
running sum is >= S. Keep smallest window length throughout the process.


(ii) Find smallest sub-array size so that elements inside the sub-array contains all integers
     in range [1..K]

Solution: keep the smallest window length throughout the process and report answer. When all integers 
in [1..K] has non zero frequency, range is covered. Growing the window increases a frequency of a certain
integer that may cause the range to the fully covered, whereas shrinking the window decreases a frequency
of a removed integer and if the frequency of that integer drops to 0, previously covered range is now
no longer fully covered (i.e. must keep that last integer on the left)


(iii) Find maximum sum of a certain sub-array with (static) size K

Solution: insert first K integers in window, compute sum and declare as current max. Then slide to right by
adding one element on the right and removing one element from the back. Add sum by value of added element minus
value of removed element and compare with the current max to check if new max is found. Repeat process n-K times and report
the max sum found


(iv) Find minimum of each possible sub-arrays with (static) size K


Solution: use deque to model the window. See C++ code below
*/
void SlidingWindow(int A[], int n, int k) {
    // ii---or pair<int, int>---represents the pair (A[i], i)
    deque<ii> window; // maintain 'window' to be sorted in ascending order

    for (int i = 0; i < n; i++) {
        while (!window.empty() && window.back().first >= A[i])
            window.pop_back();          // to keep 'window' always sorted

        window.push_back(ii(A[i], i));

        // use the second field to see if this is part of the current window
        while (window.front().second <= i-K)        //lazy deletion
            window.pop_front();

        if (i+1 >= K) printf("%d\n", window.front().first) //answer
    }
}


// 7. Max 1D Range Sum/Kadane's Algorithm

// Given an integer array A, determine the max range sum of A

void Kadane(int A[], int n) {
    int sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        ans = max(ans, sum);
        if (sum < 0) sum = 0;
    }
    printf("Max 1D Range Sum = %d\n", ans);
}

// Following code is a O(n^3) Algorithm to solve Max 2D Range Sum, i.e. 
// Sub-matrix of A with maximum sum where A is a 2D matrix

void Kadane_2d() {     // O(n^3) 1D DP + greedy (Kadane's) solution, 0.008 s in UVa
  int n; scanf("%d", &n);             // the dimension of input square matrix
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
    scanf("%d", &A[i][j]);
    if (j > 0) A[i][j] += A[i][j-1];        // only add columns of this row i
  }
  int maxSubRect = -127*100*100;                 // the lowest possible value
  for (int l = 0; l < n; l++) for (int r = l; r < n; r++) {
    int subRect = 0;
    for (int row = 0; row < n; row++) {
      if (l > 0) subRect += A[row][r] - A[row][l-1];      // Max 1D Range Sum
      else       subRect += A[row][r];              // on columns of this row
      if (subRect < 0) subRect = 0;     // greedy, restart if running sum < 0
      maxSubRect = max(maxSubRect, subRect);    // Kadane's algorithm on rows
  } }
  printf("%d\n", maxSubRect);
  return 0;


// 8. LIS - O(n log k) - Uses Greedy + Divide and Conquer Algorithm

#define MAX_N 100000

void print_array(const char *s, int a[], int n) {
  for (int i = 0; i < n; i++) {
    if (i) printf(", ");
    else printf("%s: [", s);
    printf("%d", a[i]);
  }
  printf("]\n");
}

void reconstruct_print(int end, int a[], int p[]) {
  int x = end;
  stack<int> s;
  for (; p[x] >= 0; x = p[x]) s.push(a[x]);
  printf("[%d", a[x]);
  for (; !s.empty(); s.pop()) printf(", %d", s.top());
  printf("]\n");
}

int main() {
  int n = 11, A[] = {-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4};
  int L[MAX_N], L_id[MAX_N], P[MAX_N];

  int lis = 0, lis_end = 0;
  for (int i = 0; i < n; ++i) {
    int pos = lower_bound(L, L+lis, A[i]) - L;
    L[pos] = A[i];
    L_id[pos] = i;
    P[i] = pos ? L_id[pos-1] : -1;
    if (pos+1 > lis) {
      lis = pos+1;
      lis_end = i;
    }

    printf("Considering element A[%d] = %d\n", i, A[i]);
    printf("LIS ending at A[%d] is of length %d: ", i, pos+1);
    reconstruct_print(i, A, P);
    print_array("L is now", L, lis);
    printf("\n");
  }

  printf("Final LIS is of length %d: ", lis);
  reconstruct_print(lis_end, A, P);
  return 0;


// 9. Graham Scan's algorithm


// Convert string to mintues or minutes to time

int clockConvert (string input, bool am) {
    if (input == "noon") {
        return 12*60;
    } else if (input == "midnight") {
        return 0;
    }
    
    if (am) {
        istringstream iss (input);
        string token;
        vector<string> tokens;
        while (getline(iss, token, ':')) {
            tokens.push_back(token);
        }
        
        if (tokens[0] == "12") {
            return 0 + stoi(tokens[1]);
        }
        return stoi(tokens[0])*60 + stoi(tokens[1]);
    } else {
        istringstream iss (input);
        string token;
        vector<string> tokens;
        while (getline(iss, token, ':')) {
            tokens.push_back(token);
        }
        
        if (tokens[0] == "12") {
            return 12*60 + stoi(tokens[1]);
        }
        return (stoi(tokens[0])+12)*60 + stoi(tokens[1]);
    }
}

string minutesToClock(int minutes) {
    minutes %= (24*60);
    if (minutes == 12*60) {
        return "noon";
    } else if (minutes == 0) {
        return "midnight";
    }
    
    int hours = minutes/60;
    int minutes_ = minutes%60;
    if (hours >= 12) {
        if (hours != 12)
            hours -= 12;
        string output = to_string(hours);
        output += ":";
        if (minutes_ < 10) {
            output += '0';
        }
        output += to_string(minutes_);

        output += " p.m.";
        return output;
    } else {
        string output = to_string(hours);
        if (hours == 0) {
            output = to_string(12);
        }
        output += ":";
        if (minutes_ < 10) {
            output += '0';
        }
        output += to_string(minutes_);
        
        output += " a.m.";
        return output;
    }
}




