//
//  dynamic_array.cpp
//  oop_cpp_test
//
//  Created by Ler Wilson on 12/1/18.
//  Copyright © 2018 Ler Wilson. All rights reserved.
//

#include "dynamic_array.hpp"
#include <iostream>

using namespace std;

dynamic_array::dynamic_array() {
    this->arr = new int[size+1];
}

dynamic_array::~dynamic_array(){
    // Deconstructor
    //delete [] arr;
}

void dynamic_array::add(int element) {
    // Resize
    int* t_array = new int[this->size+1];
    copy(t_array);
    t_array[this->size] = element;
    delete [] arr;
    this->arr = t_array;
    //delete [] t_array; - WARNING do not do this as the compiler will reuse this space again
    this->size++;
}

void dynamic_array::pop_back() {
    // delete the last memory also
    this->size--;
    int* t_array = new int [this->size];
    copy(t_array);
    
    delete [] this->arr;
    this->arr = t_array;
}

int dynamic_array::get(int i) {
    return arr[i];
}

int dynamic_array::getSize() {
    return this->size;
}

void dynamic_array::clear() {
    delete [] this->arr;
    this->size = 0;
}

// Concatenation
dynamic_array dynamic_array::operator+(dynamic_array other) {
    dynamic_array result;
    int newSize = other.size + this->size;
    int* temp = new int[newSize];
    int i, index = 0;
    for (i = 0; i < this->size; i++) temp[index++] = this->arr[i];
    for (i = 0; i < other.size; i++) temp[index++] = other.arr[i];
    result.size = newSize;
    delete [] result.arr;
    result.arr = temp;
    
    return result;
}

// Comparison
bool dynamic_array::operator==(dynamic_array other) {
    if (other.size != this->size) return false;
    for (int i = 0; i < other.size; i++) {
        if (other.arr[i] != this->arr[i]) return false;
    }
    return true;
}

bool dynamic_array::operator!=(dynamic_array other) {
    if (other.size != this->size) return true;
    for (int i = 0; i < other.size; i++) {
        if (other.arr[i] == this->arr[i]) return false;
    }
    return true;
}

// Private methods
void dynamic_array::copy(int* t_array) {
    for (int i = 0; i < this->size; i++) {
        t_array[i] = arr[i];
    }
}


