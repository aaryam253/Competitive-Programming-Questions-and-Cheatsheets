#include <iostream>

using namespace std;

// Notice we created the struct outside the class.
struct node {
    int data;
    node *next;
};

class l_linked {
private:
    node *head, *tail;
    int size = 0;
    
    void create_node (int value) {
        node *temp = new node;
        temp->data = value;
        temp->next = NULL;
        if (head == NULL) {
            // If list is empty, use temp as the head and tail.
            head = temp;
            tail = temp;
            temp = NULL; // set temp to reference NULL
            size++;
        }else {
            tail->next = temp; // else create the node at the end
            tail = temp; // temp becomes the tail.
            size++;
        }
    }
    
public:
    l_linked () {
        head = NULL;
        tail = NULL;
    }
    
    int getSize () {return size;}
    
    void print () {
        node *temp = new node;
        temp = head;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;  // set temp to reference the next node.
        }
    }
    
    void insert(int data, int position) {
        if (!size) {
            create_node (data);
            return;
        }
        
        if (!position) {
            // If at the start
            node* temp = new node; // Create new reference of node type
            temp->data = data;
            temp->next = head;
            head = temp; // Set the head as this node
            size++;
            return;
        }else if (position >= size){
            // Create the data at the end
            create_node(data);
            size++;
            return;
        }
        
        // Search based on index
        node *temp = new node; // Start from the head first
        node *previous = new node;
        node *current = new node;
        
        current = head;
        
        for(int i=0;i<position;i++) {
            previous=current;
            current=current->next;
        }
        temp->data=data;
        previous->next=temp;
        temp->next=current;
    }
    
    node* search (int val) {
        node *temp = head; // Start from the head first
        while (temp != NULL) {
            // If list is not empty
            if (temp->data == val) return temp;
            temp = temp->next;
        }
        return NULL;
    }
    
    void remove (int position) {
        node *current;
        if (position == 0) {
            // Pop start
            current = head;
            head = head->next;
            size--;
            delete current;
            return;
        }
        
        if (position == size - 1) {
            current = tail;
            // Pop end
            // Need to keep track of the node before the last one.
            node *temp = head; // Start from the head first
            node *previous = head;
            while (temp != NULL) {
                // If list is not empty
                if (temp == tail){
                    previous->next = NULL;
                    delete current; // Delete the existing tail
                    tail = previous;
                }
                previous = temp;
                temp = temp->next;
            }
            size--;
            return;
        }
        
        // Pop anywhere within the list
        node *temp = head; // Start from the head first
        node *previous = head;
        int count = 0;
        while (temp != NULL) {
            // If list is not empty
            count++;
            if (count - 1 == position)
            {
                previous->next = temp->next;
                delete temp; // Delete the existing tail
                size--;
                return;
            }
            previous = temp;
            temp = temp->next;
        }
    }
    
    void delete_all () {
        // Delete everything
        size = 0;
        node *temp = head;
        node *current;
        while (temp != NULL) {
            // If list is not empty
            current = temp;
            temp = temp->next;
            delete current;
        }
        head = NULL;
        tail = NULL;
        cout << "All deleted" << endl;
    }
    
    void bubbleSort_list () {
        node *cur = new node;
        node *next = new node;
        bool unsorted = true;
        while(unsorted) {
            unsorted = false;
            cur = head;
            
            while(cur != nullptr) {
                next = cur->next;
                if(next < cur) {
                    swap(cur, next);
                    unsorted = true;
                }
                cur = cur->next;
            }
        }
    }
    
    void reverse_list () {
        node * prev = NULL;
        node * current = head;
        node * next;
        while (current != NULL) {
            // Basically set all the node's next to the prev while traversing down the linked list in  O(N)
            next  = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

int main(int argc, char const *argv[]) {
    l_linked list;
    list.insert(1, 0);
    list.insert(2, 0);
    list.insert(3, 0);
    list.insert(4, 0);
    
    list.insert(10, 1);
    
    node* removal = list.search(2);
    
    cout << "The data is-> " << removal->data << endl;
    
    list.remove(2);
    list.print();
    
    list.delete_all();
    
    return 0;
}
