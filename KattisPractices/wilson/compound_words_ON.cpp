#include <stdio.h>
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main () {
    set<string> input;
    set<string> input3;
    /*
     input.insert("a");
     input.insert("ab");
     input.insert("c");
     */
    
    /*
    input.insert("a");
    input.insert("bb");
    input.insert("ab");
    input.insert("b");
    input.insert("aaab");
    */
    
    // TODO: Find out how to ignore cases when abb can happen because of a + bb or ab + b
    
    string in;
    //cin.ignore();
    while (cin >> in) {
        if (in != "") {
            input.insert(in);
        }
    }
    
    
    for (auto it = input.begin(); it != input.end(); it++) {
        for (auto it2 = input.begin(); it2 != input.end(); it2++) {
            if (it != it2) {
                if (next(it) != input.end() && (*it + *it2 >= *next(it) + *input.begin())) {
                    input3.insert(*it + *it2);
                }else {
                    
                    if (!input3.empty() && *it + *it2 >= *input3.begin()) {
                        // Shouldnt be here
                        input3.insert(*it + *it2);
                        
                        while (!input3.empty()) {
                            cout << *input3.begin() << endl;
                            input3.erase(input3.begin());
                            
                        }
                    } else {
                        cout << (*it + *it2) << endl;
                    }
                }
            }
        }
    }
}

