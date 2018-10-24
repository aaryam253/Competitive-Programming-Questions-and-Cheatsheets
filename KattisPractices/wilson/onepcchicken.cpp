#include <iostream>

using namespace std;

int main () {
    int N, M;
    cin >> N >> M;
    int left = M - N;
    if (left < -1) {
        cout << "Dr. Chaz needs " << (abs(left)) << " more pieces of chicken!" << endl;
    }
    else if (left == -1) {
        cout << "Dr. Chaz needs " << 1 << " more piece of chicken!" << endl;
    }
    else if (left == 1) {
        cout << "Dr. Chaz will have " <<  1 << " piece of chicken left over!" << endl;
    }
    else  {
        cout << "Dr. Chaz will have " <<  left << " pieces of chicken left over!" << endl;
    }
}
