----------------------------------------------------------------------------------------------------------------------
// Overriding insert of an array 
void insert (int v, int pos, int *arr, int* size) {

	for (int i = pos; i < size - 1; ++i)
	{
		A[i+1] = A[i]; // In this case, the last element will be LOST or overridden. We should increase the size first. 
	}	
	A[pos] = v;
	*size++;
}


----------------------------------------------------------------------------------------------------------------------
// Direct reference of .size() in a loop esp for item removal

for (int d = 0; d < list.size(); d++) {
	// Will only run "halfway" as each time list pops, it will update list.size()
	cout << "Transferred: " << list.top() << endl;
	list.pop();
}
----------------------------------------------------------------------------------------------------------------------

// Time complexities
/*

F(n) = n + (1/2)n + (1/3)n + ... + 1 is O(2^n) easily mistaken for O(n)

actual fact: harmonic series, so its Olog(n)

Summation usually can be derived from the formula: Sn = a(1-r^n)/(1-r) for geometric progression 

*/

----------------------------------------------------------------------------------------------------------------------
// End iterator of a vector/ deque

vector<int> myvec ({1,2,3});

auto it = myvec.end();

// *it is not 3, its actually the one next to 3 which is a null object

----------------------------------------------------------------------------------------------------------------------
// Getting kth element from a std::list 

// O(k) as std::list is a doubly linked list 


// Inserting elements into the middle of the deque works 

----------------------------------------------------------------------------------------------------------------------
// Do not call to see if a data exists in a map or set 

unordered_map <int, int> myMap;
cout << myMap.size() << endl; // Will print 0

cout << myMap[3] << endl; // this will print 0 or any floating number 

cout << myMap.size() << endl; // Will print 1, calling myMap[3] will somehow produce an entry there 

// Always use find first 

if (myMap.find(3) != myMap.end())
	cout << myMap[3] << endl;

----------------------------------------------------------------------------------------------------------------------
// Time comlpexity of inserting into priority queue/ AVL tree is not exactly Nlog(N)
// There are only a somewhat fixed number of swaps as the element is inserted

priority_queue <int> pq; 
int n = 10;

while(n--) {
    pq.insert(n);
}
/* vs */
n = 10;
vector<int> v;

while(n--) {
	v.push_back(n);    
}
----------------------------------------------------------------------------------------------------------------------
// Modifying dijkstra to perform longest path algos in the following ways will not work: 

1.Directly use “max” operations instead of “min” operations.
2.Convert all positive weights to be negative. Then find the shortest path.
3.Give a very large positive number M. If the weight of an edge is w, now M-w is used to replace w. Then find the shortest path.

// However, dijkstra can still be applied to a DAG to find longest path, it will be more inefficient compared to toposort + one pass 
----------------------------------------------------------------------------------------------------------------------



