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

#define MAX 2147483646

using namespace std;

map <int, string> names = {{1,"one"},
    {2,"two"},
    {3,"three"},
    {4,"four"},
    {5,"five"},
    {6,"six"},
    {7,"seven"},
    {8,"eight"},
    {9,"nine"},
    {10,"ten"},
    {11,"eleven"},
    {12,"twelve"},
    {13,"thirteen"},
    {14,"fourteen"},
    {15,"fifteen"},
    {16,"sixteen"},
    {17,"seventeen"},
    {18,"eighteen"},
    {19,"nineteen"},
    {20,"twenty"},
    {30,"thirty"},
    {40,"forty"},
    {50,"fifty"},
    {60,"sixty"},
    {70,"seventy"},
    {80,"eighty"},
    {90,"ninety"},
    {100,"onehundred"},
    {200,"twohundred"},
    {300,"threehundred"},
    {400,"fourhundred"},
    {500,"fivehundred"},
    {600,"sixhundred"},
    {700,"sevenhundred"},
    {800,"eighthundred"},
    {900,"ninehundred"}
};


string numToString (int num) {
    
    if (num < 20) {
        return names[num];
        
    } else if (num >= 100) {
        int hundreths = num/100;
        hundreths*=100;
        string build = names[hundreths];
        
        num %= 100;
        return build += numToString(num);
    } else {
        int tenths = num/10;
        tenths *= 10;
        string build = names[tenths];
        num %= 10;
        
        return build += numToString(num);
    }
}

string match (int currCount) {
//    int count = currCount;
//    while (true) {
//        if (currCount + numToString(count).length() == count) {
//            return numToString(count);
//        }
//        count++;
//    }
//    return "";
    
    
    for (int i = 1; i < 1000; i++) {
        if (currCount + numToString(i).length() == i) {
            return numToString(i);
        }
    }
    return "";
}

int main () {
    
//    cout << "enter" << endl;
    
    
    int num; cin >> num;
    queue<string> q;
    int numWords = 0;
    while (num--) {
        string word; cin >> word;
        if (word[0] != '$') {
            numWords+= word.length();
        }
        q.push(word);
    }



    while (!q.empty()) {
        if (q.front() != "$") {
            cout << q.front() << " ";
        } else {
            cout << match(numWords) << " ";
        }
        q.pop();
    }
    cout << endl;
    
//    cout << numToString(999) << endl;
    
    
}
