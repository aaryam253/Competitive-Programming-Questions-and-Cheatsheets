#include <iostream>
#include <functional>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <vector>

using namespace std;

int main () {
  int num_test;
  scanf("%d", &num_test);

  for (int i = 0; i < num_test; i++) {
    int elements, left = 0, right;
    int flag = 0, error = 0;
    int size = 0;
    vector<int> myVector(100001);
    char commands[100001] = {0};
    scanf ("%s", commands);
    scanf("%d", &elements);

    right = elements;
    size = elements;

    for (int d = 0; d < elements; d++) {
      int number;
      if (d == 0) {
        char dump;
        scanf(" %c", &dump);
        scanf("%d", &number);
        scanf("%c", &dump);
      }
      else if (d == elements - 1) {
        char dump;
        scanf("%d", &number);
        scanf(" %c", &dump);
      }else {
        char dump;
        scanf("%d", &number);
        scanf("%c", &dump);
      }
      myVector[d] = number;
    }

    if (!elements) {
      char dump;
      scanf(" %c", &dump);  //changed this.
      scanf(" %c", &dump);
      // cout<<"BC --> "<<dump<<endl;
      // scanf("[]\n");
    }

    // cout<<"DBG --> "<<elements<<endl;
    // for(int i = 0; i < elements; i++) cout<<myVector[i]<<" ";
    // cout<<endl;

    for (int d = 0; commands[d] != '\0'; d++) {

      if (commands[d] == 'R') {
        if (flag == 0) {
          flag = 1;
        }else {
          flag = 0;
        }
      }

      if (commands[d] == 'D') {
        if (size <= 0) {
          error = 1;
          printf("error\n");
          break;        //added here.
        }else {
          if (flag){
            right--;
            size--;
          }
          else {
            left++;
            size--;
          }
        }
      }
    }

    if (!error) {
      printf("[");
      if (flag) {
        for (int d = right-1; d >= left; d--) {
          if (d == left) {
            printf("%d", myVector[d]);
          }else {
            printf("%d,", myVector[d]);
          }
        }
      }else {
        for (int d = left; d < right; d++) {
          if (d == right-1) {
            printf("%d", myVector[d]);
          }else {
            printf("%d,", myVector[d]);
          }
        }
      }
      printf("]\n");
    }
  }
}
