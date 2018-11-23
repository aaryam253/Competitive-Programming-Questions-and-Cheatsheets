#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <tuple>
#include <string.h>
#include <sstream>

#define MAX 2147483646

using namespace std;

int main () {
    string line;
    int count = 0;
    int globalSpeed = 0;
    double distance = 0;
    long long globalTime = 0;
    
    while (getline(cin, line)) {
        istringstream iss (line);
        string token;
        string speed = "-1";
        long long time = 0;

        int counter = 0;
        while (getline(iss, token, ' ')) {
            if (counter == 1) {
                speed = token;
            } else {
                int timeCounter = 0;
                istringstream iss (token);
                string token;
                
                while (getline(iss, token, ':')) {
                    if (timeCounter == 0)
                        time += stoi(token) * 3600;
                    else if (timeCounter == 1)
                        time += stoi(token) * 60;
                    else
                        time += stoi(token);
                    
                    timeCounter++;
                }
            }
            counter++;
        }
        
        if (speed != "-1") {
            distance = (globalSpeed/3600.0) * (time - globalTime) + distance;
            globalSpeed = stoi(speed);
            globalTime = time;
        } else {
            distance = (globalSpeed/3600.0) * (time - globalTime) + distance;
            cout << token << " ";
            printf("%0.2lf km\n", distance);
            globalTime = time;
        }
        
//        count++;
//        if (count == 6) break;
        
    }

}
