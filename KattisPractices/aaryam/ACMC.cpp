//
//  main.cpp
//  Association for Computing Memory
//
//  Created by Aaryam Srivastava on 13/2/2018.
//  Copyright © 2018 Developers. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int comparator(const void* a, const void* b) {
    return *((int*)a) - *((int*)b);
}

void solves(int first, int *times, size_t count) {
    if (first > 300) cout << "0 0" << endl;
    else if (first == 300) cout << "1 300" << endl;
    else {
        int solved = 1;
        int time = first;
        int penalty = first;
        qsort(times, count, sizeof(int), comparator);
        for (int i = 0; i < count; i++)
        {
            if (time + times[i] > 300) break;
            time += times[i];
            penalty += time;
            solved++;
        }
        cout << solved << " " << penalty << endl;
    }
}

int main(void) {
    int questions, position;
    cin >> questions >> position;
    
    int first = 0, times[questions - 1];
    for (int i = 0; i < position; i++) scanf("%d", times + i);
    cin >> first;
    for (int i = position; i < questions - 1; i++) scanf("%d", times + i);
    solves(first, times, questions - 1U);
    
    return 0;
}

