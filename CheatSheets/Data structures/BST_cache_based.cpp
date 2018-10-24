
class BST {
    // Precond: this BST does not store duplicates
    // 0 is used to signify a non-existent value return
    
private:
    
    int arr[300001] = {0}; // note that there will be many many gaps in between 
    
    int size;
    int search_recur(int key, int curr) {
        if (curr == 0) return curr;
        
        else if (arr[curr] == key) return curr;
        
        else if (arr[curr] < key) return search_recur(key, 2*curr+2);
        else return search_recur(key, 2*curr+1);
    }
        
    void inorder_recur (int curr) {
        if (arr[curr] == 0) return;

        inorder_recur(2*curr+1);
        cout << arr[curr] << " ";
        inorder_recur(2*curr+2);
    }
    
public:
    
    BST () {
        // constructor
        size = 0;
    }
    
    bool search (int key) {
        if (search_recur(key, 0) != 0) return true;
        return false;
    }
        
        
    // O(h) as we have to search first then insert if not found
    // Iterative insertion
    void insert (int key) {
        if (!size) {
            arr[0] = key;
            size++;
            return;
        }
        
        int index = 0;
        while (true) {
            if (key > arr[index]) {
                // traverse right
                // TODO: Continue converting this to array/ cached based BST
                if (arr[2*index + 2] == 0) {
                    // found insertion pt
                    arr[2*index + 2] = key;
                    size++;
                    return;
                }
                index = 2*index+2;
            }
            else if (key < arr[index]) {
                // traverse left
                if (arr[2*index + 1] == 0) {
                    // found insertion pt
                    arr[2*index + 1] = key;
                    size++;
                    return;
                }
                index = 2*index+1;
            }
            else{
                return;
            }
        }
    }
    
    void inorder () {
        inorder_recur(0);
        cout << endl;
    }
    
    int getSize () {
        return size;
    }
    
    
};
