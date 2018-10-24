#include <stdio.h>
#include <iostream>
#include <queue>


using namespace std;

int main () {
    int num_queries;
    string placeholder;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > timeline;
    
    do {
        int id, period;
        cin >> placeholder;
        if (placeholder != "#") {
            cin >> id >> period;
            timeline.push(make_tuple(period, id, period));
            
        }
        
    }while (placeholder != "#");
    
    
    cin >> num_queries;
    
    for (int i = 0; i < num_queries; i++) {
        int id, time, period;
        cout << get<1>(timeline.top()) << endl;
        
        id = get<1>(timeline.top());
        period = get<2>(timeline.top());
        time = get<0>(timeline.top()) + period;
        timeline.pop();
        timeline.push(make_tuple(time, id, period));
    }
}
