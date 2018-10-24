#include <iostream>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <unordered_map>

using namespace std;


int main () {
    int cases;
    string word;
    cin >> cases;
    getline(cin, word); // Flush CIN
    for (int i = 0; i < cases; i++) {
        //string input;
        string line;
        getline(cin, line);
        unordered_map<string, string> sounds_animal;
            string sound;
            cin >> word;
            while(word != "what"){
                cin >> word; // "goes"
                cin >> sound;
                
                sounds_animal[sound] = word;
                
                cin >> word;
            }
        
        getline(cin,word); //flush cin

        
        istringstream iss (line);
        string token;
        while (getline(iss, token, ' '))
        {
            if (sounds_animal[token] == "") {
                cout << token << " ";
            }
        }
        cout << endl;
    }
    
}

