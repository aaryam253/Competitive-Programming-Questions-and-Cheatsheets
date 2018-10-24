#include <iostream>
#include <stdio.h>
#include <unordered_set>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main () {
    int A, B;
    srand (time(NULL));
    cin >> A >> B;
    string output;
    unordered_set<string> dict;
    for (int i = 0 ; i < B; i++) {
        string word = "";
        do {
            word = "";
            // Randomly create words
            int numLetters = rand()%15 + 1;
            for (int d = 0; d < numLetters; d++) {
                char mychar = rand()%26 + 97;
                word += mychar;
            }
            dict.insert(word);
        }while (dict.find(word) == dict.end());
        
        word += ' '; // Add white space
        output += word;
    }
    //output[output.size()-1] = '\0';
    cout << output << endl;
}
