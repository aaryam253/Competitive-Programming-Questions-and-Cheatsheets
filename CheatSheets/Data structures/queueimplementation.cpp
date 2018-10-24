//
//  main.cpp
//  StackImplementation
//
//  Created by Aaryam Srivastava on 1/2/2018.
//  Copyright © 2018 Developers. All rights reserved.
//

#include <iostream>
using namespace std;

// create a node structure
struct node {
    int data;
    node *next;
};

//creating a queue class
class Queue {
public:
    node *front, *rear; //to store the front and rear positions
    Queue () {front = rear = NULL;}
    
    void enqueue(); //inserts an element
    void dequeue(); //deletes an element
    void print(); //prints the current stack
    ~Queue();
};

//enqueue operation
void Queue::enqueue() {
    int value;
    node *ptr = new node;
    if (ptr == NULL) {
        cout << "Overflow" << endl;
        return;
    }
    
    cout<<"PUSH Operation" << endl;
    cout<<"Enter a number to insert: ";
    cin >> value;
    
    ptr->data = value;
    ptr->next = NULL;
    
    //for the first node
    if (front == NULL) front = rear = ptr;
    else {
        rear->next=ptr;
        rear=ptr;
    }
    cout << "New item inserted in the stack" << endl;
}

//dequeue operation
void Queue::dequeue() {
    if (front == NULL) {
        cout << "The stack is empty" << endl;
    }

    cout << "Value" << front->data << "removed sucessfully" << endl;
    if (front == rear) { //if only one node exists
        front = rear = NULL;
    }
    else {
        front = front->next;
    }
}

//destructor function
Queue::~Queue() {
    while (front != NULL) {
        node *temp=front;
        front=front->next;
        delete temp;
    }
    rear = NULL;
}

//prints the stack
void Queue::print() {
    if(front == NULL) {
        cout << "Underflow." << endl;
        return;
    }
    node *temp = front;
    
    //will check until NULL is not found
    while(temp) {
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}

int main(void) {
    Queue q;
    int operation;
    while (1) {
        cout << "---------------------------------------------------" << endl;
        cout <<"\t\tQUEUE IMPLEMENTATION USING LINKED LIST" << endl;
        cout << "1: ENQUEUE\n2: DEQUEUE\n3: PRINT QUEUE\n4: EXIT" << endl;
        cout << "Enter your choice (1-4): " << endl;
        cin >> operation;
        
        
        switch (operation) {
            case 1:
                q.enqueue();
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.print();
                break;
            case 4:
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

