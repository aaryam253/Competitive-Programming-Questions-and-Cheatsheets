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

#define MAX 2147483640

using namespace std;


// Needs a big int method to solve this

string doSum(string a, string b)
{
    if(a.size() < b.size())
        swap(a, b);
    
    unsigned long j = a.size()-1;
    for(unsigned long i=b.size()-1; i>=0; i--, j--)
        a[j]+=(b[i]-'0');
    
    for(unsigned long i=a.size()-1; i>0; i--)
    {
        if(a[i] > '9')
        {
            unsigned long d = a[i]-'0';
            a[i-1] = ((a[i-1]-'0') + d/10) + '0';
            a[i] = (d%10)+'0';
        }
    }
    if(a[0] > '9') {
        string k;
        k+=a[0];
        a[0] = ((a[0]-'0')%10)+'0';
        k[0] = ((k[0]-'0')/10)+'0';
        a = k+a;
    }
    return a;
}

bool isCreeper (string input) {
    if (input.size() >= 8) {
//        cout << input << " " << input.substr(input.length()-4,4) << endl;
        if ((input.substr(0, 4) == "1233" && input.substr(input.length()-4, 4) == "4444") && input[input.length()-5] == '3') {
            return true;
        } else if ((input.substr(0, 4) == "5566" && input.substr(input.length()-4, 4) == "7777") && input[input.length()-5] == '6') {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main () {
    int TC; cin >> TC;
    for (int i = 1; i <= TC; i++) {
        unordered_set<string> discovered;
        int garbage; cin >> garbage;
        int step; cin >> step;
        string input; cin >> input;
        int index = 1;
        bool isPrinted = false;
        cout << garbage << " ";
        
        while (index < step) {
            if (isCreeper(input)) {
                isPrinted = true;
                cout << "C " << index << endl;
                break;
            }
            if (discovered.find(input) != discovered.end()) {
                isPrinted = true;
                cout << "R " << index << endl;
                break;
            }
            discovered.insert(input);
            
            string a = input;
            reverse(input.begin(), input.end());
            string b = input;
            string processed = doSum(a, b);
            sort(processed.begin(), processed.end());
            size_t n = processed.find_first_not_of('0');
            if (n != string::npos) {
                processed = processed.substr(n);
            }
            input = processed;
            index++;
        }
        if (!isPrinted) {
            if (isCreeper(input)) {
                isPrinted = true;
                cout << "C " << index << endl;
                break;
            } else if (discovered.find(input) != discovered.end()) {
                isPrinted = true;
                cout << "R " << index << endl;
                break;
            } else {
                cout << input << endl;
            }
        }
        
    }
    
    
}
