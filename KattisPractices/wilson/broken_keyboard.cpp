#include <iostream>
#include <deque>

using namespace std;

int main () {
    deque<char> input;
    deque<char> bijuu;
    string myInput;
    cin >> myInput;
    
    int flag = 0;
    
    for (auto it = myInput.begin(); it != myInput.end(); it++) {
        
        if (*it == '[') {
            flag = 1;
            continue;
        }
        else if (*it == ']') {
            flag = 0;
            continue;
        }
        if (flag) {
            bijuu.push_back(*it);
        }
        else {
            input.push_back(*it);
        }
    }
    
    while (!bijuu.empty()) {
        cout << bijuu.front();
        bijuu.pop_front();
    }
    
    while (!input.empty()) {
        cout << input.front();
        input.pop_front();
    }
    
    cout << endl;
}
