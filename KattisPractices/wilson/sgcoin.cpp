#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <tuple>
#include <string.h>
#include <sstream>

using namespace std;

long long H(long long previousHash, string &transaction,
            long long token) {
    long long v = previousHash;
    for (int i = 0; i < transaction.length(); i++) {
        v = (v * 31 + transaction[i]) % 1000000007;
    }
    
//    cout << (v*7) % 1000000007 << endl;
    return (v * 7 + token) % 1000000007;
}


int main () {
    
    string test = "t";
    string test2 = "a";
    unsigned long long hashValue; cin >> hashValue;
    unsigned long long token1 = 0;
    unsigned long long token2 = 0;
    // Find the tokens which can produce a 7 digit trailing hash
    unsigned long long aHash = H(hashValue , test, token1);
    // Take the closest number to 7 trailing zeroes for this hash and minus away, that's our token
    unsigned long long difference1 = ((aHash/10000000)+1)*10000000 - aHash;
    token1 = difference1;
//    cout << difference1 << endl;
    aHash = H(hashValue , test, token1);
    cout << test << " " << token1 << endl;
    
    unsigned long long bHash = H(aHash, test2, token2);
    unsigned long long difference2 = ((bHash/10000000)+1)*10000000 - bHash;
    token2 = difference2;
    bHash = H(aHash, test2, token2);
    cout << test2 << " " << token2 << endl;
    
//    cout << test2 << " " << token2 << endl;

}
