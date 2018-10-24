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
    struct node *next;
};

//creating a stack class
class Stack {
    struct node *top;
public:
    Stack() { //constructor
        top = NULL;
    }
    void push(); //inserts an element
    void pop(); //deletes an element
    void print(); //prints the current stack
};

//push operation
void Stack::push() {
    int value;
    struct node *ptr;
    cout<<"PUSH Operation" << endl;
    cout<<"Enter a number to insert: ";
    cin >> value;
    
    ptr = new node;
    ptr->data = value;
    ptr->next = NULL;
    
    if (top!= NULL) {
        ptr->next=top;
    }
    top = ptr;
    
    cout << "New item inserted in the stack" << endl;
}

//pop operation
void Stack::pop() {
    struct node *temp;
    if (top == NULL) {
        cout << "The stack is empty" << endl;
    }
    
    temp = top;
    top = top->next;
    cout << "Value" << temp->data << "removed sucessfully" << endl;
    delete temp;
}

//prints the stack
void Stack::print() {
    struct node *ptr1=top;
    cout << "The stack is" << endl;
    while (ptr1 != NULL) {
        cout << ptr1->data << " ->";
        ptr1=ptr1->next;
    }
    cout << "NULL" << endl;
}

int main(void) {
    Stack s;
    int operation;
    while (1) {
        cout << "---------------------------------------------------" << endl;
        cout <<"\t\tSTACK IMPLEMENTATION USING LINKED LIST" << endl;
        cout << "1: PUSH\n2: POP\n3: PRINT STACK\n4: EXIT" << endl;
        cout << "Enter your choice (1-4): " << endl;
        cin >> operation;
        
        
        switch (operation) {
            case 1:
                s.push();
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.print();
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
