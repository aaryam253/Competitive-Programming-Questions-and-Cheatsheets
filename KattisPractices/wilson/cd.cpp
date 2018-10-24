#include <iostream>
#include <stdio.h>
#include <unordered_set>

using namespace std;


int main () {
    int numJack, numJill;
    while (true) {
        unordered_set<int> jack;
        int count = 0;
        scanf("%d %d", &numJack, &numJill);
        if (numJack == 0 && numJill == 0) {
            break;
        }
        
        for (int i = 0; i < numJack; i++) {
            int num;
            scanf("%d", &num);
            jack.insert(num);
        }
        
        for (int i = 0; i < numJill; i++) {
            int num;
            scanf("%d", &num);
            if (jack.find(num) != jack.end()) {
                count++;
            }
        }
        printf("%d\n", count);
    }
}

