#include <iostream>
using namespace std;

// create a node structure
struct node {
    int data;
    node *next;
    node *prev;
};

//creating a deque class
class Deque {
public:
    node *head, *tail; //to store the head and tail positions
    Deque () {head = tail = NULL;}
    
    void push_back(); //inserts an element at the tail
    void pop_front(); //deletes an element at the head
    void push_front(); //inserts an element at the head
    void pop_back(); //deletes an element at the tail
    void print(); //prints the current stack
    ~Deque();
};

//push_back operation
void Deque::push_back() {
    int value;
    node *ptr = new node;
    if (ptr == NULL) return;
    
    cout <<"PUSH FRONT Operation" << endl;
    cout <<"Enter a number to insert: ";
    cin >> value;
    
    ptr->data = value;
    ptr->next = NULL;
    ptr->prev = tail;
    
    //for the first node
    if (tail == NULL) head = tail = ptr;
    else {
        tail->next=ptr;
        tail=ptr;
    }
    cout << "New item inserted in the stack" << endl;
}

//push_front operation
void Deque::push_front() {
    int value;
    node *ptr = new node;
    if (ptr == NULL) return;
    
    cout<<"PUSH BACK Operation" << endl;
    cout<<"Enter a number to insert: ";
    cin >> value;
    
    ptr->data = value;
    ptr->next = head;
    ptr->prev = NULL;
    
    //for the first node
    if (head == NULL) head = tail = ptr;
    else {
        head->prev=ptr;
        head=ptr;
    }
    cout << "New item inserted in the stack" << endl;
}

//pop_front operation
void Deque::pop_front() {
    if (head == NULL) return;

    cout << "Value" << head->data << "removed sucessfully" << endl;
    if (head == tail) { //if only one node exists
        head = tail = NULL;
    }
    else {
        head = head->next;
    }
}


//pop_back operation
void Deque::pop_back() {
    if (tail == NULL) return;
    
    cout << "Value" << tail->data << "removed sucessfully" << endl;
    if (tail == head) { //if only one node exists
        head = tail = NULL;
    }
    else {
        tail = tail->prev;
    }
}

//destructor function
Deque::~Deque() {
    while (head != NULL) {
        node *temp=head;
        head=head->next;
        delete temp;
    }
    tail = NULL;
}

//prints the stack
void Deque::print() {
    if(head == NULL) {
        cout << "Underflow." << endl;
        return;
    }
    node *temp = head;
    
    //will check until NULL is not found
    while(temp) {
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}

int main(void) {
    Deque dq;
    int operation;
    while (1) {
        cout << "---------------------------------------------------" << endl;
        cout <<"\t\tDEQUE IMPLEMENTATION USING LINKED LIST" << endl;
        cout << "1: PUSHBACK\n2: POPFRONT\n3: PUSHFRONT\n4: POPBACK\n5: PRINT QUEUE\n6: EXIT" << endl;
        cout << "Enter your choice (1-6): " << endl;
        cin >> operation;
        
        switch (operation) {
            case 1:
                dq.push_back();
                break;
            case 2:
                dq.pop_front();
                break;
            case 3:
                dq.push_front();
                break;
            case 4:
                dq.pop_back();
                break;
            case 5:
                dq.print();
                break;
            case 6:
                cout << "Thanks, till next time sensei <3 <3 <3" << endl;
                return 0;
                break;
            default:
                cout << "Please enter a valid choice" << endl;
                break;
        }
    }
    
    return 0;
}

