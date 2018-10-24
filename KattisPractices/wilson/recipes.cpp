#include <iostream>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

int main () {
    int TC;
    cin >> TC;
    for (int i = 0; i < TC; i++) {
        unordered_map<string, double> namePercentage;
        queue<string> order;
        int R;
        double P, D, mainWeight = 0;
        cin >> R >> P >> D;
        double scaleFactor = D/P;
        
        for (int d = 0; d < R; d++) {
            // each ingredient
            string name;
            double weight, percentage;
            cin >> name >> weight >> percentage;
            if (percentage == 100.0) {
                mainWeight = weight;
            }
            namePercentage.insert(make_pair(name, percentage));
            order.push(name);
        }
        
        cout << "Recipe # " << i+1 << endl;
        while (!order.empty()) {
            cout << order.front() << " ";
            double calculatedNum = namePercentage[order.front()] * scaleFactor * mainWeight * 0.01;
            printf("%0.1lf\n", calculatedNum);
            order.pop();
        }
        
        cout << "----------------------------------------" << endl;
    }
    
}
