#include <bits/stdc++.h> // Will include everything under the sun


using namespace std;



void print_vector (std::vector<int> V)  {
	for (auto it = V.begin(); it != V.end(); it++)
	{
		cout << *it << endl;
	}

	// 'it' is an address that points to the slot. It can be incremented to point to the next
	// '*it' means dereferencing the pointer and obtaining its value.
}

int main(int argc, char const *argv[])
{
	std::vector<int> V;
	for (int i = 0; i < 10; ++i) V.push_back(i);

	//cout << "Before" << endl;
	//print_vector (V);

	// Insert an element(10) in the first position
	V.insert(V.begin(), 10);

	//cout << "After insertion of -1" << endl;
	//print_vector (V);

	// Erasing an item in the vector
    vector<int> myvec ({1,2,3,4});

    myvec.erase(++myvec.begin()); // should remove 2 and shift the rest down

    for (auto it = myvec.begin(); it != myvec.end(); it++) {
        cout << *it << endl;
    }
    // Will print 1 3 4

    myvec.erase(++myvec.begin()+2); // should remove 4

	reverse(V.begin(), V.end());
	//print_vector (V);

	//cout << "After sorting the array" << endl;
	sort(V.begin(), V.end());
	//print_vector(V);

	string a = "Hello world";
	cout << a.substr(2) << endl; // char index 2 to end
	cout << a.substr(3, 2) << endl; // char index 3 to 2


	string x = "this is a test";
	char *p = new char[10];
	strcpy (p, x.c_str()); // Copies string x to char array p using .c_str()
	cout << p << endl;
	// Usually done so we can use this for tokenisation (char operations)

	string out;
	istringstream iss (x);

	while(!iss.eof()) {
		iss >> out;

		// Note we cant just cout iss as it is a stream. we have to output it to string object.
	    cout << out << endl;
	}
	return 0;
}
/*Notes for vectors
    vector<int> v;

Iterators
    v.begin()
    v.end()
Capacity
    v.size()
    v.empty()
Element Access
    v[<index>]
    v.at(<index>)
    v.front()
    v.back()
Modifiers
    v.push_back(<value>)
    v.pop_back()
    v.insert(<iterator position>)
    v.erase(<iterator position>)
    v.swap(<vector>)
    v.clear()
*/
