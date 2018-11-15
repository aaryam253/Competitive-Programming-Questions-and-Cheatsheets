//
//  main.cpp
//  oop_cpp_test
//
//  Created by Ler Wilson on 12/1/18.
//  Copyright © 2018 Ler Wilson. All rights reserved.
//

#include <iostream>
#include "box.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    box *hello = new box(1,2,3); // Creating a new box with the parameters 
    cout << "Height: " << hello->height << endl; // shortcut to de-reference the pointer and accesses the variable
    cout << "Volume: " << hello->volume() << endl;
    cout << "Fancy operations: " << hello->fancyStuff(2) << endl; // Demo of a private method
    
    return 0;
}
