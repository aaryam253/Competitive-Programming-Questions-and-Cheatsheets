#include <iostream>


using namespace std;




int main () {
    int num; cin >> num;
    while (num--) {
        string input, input2;
        cin >> input >> input2;
        string output = input2;

        for (int i = 0; i < input.size(); i++) {
            if (input2[i] == input[i]) output[i] = '.';
            else output[i] = '*';
        }
        cout << input << endl;
        cout << input2 << endl;
        cout << output << endl;
        cout << endl;
    }
}
