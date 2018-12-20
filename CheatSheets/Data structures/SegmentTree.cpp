/**
 * This segment tree stores the actual min value in the ST array instead of the index
 * This is to be used for massive queries and updates to an array of values
**/

class SegmentTree {
    vector<int> arr;
    vector<int> ST; // SegmentTree, 1-based indexing
    
public:
    SegmentTree (vector<int> arr) {
        this->arr = arr;
        ST = vector<int> (arr.size()*2, 0);
        construct();
        
        for (auto it : ST) {
            cout << it << " ";
        }
        cout << endl;
    }
    
    void update (int index, int value) {
        int index_ = index + arr.size(); // Since the actual values are stored at the leaf nodes, we add arr.size()
        ST[index] = value;
        
        while (index > 1) {
            index = index/2; // Reference parent
            ST[index] = min(ST[index*2], ST[index*2 + 1]);
        }
    }
    
    /**
     * Range is from [left, right)
     * Can also be used for max query and sum of ranges
     * O(Log(n)) operation
    **/
    int rangeMinQuery(int left, int right) {
        if (left < 0 || left >= arr.size()) return -1;
        if (right < 0 || right >= arr.size()) return -1;

        left += arr.size(); right += arr.size();
        int minimum = INT_MAX;
        
        // We try to narrow down our search
        while (left < right) {
            if (left%2) {
                // Means we've hit a right child node
                minimum = min(minimum, ST[left]);
                left++;
            }
            if (right%2) {
                // Means we've hit a left child node
                right--;
                minimum = min(minimum, ST[right]);
            }
            left /= 2; right /= 2; // Reference their parents
        }
        return minimum;
    }
    
private:
    /**
     * O(Log(n)) time complexity
    */
    void construct () {
        // Fill up second half of the ST array with the elements in arr
        int idx = arr.size();
        for (int i = 0; i < arr.size(); i++) {
            ST[idx++] = arr[i];
        }
        // Creating the rest of the segment tree by segmenting with minimum
        for (int i = arr.size() - 1; i >= 1; i--) {
            ST[i] = min(ST[2*i], ST[(2*i)+1]);
        }
    }
    
};
