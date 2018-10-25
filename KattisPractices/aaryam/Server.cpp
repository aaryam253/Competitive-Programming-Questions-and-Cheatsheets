//
//  main.cpp
//  Server
//
//  Created by Aaryam Srivastava on 24/1/2018.
//  Copyright © 2018 LearnAppMaking. All rights reserved.
//

#include <iostream>
using namespace std;

int main(void) {
    int tasks, time, total_time = 0, job, count = 0;
    
    cin >> tasks >> time;
    
    for (int i = 0; i < tasks; i++) {
        cin >> job;
        total_time += job;
        if (total_time > time) {
            break;
        }
        
        count++;
    }
    
    cout << count << endl;
    
    return 0;
}
