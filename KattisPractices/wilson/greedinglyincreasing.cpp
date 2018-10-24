#include <stdio.h>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

int main () {
    deque<int> myStack;
    int num;
    scanf("%d", &num);
    
    for (int i = 0; i < num; i++) {
        int number;
        scanf("%d", &number);
        if (!i) myStack.push_back(number);
        else if (myStack.back() < number){
            myStack.push_back(number);
        }
    }
    
    printf("%d\n", myStack.size());
    int size = myStack.size();
    for (int i = 0; i < size; i++) {
        printf ("%d ", myStack.front());
        myStack.pop_front();
    }
    printf("\n");
    
    
}

