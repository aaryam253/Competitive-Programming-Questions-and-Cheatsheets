//
//  box.cpp
//  oop_cpp_test
//
//  Created by Ler Wilson on 12/1/18.
//  Copyright © 2018 Ler Wilson. All rights reserved.
//

#include "box.hpp"
#include <iostream>


box::box (double l, double b, double h) {
    // similar to self.height
    this->length = l;
    this->breadth = b;
    this->height = h;
}


// Methods
double box::volume() {
    // Method to calc volume
    return this->length*this->breadth*this->height;
}

int box::fancyStuff(int val) {
    return fancyStuff2(val);
}

int box::fancyStuff2(int num) {
    return ++num;
}
