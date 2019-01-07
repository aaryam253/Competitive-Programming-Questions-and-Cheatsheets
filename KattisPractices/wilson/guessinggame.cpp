#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <tuple>
#include <string.h>
#include <sstream>

using namespace std;



int main () {
    int upper, lower; upper = 10; lower = 1;
    while (true) {
        int number; cin >> number;
        if (!number) break;
        string input; cin >> input;
        string input2; cin >> input2;
        input = input + " ";
        input = input + input2;
        
        if (input == "too high") {
            if (number - 1 < upper)
                upper = number - 1;
        } else if (input == "right on"){
            // end the game here
            if (number < lower || number > upper || upper < lower) {
                cout << "Stan is dishonest" << endl;;
            } else {
                cout << "Stan may be honest" << endl;
            }
            lower = 1;
            upper = 10;
        } else if (input == "too low"){
            if (number + 1 > lower)
                lower = number + 1;
        }
//        cout << lower << " " << upper << endl;
    }
}
