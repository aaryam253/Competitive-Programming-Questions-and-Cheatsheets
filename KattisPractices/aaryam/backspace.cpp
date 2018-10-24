

#include <iostream>
#include <stack>
using namespace std;
char raw[1000000];

int main(){
    stack<char> real_expression;
    string original;
    
    cin >> original;
    
    for (int i = 0; i < original.size(); i++) {
        if (isalpha(original.at(i))) {
            real_expression.push(original[i]);
        }
        else if (original[i] == '<'){
            real_expression.pop();
        }
    }

    int count = 0;
    while (!real_expression.empty()) {
        raw[count] = real_expression.top();
        real_expression.pop();
        count++;
    }
    
    for(int i = count-1; i >= 0; i--) {
        cout << raw[i];
    }
    
    cout<<endl;
    return 0;
}
