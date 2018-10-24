#include <iostream>
#include <vector>

#define MAX 200000

using namespace std;

class UF    {
    int *id, cnt, *sz;
public:
	// Create an empty union find data structure with N isolated sets.
    UF(int N)   {
        cnt = N;
	id = new int[N];
	sz = new int[N];
        for(int i=0; i<N; i++)	{
            id[i] = i;
	    sz[i] = 1;
	}
    }
    ~UF()	{
	delete [] id;
	delete [] sz;
    }
	// Return the id of component corresponding to object p.
    int find(int p)	{
        int root = p;
        while (root != id[root])
            root = id[root];
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
	// Replace sets containing x and y with their union.
    void merge(int x, int y)	{
        int i = find(x);
        int j = find(y);
        if (i == j) return;
		
		// make smaller root point to larger one
        if   (sz[i] < sz[j])	{ 
		id[i] = j; 
		sz[j] += sz[i]; 
	} else	{ 
		id[j] = i; 
		sz[i] += sz[j]; 
	}
        cnt--;
    }
	// Are objects x and y in the same set?
    bool connected(int x, int y)    {
        return find(x) == find(y);
    }
	// Return the number of disjoint sets.
    int count() {
        return cnt;
    }
};


int main(int argc, char const *argv[])
{

	int numHouses, numConnections;
	cin >> numHouses >> numConnections;
	UF thisUnion(numHouses);

	for (int i = 0; i < numConnections; ++i)
	{
		int x, y;
		cin >> x >> y;
		// Make sure to record from x-1 and y-1
		thisUnion.merge(x-1, y-1);
	}

	int flag = 0;
	// Question did not specify but apparently we wont be getting houses in the order of 1,2,5,6,7 where there are skipped numbers
	for (int i = 0; i < numHouses; ++i)
	{
		if(!thisUnion.connected(i , 0)) {
			cout << i+1 << endl; // When we wanna print then only do an i+1
			flag = 1;
		}
	}

	if (!flag) cout << "Connected" << endl;

	return 0;
}