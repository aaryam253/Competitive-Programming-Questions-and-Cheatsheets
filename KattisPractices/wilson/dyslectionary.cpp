#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<string> myArr;


int main () {
    int flag = 0;
    string input;

    while(!cin.eof()){
        int max = 0;
        
        if(flag)
            cout << endl;
        else
            flag = 1;
        while(getline(cin, input) && input != ""){
            reverse(input.begin(), input.end());
            myArr.push_back(input);
            if (input.size() > max) max = input.size();
            if(input == "") goto NEXT;
        }
        
        NEXT: ;
        
        sort(myArr.begin(), myArr.end());

        
        for (int i = 0; i < myArr.size(); i++) {
            int count = max - myArr[i].length();
            reverse(myArr[i].begin(), myArr[i].end());
            while (count--) {
                cout << " ";
            }
            cout << myArr[i] << endl;
        }
        myArr.clear();
        
    }
    
    
}

