#include <bits/stdc++.h> // Will include everything under the sun 

using namespace std; // Declaration of the namespace in the global scale, but might cause problems of name clashing 


void loops () {
	// Integer type for loop 
	for (int i = 0; i < 5; i++) {
		cout << i << endl;
	}

	// iterator type for loop 
	string input = "hello";
	for (auto it = input.begin(); it < input.end(); ++it) {
		// Usually used for cpp string manipulations 
	}
}

int factorial (int n) {
	if (n <= 1) {
		return n;
	}
	return n*factorial(n-1);
}

void binom () {
	int n, k;
	cin >> n >> k;
	cout  << factorial (n)/((factorial(k))*factorial(n-k)) << endl;;
}

// Precond: n > 0
int pascal(const int n, const int x) {
    if(n == 0 || n == 1 || x == 0 || x == n)
        return 1;
    return pascal(n-1, x-1) + pascal(n-1, x);
}

int* merge (int* A, int* B) {
	int size1 = 4; // size of A
	int size2 = 3; // size of B

	int * result = new int[size1 + size2]; // 'new' to allocate new memory dynamically during runtime 
	int i = 0, j = 0, index = 0;
	while (i < size1 && j < size2) {
		// Insert in increasing order 
		if (A[i] > B[j]) {
			result[index++] = B[j++]; 
		}

		if (A[i] < B[j]) {
			result[index++] = A[i++];
		}
		// When they are both equal
		if (A[i] == B[j]) {
			result[index++] = B[j++];
			result[index++] = A[i++];
		}
	}
	// Settle the left overs 
	while (size1 - i > 0) {
		result[index++] = A[i++]; 
	}
	while (size2 - j > 0) {
		result[index++] = B[j++];
	}
	return result; // Function which returns a pointer/ array 
}


int main(int argc, char const *argv[])
{
	printf ("Hello world\n"); 
	/* vs */
	cout << "Hello world" << endl;
	cout << "Hello world\n";	

	int n, k;
	n = 10;
	k = 3;
	cout << "binom of 10c3: " << pascal (n, k) << endl;


	/**
	Pointers are simply integers referencing the address of a box 
	Pointers themselves may be contained in boxes 
	Pointer sizes are dependent on the size of the system (eg. 32bit for 32bit systems)
	Note that *p means deferencing a pointer i.e getting the value out of that address
	*/

	// Merging arrays by allocating memory 
	int A[4] = {1,2,3,4};
	int B[3] = {4,5,6};
	int* result = merge (A, B);
	cout << "Size of A: " << sizeof(A) << endl; // note that sizeof() can only be used for Arrays and not a pointer to an array 
	cout << "Result of mergesort: ";
	for (int i = 0; i < 7; i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	

	delete result; // This removes our priviledge to that memory spot. (Doesnt mean its gone, just means other programs are free to use it)
	// delete result; - Deletes the memory again, can be dangerous and can delete other program's memory 

	int x = 10;
	cout << "x is initially 10" << endl;
	int& x_r = x; // & is a pointer reference 
	x_r = 1000; // Notice how it de-references itself automatically unlink in pointers where we have to do as follows

	int* x_p = &x;
	*x_p = 1000; // De-reference the pointer variable first. 

	cout << x << endl;


	return 0; // Used to show that the program exits successfully 
}


Hierarchy of compilation 
C++ -> assembly code -> machine code -> executable .exe (after link id)

Declaring static types is better as it can throw and identify errors on compilation 


For kattis questions that do not specify the num of test cases, 
use this
	for (i = 1; cin >> size; i++) {
		// your code here
	}




Using of cin/ cout with scanf/ printf - will cause closeness 
Maybe just use scanf/ printf 

if you use cin/cout, use 
ios_base::sync_with_stdio(false);cin.tie(NULL);

Using of global variables is fine in CS2040C




