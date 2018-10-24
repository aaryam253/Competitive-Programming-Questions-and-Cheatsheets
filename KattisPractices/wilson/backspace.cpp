#include <iostream>
#include <deque>

using namespace std;

int main () {
    deque<char> input;
    string myInput;
    cin >> myInput;
    
    for (auto it = myInput.begin(); it != myInput.end(); it++) {
        if (*it != '<') {
            input.push_back(*it);
        }else {
            input.pop_back();
        }
    }
    
    while (!input.empty()) {
        cout << input.front();
        input.pop_front();
    }
    
    cout << endl;
}
