#include <iostream>
#include <stdio.h>

using namespace std;


class binHeap_p {
private:
    struct node{
        node * parent;
        node * left;
        node * right;
        int data;
    };
    int size;
    node * tail, * head;
    
    void bubbleUp (node * cur) {
        if (cur->parent == NULL) {
            return;
        }
        
        if (cur->data > cur->parent->data) {
            // Swap
            int t = cur->data;
            cur->data = cur->parent->data;
            cur->parent->data = t;
            
            bubbleUp(cur->parent);
        }
    }
public:
    
    binHeap_p () {
        size = 0;
    }
    void push (int data) {
        node *temp = new node;
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        temp->parent = NULL;
        if (!size) {
            head = temp;
            tail = temp;
        }else {
            if (tail->left == NULL) {
                tail->left = temp;
                temp->parent = tail;
            }
            else {
                tail->right = temp;
                temp->parent = tail;
            }
            tail = temp;
            bubbleUp(tail);
        }
        size++;
    }
    
    int top () {
        if (head == NULL) return NULL;
        return head->data;
    }
    
    void removeTop () {
        // Removing does not require additional operations.
        // Just check left and right child
        node * temp = head;
        if (head->left > head->right) {
            head = head->left;
        }else {
            head = head->right;
        }
        delete temp;
    }
    
    int getSize () {
        return size;
    }
    
};


int main () {
    binHeap_p myHeap;
    int arr[5] = {5,3,2,8,1}; // input set
    for (int i = 0; i < 5; i++) {
        myHeap.push(arr[i]);
        cout << myHeap.top() << endl;
    }
    
    cout << "------------ Removing ------------" << endl;
    for (int i = 0; i < 5; i++) {
        cout << myHeap.top() << endl;
        myHeap.removeTop();
    }
    
}

