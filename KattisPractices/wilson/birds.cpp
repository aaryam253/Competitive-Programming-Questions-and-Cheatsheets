#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    vector<unsigned long long> wire;
    unsigned long long l, d;
    int n;
    
    cin >> l >> d >> n;
    
    for (int i = 0; i < n; i++) {
        unsigned long long pos;
        cin >> pos;
        wire.push_back(pos);
    }
    
    sort(wire.begin(), wire.end());
    unsigned long long count = 0;
    
    for (int i = 0; i < wire.size(); i++) {
        if (!i) {
            // Initial - closest to the first pole
            if (wire[i] >= 6) {
                count += (wire[i]-6) / d;
            }
        }else if (i == wire.size()-1){
            // End of wire
            if (l-wire[i] >= 6) {
                count += (l-6-wire[i])/d;
            }

        }else {
            if (wire[i]-wire[i-1] - d >= d) {
                count += (wire[i]-wire[i-1]-d/d);

            }
        }
    }
    
    if (!n) {
        if (l - 6 >= 6) {
            // Bird can stand at the start
            count++;
        }
        
        if (l - 12 >= d ) {
            // Bird can stand at the end
            count++;
        }
        
        count += (l-6-6-d)/d;
    }
    
    cout << count << endl;
    
}

