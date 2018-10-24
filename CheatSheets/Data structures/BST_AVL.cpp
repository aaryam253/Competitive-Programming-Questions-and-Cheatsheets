#include <bits/stdc++.h>



using namespace std;

struct BSTVertex {
    BSTVertex* parent;
    BSTVertex* left;
    BSTVertex* right;
    int key;
    int height;
};

class BST {
protected:
    BSTVertex *root;
    
    // O(h) as we have to search first then insert if not found
    BSTVertex* insert(BSTVertex* T, int v) {
        if (T == NULL) {                                 // insertion point is found
            T = new BSTVertex;
            T->key = v;
            T->parent = T->left = T->right = NULL;
            T->height = 0; // will be used in AVL lecture
        }
        else if (T->key < v) {                                // search to the right
            T->right = insert(T->right, v);
            T->right->parent = T;
        }
        else {                                                 // search to the left
            T->left = insert(T->left, v);
            T->left->parent = T;
        }
        return T;                                          // return the updated BST
    }
    

    // Commonly used for DFS
    // inorder traversal will give a sorted sequence O(n)
    void inorder(BSTVertex* T) {
        if (T == NULL) return;
        inorder(T->left);                              // recursively go to the left
        printf(" %d", T->key);                                // visit this BST node
        inorder(T->right);                            // recursively go to the right
    }
    
    int findMin(BSTVertex* T) {
        if (T == NULL)       return -1;             // BST is empty, no minimum
        else if (T->left == NULL) return T->key;                  // this is the min
        else                      return findMin(T->left);         // go to the left
    }
    
    int findMax(BSTVertex* T) {
        if (T == NULL)        return -1;            // BST is empty, no maximum
        else if (T->right == NULL) return T->key;                 // this is the max
        else                       return findMax(T->right);      // go to the right
    }
    
    BSTVertex* search(BSTVertex* T, int v) {
        if (T == NULL)   return T;                                // not found
        else if (T->key == v) return T;                                    // found
        else if (T->key < v)  return search(T->right, v);     // search to the right
        else                  return search(T->left, v);       // search to the left
    }
    

    // Predecessor and successor will also run in O(h)

    int successor(BSTVertex* T) {
        if (T->right != NULL)                      // this subtree has right subtree
            return findMin(T->right); // the successor is the minimum of right subtree
        else {
            BSTVertex* par = T->parent;
            BSTVertex* cur = T;
            // if par(ent) is not root and cur(rent) is its right children
            while ((par != NULL) && (cur == par->right)) {
                cur = par;                                         // continue moving up
                par = cur->parent;
            }
            return par == NULL ? -1 : par->key;          // this is the successor of T
        }
    }
    
    int predecessor(BSTVertex* T) {
        if (T->left != NULL)                        // this subtree has left subtree
            return findMax(T->left); // the predecessor is the maximum of left subtree
        else {
            BSTVertex* par = T->parent;
            BSTVertex* cur = T;
            // if par(ent) is not root and cur(rent) is its left children
            while ((par != NULL) && (cur == par->left)) {
                cur = par;                                         // continue moving up
                par = cur->parent;
            }
            return par == NULL ? -1 : par->key;          // this is the successor of T
        }
    }
    
    BSTVertex* remove(BSTVertex* T, int v) {
        if (T == NULL)  return T;              // cannot find the item to be deleted
        
        if (T->key == v) {                         // this is the node to be deleted
            if (T->left == NULL && T->right == NULL)                 // this is a leaf
                T = NULL;                                      // simply erase this node
            else if (T->left == NULL && T->right != NULL) { // only one child at right
                T->right->parent = T->parent;          // ma, take care of my only child
                T = T->right;                                                // bypass T
            }
            else if (T->left != NULL && T->right == NULL) {  // only one child at left
                T->left->parent = T->parent;           // ma, take care of my only child
                T = T->left;                                                 // bypass T
            }
            else {                // has two children, find successor to avoid quarrel
                int successorV = successor(v);             // predecessor is also OK btw
                T->key = successorV;        // replace this key with the successor's key
                T->right = remove(T->right, successorV);    // delete the old successorV
            }
        }
        else if (T->key < v)                                  // search to the right
            T->right = remove(T->right, v);
        else                                                   // search to the left
            T->left = remove(T->left, v);
        return T;                                          // return the updated BST
    }

    // O(k) not O(klogN)
    void kthLargestUtil(BSTVertex* root, int k, int &c) {

        // Base cases, the second condition is important to
        // avoid unnecessary recursive calls
        if (root == NULL || c >= k)
            return;
        
        // Follow reverse inorder traversal so that the
        // largest element is visited first
        kthLargestUtil(root->right, k, c);
        
        // Increment count of visited nodes
        c++;
        
        // If c becomes k now, then this is the k'th largest
        if (c == k)
        {
            cout << "K'th largest element is "
            << root->key << endl;
            return;
        }
        
        // Recur for left subtree
        kthLargestUtil(root->left, k, c);
    }



    
    // will be used in AVL lecture
    int getHeight(BSTVertex* T) {
        if (T == NULL) return -1;
        else return max(getHeight(T->left), getHeight(T->right)) + 1;
    }

    BSTVertex* search_lower_bound (BSTVertex* temp, int key) {
        BSTVertex * prev = NULL;
        // Iterative
        while (temp != NULL) {
            if (key < temp->key) {
                prev = temp;
                temp = temp->left;
            }
            else if (temp->key == key) return temp; // Needed to for normal search style operation
            else {
                temp = temp->right;
            }
        }
        return prev;
    }

    int sizeof_subtree (BSTVertex * curr) {
        int count = 0;
        if (curr == NULL) return count; // If its NULL, dont count
        else count++;
        count += sizeof_subtree(curr->left);
        count += sizeof_subtree(curr->right);
        return count;
    }
    
    int rank (BSTVertex * curr, int key) {
        // Iterative
        int rank = 1; // 1-based
        while (curr != NULL) {
            if (curr->key < key) {
                // traverse right
                rank += (sizeof_subtree(curr->left) + 1); // Add size of left sub tree plus parent 
                curr = curr->right;
            }else if (curr->key > key) {
                // Traverse left
                curr = curr->left;
            }
            else {
                // Found the key
                rank += sizeof_subtree(curr->left);
                return rank;
            }
        }
        return rank;
    }

    BSTVertex * select (BSTVertex * curr, int rank) {
        int rank_ = 1;
        while (curr != NULL) {
            // We keep traversing right till the first instance rank is either larger or equals to the one we want
            int temp = rank_ + sizeof_subtree(curr->left);
            if (temp < rank) {
                rank_ = temp + 1; // Replace rank_ with the new value + parent
                curr = curr->right;
            }
            else if (temp == rank){
                return curr; // Return immediately
            }
            else {
                curr = curr->left;
            }
        }
        return curr;
    }


    BSTVertex * lca (BSTVertex * root, int n1, int n2) {
        if (root == NULL) return NULL;
        // If both n1 and n2 are smaller than root, then LCA lies in left
        if (root->data > n1 && root->data > n2)
            return lca(root->left, n1, n2);
     
        // If both n1 and n2 are greater than root, then LCA lies in right
        if (root->data < n1 && root->data < n2)
            return lca(root->right, n1, n2);
     
        return root;
    }

    
public:
    BST() { root = NULL; }
    
    void insert(int v) { root = insert(root, v); }
    
    void inorder() {
        inorder(root);
        printf("\n");
    }
    
    int findMin() { 
        return findMin(root); 
    }
    
    int findMax() { 
        return findMax(root); 
    }
    
    int search(int v) {
        BSTVertex* res = search(root, v);
        return res == NULL ? -1 : res->key;
    }
    
    int successor(int v) {
        BSTVertex* vPos = search(root, v);
        return vPos == NULL ? -1 : successor(vPos);
    }
    
    int predecessor(int v) {
        BSTVertex* vPos = search(root, v);
        return vPos == NULL ? -1 : predecessor(vPos);
    }
    
    void remove(int v) { 
        root = remove(root, v); 
    }
    
    // will be used in AVL lecture
    int getHeight() { 
        return getHeight(root); 
    }

    void kthLargest(int k)
    {
        // Initialize count of nodes visited as 0
        int c = 0;
        
        // Note that c is passed by reference
        kthLargestUtil(root, k, c);
    }

    int lower_bound(int k) {
        return search_lower_bound(root, k)->key;
    }

    int upper_bound (int k) {
        BSTVertex * temp = search_lower_bound(root, k);
        if (temp->key != k) return temp->key;
        return successor(temp);
    }


    int rankOf (int key) {
        return rank(root, key);
    }

    int select (int rank) {
        return select(root, rank)->key;
    }


    int lca_handler (int n1, int n2) {
        BSTVertex * curr = lca(root, n1, n2);
        return curr->key;
    }

};

/*
 BST properties:
 - Root vertex does not have parent
 - Leaf vertex does not have any child
 - Internal vertices are vertices which are not leaves
 - We can store satellite data with the key being used to sort the BST
 - Vertices which are greater fall on the right of parent
 - Vertices which are smaller fall on the left of parent
 - We have to decide if we wish to store duplicate on the left or right (optional)
 
 - Dynamic data structure which is efficient even when updating vertices inside
 
 - Lower bound: h > log2(N)
 - Upper bound: h <= N
 
 - Total number of possible trees with n keys: (2n)!/((n+1)!*n!)
 
 - Rank is the nth element in the ordered set of elements (1-based) eg. rank 1 is the smallest element
 
 - Deleting an element of same value but different locations in a BST will not result in a structurally similar BST
 
 - Traversal techniques: https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/

 - Tip: Inorder traversal, just flatten the tree and read from left to right 

 - Traversal to read the tree in sorted order will just take O (N) as finding successor wont take more than h iterations

 */


class AVL : public BST { // another example of C++ inheritance
private:
    int h(BSTVertex* T) { return T == NULL ? -1 : T->height; }
    
    BSTVertex* rotateLeft(BSTVertex* T) {
        // T must have a right child
        
        BSTVertex* w = T->right;
        w->parent = T->parent;
        T->parent = w;
        T->right = w->left;
        if (w->left != NULL) w->left->parent = T;
        w->left = T;
        
        T->height = max(h(T->left), h(T->right)) + 1;
        w->height = max(h(w->left), h(w->right)) + 1;
        
        return w;
    }
    
    BSTVertex* rotateRight(BSTVertex* T) {
        // T must have a left child
        
        BSTVertex* w = T->left;
        w->parent = T->parent;
        T->parent = w;
        T->left = w->right;
        if (w->right != NULL) w->right->parent = T;
        w->right = T;
        
        T->height = max(h(T->left), h(T->right)) + 1;
        w->height = max(h(w->left), h(w->right)) + 1;
        
        return w;
    }
    
    BSTVertex* insert(BSTVertex* T, int v) {       // override insert in BST class
        if (T == NULL) {                                 // insertion point is found
            T = new BSTVertex;
            T->key = v;
            T->parent = T->left = T->right = NULL;
            T->height = 0; // will be used in AVL lecture
        }
        else if (T->key < v) {                                // search to the right
            T->right = insert(T->right, v);
            T->right->parent = T;
        }
        else {                                                 // search to the left
            T->left = insert(T->left, v);
            T->left->parent = T;
        }
        
        int balance = h(T->left) - h(T->right);
        if (balance == 2) { // left heavy
            int balance2 = h(T->left->left) - h(T->left->right);
            if (balance2 == 1) {
                T = rotateRight(T);
            }
            else { // -1
                T->left = rotateLeft(T->left);
                T = rotateRight(T);
            }
        }
        else if (balance == -2) { // right heavy
            int balance2 = h(T->right->left) - h(T->right->right);
            if (balance2 == -1)
                T = rotateLeft(T);
            else { // 1
                T->right = rotateRight(T->right);
                T = rotateLeft(T);
            }
        }
        
        T->height = max(h(T->left), h(T->right)) + 1;
        return T;                                          // return the updated AVL
    }
    
    BSTVertex* remove(BSTVertex* T, int v) {
        if (T == NULL)  return T;              // cannot find the item to be deleted
        
        if (T->key == v) {                         // this is the node to be deleted
            if (T->left == NULL && T->right == NULL)                 // this is a leaf
                T = NULL;                                      // simply erase this node
            else if (T->left == NULL && T->right != NULL) { // only one child at right
                BSTVertex* temp = T;
                T->right->parent = T->parent;
                T = T->right;                                                // bypass T
                temp = NULL;
            }
            else if (T->left != NULL && T->right == NULL) {  // only one child at left
                BSTVertex* temp = T;
                T->left->parent = T->parent;
                T = T->left;                                                 // bypass T
                temp = NULL;
            }
            else {                                 // has two children, find successor
                int successorV = successor(v);
                T->key = successorV;        // replace this key with the successor's key
                T->right = remove(T->right, successorV);    // delete the old successorV
            }
        }
        else if (T->key < v)                                  // search to the right
            T->right = remove(T->right, v);
        else                                                   // search to the left
            T->left = remove(T->left, v);
        
        if (T != NULL) {               // similar as insertion code except this line
            int balance = h(T->left) - h(T->right);
            if (balance == 2) { // left heavy
                int balance2 = h(T->left->left) - h(T->left->right);
                if (balance2 == 1) {
                    T = rotateRight(T);
                }
                else { // -1
                    T->left = rotateLeft(T->left);
                    T = rotateRight(T);
                }
            }
            else if (balance == -2) { // right heavy
                int balance2 = h(T->right->left) - h(T->right->right);
                if (balance2 == -1)
                    T = rotateLeft(T);
                else { // 1
                    T->right = rotateRight(T->right);
                    T = rotateLeft(T);
                }
            }
            
            T->height = max(h(T->left), h(T->right)) + 1;
        }
        
        return T;                                          // return the updated BST
    }
    
public:
    AVL() { root = NULL; }
    
    void insert(int v) { 
        root = insert(root, v); 
    }
    
    void remove(int v) { 
        root = remove(root, v); 
    }
};


/*
 AVL trees:
 - Most operations run in O(log(N)) time
 - A vertex is said to be height balanced invariant if |v.left.height - v.right.height| <= 1
 - If height balancing is satisfied, total height will always be < 2*log2(N)
 - Nh > 2 ^ (h/2),  Nh = number of vertices we can fit into height h
 - Minimum number of nodes we can fit in a tree of height H: S(h) = S(h-1) + S(h-2) + 1
 - Max number of rotations during insertion <= 1
 - Max number of rotations during deletion O(log(n)) where log(n) is the height of the tree

 Examples:
 
 height: 0 1 2 3 4  5  6  7  8  9   10  11  12 
 ------------------------------------------------
 number: 0 2 4 7 12 20 33 54 88 143 232 376 609


 Rotation:
 - Right rotation: can only be called if it has a left child
 - Left rotation: can only be called if it has a right child


*/
