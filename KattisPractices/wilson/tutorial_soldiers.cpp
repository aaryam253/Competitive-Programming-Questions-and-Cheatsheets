#include <iostream>
#include <list>
#include <stdio.h>

using namespace std;

void remove (int a, int b, list<int> *soliders) {
    for (auto it = soliders->begin(); it != soliders->end(); ) {
        if (*it == a) {
            it = soliders->erase(it);
            if (prev(it) != soliders->end()) {
                printf("%d", *prev(it));
            }else {
                printf("%d", -1);
            }
            if (a == b) {
                if (it != soliders->begin() && it != soliders->end()) {
                    printf(" %d\n", *it);
                }else {
                    printf(" %d\n", -1);
                }
            }
        }else if (*it == b) {
            it = soliders->erase(it);
            if (it != soliders->begin() && it != soliders->end()) {
                printf(" %d\n", *it);
            }else {
                printf(" %d\n", -1);
            }
        }else {
            it++;
        }
    }
}

int main () {
    int num, G;
    list<int> soldiers;
    scanf("%d", &num);
    scanf("%d", &G);
    for (int i = 0; i < num; i++) {
        soldiers.push_back(i);
    }
    
    for (int i = 0; i < G; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        remove(a, b, &soldiers);
    }
    
}
