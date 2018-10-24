#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

int main () {
    //vector<long int> tree;
    int num;
    long long int max = 0;
    string input;
    cin >> num;
    for (int i = 0; i <= num; i++) {
        max += pow(2, i);
    }
    
    int index = 0;
    // 2i+1, 2i+2
    //cin >> input;
    getline(cin, input);
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == 'L') {
            index = 2*index+1;
        }else if (input[i] == 'R'){
            index = 2*index+2;
        }
    }
    cout << max - index << endl;
}
