#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <ctype.h>
using namespace std;

int main () {
    int TC; cin >> TC; cin.ignore();
    
    string roadname; string buildings; string digits;
    for (int k = 0; k < TC; k++){
        unordered_map<char, int> freq;
        if (k == 0) {
            getline(cin, roadname);
            getline(cin, buildings);
        }
        else {
            roadname = digits;
            getline(cin, buildings);
        }
        
        string start, end, interval, plus;
        while (1) {
            getline(cin, digits);
            //cout << digits[0] << endl;
            if (!isdigit(digits[0]) && digits[0] != '+') break;
            
            if (digits[0] == '+') {
                istringstream b(digits);
                b >> plus;
                b >> start; b >> end; b >> interval;
                for (int i = stoi(start); i <= stoi(end); i += stoi(interval)) {
                    string curr = to_string(i);
                    for (int j = 0; j < (int)curr.size(); j++) {
                        freq[curr[j]]++;
                    }
                }
            }
            else {
                for (int i = 0; i < (int)digits.size(); i++) {
                    freq[digits[i]]++;
                }
            }
        }
        
        cout << roadname << endl;
        cout << buildings << endl;
        for (char i = '0'; i <= '9'; i++) {
            cout << "Make " << freq[i] << " digit " << i << endl;
        }
        int total = 0;
        for (auto &i : freq) total += i.second;
        if (total == 1) cout << "In total " << total << " digit" << endl;
        else cout << "In total " << total << " digits" << endl;
    }
    
    return 0;
}
