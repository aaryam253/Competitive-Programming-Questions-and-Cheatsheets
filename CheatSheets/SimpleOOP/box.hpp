//
//  box.hpp
//  oop_cpp_test
//
//  Created by Ler Wilson on 12/1/18.
//  Copyright © 2018 Ler Wilson. All rights reserved.
//

#ifndef box_hpp
#define box_hpp

#include <stdio.h>
#include <iostream>


class box {
public:
    double length, breadth, height;
    box (double l, double b, double h);
    double volume();
    int fancyStuff(int val);
    
private:
    int fancyStuff2(int num);
};

#endif /* box_hpp */
