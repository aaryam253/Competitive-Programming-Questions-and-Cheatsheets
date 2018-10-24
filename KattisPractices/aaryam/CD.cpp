#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unsigned long long J, Ji;
    
    while (1) {
        cin >> J >> Ji;
        if (J == 0 && Ji == 0) break;
        unsigned long long common = 0;
        unordered_set<unsigned long long> Jcd;
        unsigned long long cdJ, cdJi;
        for (unsigned long long i = 0; i < J; i++) {
            cin >> cdJ;
            Jcd.insert({cdJ});
        }
        
        for (unsigned long long i = 0; i < Ji; i++) {
            cin >> cdJi;
            auto search = Jcd.find(cdJi);
            if (search != Jcd.end()) common++;
        }
        cout << common << endl;
    }
    return 0;
}
