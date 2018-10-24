#include <iostream>
#include <stack>


using namespace std;

int main () {
    int num;
    cin >> num;
    
    stack<int> myStack;
    
    for (int i = 0; i < num; i++) {
        // push the first one into stack, wait and see if the second one can combine to form even if not push it into stack, repeat
        int number;
        cin >> number;
        
        if (i == 0) myStack.push(number);
        else {
            if (myStack.empty()) {
                myStack.push(number);
                continue;
            }
            
            
            if ((number + myStack.top())%2 == 0) {
                myStack.pop();
            }else {
                myStack.push(number);
            }
        }
    }
    cout << myStack.size() << endl;
}
