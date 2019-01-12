/**
 ** Use DP when the problem has:
 * 1. Overlapping solutions
 * 2. Optimal sub-structures
 ** Algos:
 * 1. Top-down DP**
 * 2. Bottom-up DP**
 * 3. Kadane's algorithm
 * 4. Longest increasing subsequence
 * 5. Held and Karp's DP algorithm (For travelling salesman problems)
 * 6. Floyd Warshall's DP
 * 7. DP on implicit DAG
*/



/**
 * Top-down DP
 * Time complexity: O(Mk)
 * M: Number of distinct ans
 * k: Number of steps to get an ans
*/

int C, M; // Two conditions given by the ans
int memo[max_i][max_j]; // Memset this in main to all -1s
int arr[max_i][max_j]; // This is to store the various states and their costs, given by the ans

int recurse (int i, int j) {
    if (j < 0) return -1e9; // Large -ve number
    if (i == C) return M-j;

    if (memo[i][j] != -1) {
        // If this state has been explored before, just return it
        return memo[i][j];
    }

    int ans = -1;
    // We've stored the total number of states in arr[i][0], last column of that row
    for (int state = 1; state <= arr[i][0]; state++) {
        ans = max(ans, recurse(i+1, j - arr[i][state])); 
        // Choose an optimal ans, after exploring all the possibilities of the next state
    }

    return memo[i][j] = ans; // Memoize the most optimal ans
}

int main () {
    ...
}

/**
 * Bottom-up DP
 * We initialise the base case first and then work from there
*/

int C, M; // Two conditions given by the ans
bool reachable[max_i][max_j]; // Memset this in main to all -1s
int price[max_i][max_j]; // This is to store the various states and their costs, given by the ans


int main () {
    // Set reachable to all false initially
    ...

    // Initialise the base case
    for (int k = 1; k <= price[0][0]; k++) {
        if (M - price[0][k] >= 0)
            reachable[0][M - price[0][k]] = true;
    }


    int money;
    for (int g = 1; g < C; g++) {
        for (money = 0; money < M; money++) {
            // We've stored the total number of states in price[i][0], last column of that row
            for (int k = 1; k <= price[g][0]; k++) {
                if (money - price[g][k] >= 0)
                    reachable[g][money - price[g][k]] = true; // Visited and reachable
            }
        }
    }

    // Iterate one last time at reacheable[C-1] and see if there are any on bits. From left tor right
}


/**
 * Kadane's algorithm - 1D array
 * Used to find the maximum sum of CONTINUOUS elements of a 1D array
 * Time complexity: O(n)
*/

int main() {
  int n = 9, A[] = { 4, -5, 4, -3, 4, 4, -4, 4, -5 };   // a sample array A

  int running_sum = 0, ans = 0;
  
  for (int i = 0; i < n; i++)
    if (running_sum + A[i] >= 0) {  // the overall running sum is still +ve
      running_sum += A[i];
      ans = max(ans, running_sum);          // keep the largest RSQ overall
    }
    else        // the overall running sum is -ve, we greedily restart here ********
      running_sum = 0;      // because starting from 0 is better for future
                           // iterations than starting from -ve running sum
  printf("Max 1D Range Sum = %d\n", ans);                    // should be 9
  return 0;
}

/**
 * Longest increasing subsequence (Courtesy of Aaryam)
 * Find the longest increasing sub-sequence in an array, we can skip elements in the middle but must generally select elements from left to right
 * to form our sub-sequence
 * Time complexity: O(n^2)
*/

void calculate_LIS(int arr[], int n) {
     vector<int> lis(n, 1); // stores all LIS values, initialise all values with 1 as each element is an LIS of size 1
     for (int i = n-1; i >= 0; i--) {
             for (int j = i+1; j < n; j++) {
                     if (arr[i] > arr[j] && lis[i] < lis[j] + 1) lis[i] = lis[j] + 1;
             }
     }
}




