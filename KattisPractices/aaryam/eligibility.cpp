//
//  main.cpp
//  Eligibility
//
//  Created by Aaryam Srivastava on 15/12/2017.
//  Copyright © 2017 LearnAppMaking. All rights reserved.
//

#include <iostream>
#include <string.h>
#define MAX_LENGTH 30

typedef struct {
    char name[MAX_LENGTH];
    char began_post[MAX_LENGTH];
    char date_of_birth[MAX_LENGTH];
    int courses;
} contestant_t;

int main (void) {
    int contestant_no, i;
    char *began, *date;
    
    scanf("%d", &contestant_no);
    
    contestant_t contestants[contestant_no];
    for (i = 0; i < contestant_no; i++) {
        scanf("%s %s %s %d", contestants[i].name, contestants[i].began_post, contestants[i].date_of_birth, &contestants[i].courses);
    }
    
    for (i = 0; i < contestant_no; i++) {
        began = strtok(contestants[i].began_post, "/");
        date = strtok(contestants[i].date_of_birth, "/");
        
        if (strcmp(began, "2009") > 0 || strcmp(date, "1990") > 0) {
            printf("%s eligible\n", contestants[i].name);
        }
        else if (contestants[i].courses > 40) {
            printf("%s ineligible\n", contestants[i].name);
        }
        else if (contestants[i].courses <= 40){
            printf("%s coach petitions\n", contestants[i].name);
        }
    }

    return 0;
}
