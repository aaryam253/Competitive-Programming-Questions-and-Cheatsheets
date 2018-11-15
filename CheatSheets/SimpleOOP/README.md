General OOP theory

Classes: a template with all relevant attributes and methods to use those attributes

Object: an instance of a class

Objectives of OOP:

-Encapsulation of all relevant methods/attributes

    -The class contains the variables that represents the class:
        e.g A colour of a pixel having R, G and B values
        
    -The class contains the functions that can manipulate or use the variables within the class
        e.g Functions that can change the values of R, G or B in the class
        
-Private/Public distinction

    -If you set something as private, users will not be able to directly reassign the value of the variable which is protected
        e.g If you protect R, G and B values.  the line (colour.R = 70) will not be able to alter the value.
        
    -This is a form of hiding your data, good practice.
    
    -When variables are private, you need to create public methods to alter those variables.
        e.g When R, G and B are protected, we need a public function set_value_R(int value) to change the value of R individually.
    
-Inheritance/Polymorphism
    -You can do inheritance to inherit all methods and attributes of the parent class.
    
        Very useful when you are dealing with similar things (e.g cars can have the subset of vans, trucks)
        
        the parent class acts as the base while the child class will include new attributes and methods that add on to the parent class
            e.g See example below. Rectangle and Triangle are child classes of the parent class Polygon.

EXAMPLE: A good idea to look at it in code form. README.md does not show it right.

############################################################

#include <iostream>

using namespace std;

class Polygon {                     // An example of encapsulation

  protected:
    int width, height;
    
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
      
};

class Rectangle: public Polygon {
  public:
    int area()
      { return width*height; }
};

class Triangle: public Polygon {
  public:
    int area()
      { return width*height/2; }
};

int main () {

  Rectangle rect;
  
  Triangle trgl;
  
  Polygon * ppoly1 = &rect;
  
  Polygon * ppoly2 = &trgl;
  
  ppoly1->set_values (4,5);
  
  ppoly2->set_values (4,5);
  
  cout << rect.area() << '\n';
  
  cout << trgl.area() << '\n';
  return 0;
}
############################################################
