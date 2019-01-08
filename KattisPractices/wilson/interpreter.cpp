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

int main () {
    vector<int> reg (10,0);
    int memory[1000] = {};
    int input;
    int index = 0;
    while (cin >> input) {
        memory[index++] = input;
    }
    
    int count = 0;
    
    int i = 0;
    while (true) {
        count++;
        int a = memory[i]/100;
        int b = memory[i]%100/10;
        int c = memory[i]%10;
        i++;
        if (a == 1) break;
        
        switch (a) {
            case 2:
                reg[b] = c;
                reg[b] %= 1000;
                break;
            case 3:
                reg[b] += c;
                reg[b] %= 1000;
                break;
            case 4:
                reg[b] *= c;
                reg[b] %= 1000;
                break;
            case 5:
                reg[b] = reg[c];
                break;
            case 6:
                reg[b] += reg[c];
                reg[b] %= 1000;
                break;
            case 7:
                reg[b] *= reg[c];
                reg[b] %= 1000;
                break;
            case 8:
                reg[b] = memory[reg[c]];
                reg[b] %= 1000;
                break;
            case 9:
                memory[reg[c]] = reg[b];
                break;
                
            case 0:
                if (reg[c]) {
                    i = reg[b];
                }
                break;
        }

    }
    cout << count << endl;
    
}
