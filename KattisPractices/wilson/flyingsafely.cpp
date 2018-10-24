#include <iostream>

using namespace std;

int main () {
    int cases;
    cin >> cases;
    int cities, pilots;
    int a, b;
    for(int i = 0; i < cases; i++) {
        cin >> cities >> pilots;
        
        for(int j = 0; j < pilots; j++) {
            cin >> a >> b;
        }
        
        cout << cities - 1 << endl;
    }

}
