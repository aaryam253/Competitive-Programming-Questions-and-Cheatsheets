#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>


using namespace std;

vector<pair<char, int>> countingSort (string input, int n) {
    stack<pair<char, int>> myqueue[128];
    vector<pair<char, int>> myvec;
    for (int i = 0; i < n; ++i)
    {
        myqueue[input[i]].push(make_pair(input[i], i));
    }
    for (int i = 0; i <= 127; ++i)
    {
        // Empty the bucket
        while (!myqueue[i].empty()) {
            myvec.push_back(myqueue[i].top());
            myqueue[i].pop();
        }
    }
    
    return myvec;
}

int partition(vector<pair<char, int>> input, int l, int r)
{
    int x = input[r].first, i = l;
    for (int j = l; j <= r - 1; j++) {
        if (input[j].first <= x) {
            int t = input[i].first;
            input[i].first = input[j].first;
            input[j].first = t;
            i++;
        }
    }
    int t = input[i].first;
    input[i].first = input[r].first;
    input[r].first = t;
    return i;
}


int kthSmallest(vector<pair<char, int>> input, int l, int r, int smallestElement)
{
    if (smallestElement > 0 && smallestElement <= r - l + 1) {
        int index = partition(input, l, r);
        
        // If position is same as k
        if (index - l == smallestElement - 1)
            return input[index].second;
        
        // If position is more, recur
        // for left subarray
        if (index - l > smallestElement - 1)
            return kthSmallest(input, l, index - 1, smallestElement);
        
        // Else recur for right subarray
        return kthSmallest(input, index + 1, r, smallestElement - index + l - 1);
    }
    
    // If k is more than number of
    // elements in array
    return -1;
}



int main () {
    string input;
    vector<pair<char, int> > mylist;
    cin >> input;
    
    //mylist = countingSort(input, input.size());
    mylist = countingSort(input, input.size());
    
    while (true) {
        int n;
        cin >> n;
        
        cout << kthSmallest(mylist, 0, input.size()-1, n+1) << endl;
    }
    
}

// TODO: find out why the following test case
/*
 input : popup
         5 0 1 2 3 4
 
 output: 1 4 0 2 3
*/

