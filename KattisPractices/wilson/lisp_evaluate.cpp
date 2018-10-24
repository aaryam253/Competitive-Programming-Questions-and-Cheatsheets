#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// Sample expressions
// ( + ( - 6 ) ( * 2 3 4 ( - 6 2 ) ) )
// ( + 4 24 )
// ( - 6 )
// ( + ( - 6 ) ( / 2 3 ) )


float lisp_evaluate (string input) {
    istringstream iss (input);
    string token;
    vector<string> reverseMyInput;
    stack<string> calculator;
    
    while (getline(iss, token, ' ')) {
        reverseMyInput.push_back(token);
    }
    for (int i = reverseMyInput.size()-1; i >= 0; i--) {
        // If we detect the first instance of an open bracket, we will pop the operator first and then
        // deal with the numbers after it
        
        if (reverseMyInput[i] == "(") {
            int flag = 0; // To determine if there's only a single digit inside
            char myOP = calculator.top()[0];
            calculator.pop();
            while (calculator.top() != ")") {
                float num1 = stof(calculator.top());
                calculator.pop();
                
                if (calculator.top() == ")") {
                    // last number;
                    calculator.pop();
                    
                    // If no previous operation has been performed, it is a single digit inside a bracket.
                    if (!flag) {
                        switch (myOP) {
                            case '+':
                                calculator.push(to_string(0+num1));
                                break;
                            case '-':
                                calculator.push(to_string(0 - num1));
                                break;
                            case '*':
                                calculator.push(to_string(0 * num1));
                                break;
                            case '/':
                                calculator.push(to_string(0 / num1));
                                break;
                        }
                        break;
                    }
                    
                    // Or else it was a previously operated number
                    calculator.push(to_string(num1));
                    break;
                }
                
                float num2 = stof(calculator.top());
                calculator.pop();
                
                switch (myOP) {
                    case '+':
                        calculator.push(to_string(num1+num2));
                        break;
                    case '-':
                        calculator.push(to_string(num1-num2));
                        break;
                    case '*':
                        calculator.push(to_string(num1*num2));
                        break;
                    case '/':
                        calculator.push(to_string(num1/num2));
                        break;
                }
                flag = 1;
            }
            
        }else {
            calculator.push(reverseMyInput[i]);
        }
        
    }
    
    return stof (calculator.top());
}



int main () {
    string input;
    
    getline(cin, input);

    cout << lisp_evaluate(input) << endl;
    
}

