//faster UFDS algorithm that optimises in certain areas
class UnionFindFast {
private:
    //only consider the set and its rank
    vi p, rank;
public:
    //construct the UFDS
    UnionFindFast(int N) {
        p.assign(N, 0); rank.assign(N, 0);
        for (int i = 0; i < N; i++) { p[i] = i; rank[i] = 0;}
    }
    
    //use a base function, which resembles the representative root of each set
    bool isSameSet(int a, int b) {return base(a) == base(b);}
    
    //union of two sets
    void unionSet(int a, int b) {
        int i = base(a); int j = base(b);
        if (i == j) return;
        
        //check rank to see which tree will be appended on to another tree
        if (rank[i] < rank[j]) p[i] = j;
        else if (rank[i] > rank[j]) p[j] = i;
        else {p[j] = i; rank[i] = rank[i] + 1;}
    }
    
    //find the representation root of each set
    int base(int a) {
        while (a != p[a]) a = p[a];
        return a;
    }
};
