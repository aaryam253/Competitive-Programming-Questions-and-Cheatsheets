#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <map>
#include <unordered_set>

using namespace  std;

int main () {
	unordered_map<string, int> myMap ;
	myMap.insert(make_pair("six", 6));
	myMap.insert(make_pair("five", 5));

	cout << myMap.count("six") << endl;
	cout << myMap.count("four") << endl; // Will print zero as it doesnt exist 

	// will reach end of map when it doesnt find anything 
	if (myMap.find("ten") == myMap.end()) cout << "ten does not exist" << endl; // Will be printed 

	myMap.erase(myMap.find("six")); 
	cout << myMap.count("six") << endl; // Will return 0 as it no longer exists 


    map<string, int> myMap_ordered;
    
    myMap_ordered["cat"] = INT_MAX;
    myMap_ordered["dog"] = INT_MAX;
    myMap_ordered["apple"] = INT_MAX;
    

    // O (N) - there is an upper bound for traversals to find successor == O (kN)
    for (auto it = myMap_ordered.begin(); it != myMap_ordered.end(); ++it)
    {
        cout << it->first << endl; // Will print cat first then dog (in order)
    }

    auto it = myMap_ordered.begin();
    next(it); // This is a O log(N) operation 

    // Another method for traversal 
    for (auto it: myMap_ordered) {
        cout << *it << endl;
    }
    
    
    /*
        apple cat dog
                   ^      upper bound of cat
        apple cat dog
               ^          lower bound of cat
    */
    auto it_upper = myMap_ordered.upper_bound("cat");
    auto it_lower = myMap_ordered.lower_bound("cat");
    cout << it_upper->first << endl; // Will print dog
    cout << it_lower->first << endl; // Will print cat


    // Note: BSTs are also used in table ADT
}