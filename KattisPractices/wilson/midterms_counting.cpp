#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <sstream>
#include <deque>
#include <string>

using namespace std;


int main () {
    
    int N, Ai;
    cin >> N;
    
    long long ans = 0;
    int arr[4] = {0};
    
    
    for (int i = 1; i <= N; i++) {
        cin >> Ai;
        arr[Ai]++; int travel = 0;
        for (int d = 1; d < 4; d++) {
            travel += arr[d];
            if (travel == i/2.0) {
                if (!(i%2)) {
                    // Even number
                    ans += (d + d + 1) / 2;
                    // Take the mid + the next / 2
                    cout << "Take the (mid + next)/2:" << endl;
                    cout << (d + d + 1) / 2 << endl;
                    break;
                }else{
                    // Odd number
                    ans += d;
                    // Take the middle
                    cout << "Take the middle:" << endl;
                    cout << d << endl;
                    break;
                }
                
            }
            else if (travel > i/2.0)
            {
                // Overshot, take the current index and break
                ans += d;
                cout << "Overshot:" << endl;
                cout << d << endl;
                break;
            }
        }
    }
    cout << "Final answer: " << ans << endl;

}


