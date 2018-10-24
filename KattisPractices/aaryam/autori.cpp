//
//  main.cpp
//  Autori
//
//  Created by Aaryam Srivastava on 22/12/2017.
//  Copyright © 2017 LearnAppMaking. All rights reserved.
//

#include <iostream>
#include <string>

int main(void) {
    std::string name;
    int i;
    
    std::cin >> name;
    
    for (i = 0; i < name.length(); i++) {
        if (isupper(name.at(i))) {
            std::cout << name.at(i);
        }
    }
    
    std::cout << std::endl;

    return 0;
}
