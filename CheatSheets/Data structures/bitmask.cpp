int main () {
    // Note: Instead of using bitset we can use integer instead. We use bitset just for visualisation purposes.
    bitset<8> a;
    a = 34;
    cout << a << endl;
    
    // Multiplication
    a = a << 1; // Multiplies by 2
    cout << a << endl;
    cout << a.to_ulong() << endl;
    
    // Division
    a = 34;
    a = a >> 1; // Divides by 2
    cout << a.to_ulong() << endl;
    
    // Setting bits
    a = 0;
    a |= 1<<3; // Set the bit at index = 3 to 1 (0-based indexing), aka 2^3
    cout << a << endl;
    
    // Checking if bit is turned on
    int b = a.to_ulong();
    bool T = b & (1<<3);
    cout << T << endl; // outputs 1

    // Turn off bit
    b &= (0<<3);
    cout << b << endl; // outputs 0
    
    // Flip j-th term of the set
    int j = 3;
    b ^= (1<<j);
    cout << b << endl; // 8 which is 001000
    
    // Get value of least significant bit that is on, LSOne
    b = 34;
    int t = (b & -b);
    cout << t << endl; // outputs 2, because in binary 00100010, we only consider 10 (LSOne of 00100010) which is 2
    
    // Turn on all bits in a set of size n^11
    int n = 31; // 32 bit integer
    b = (1<<n) - 1;
    cout << b << endl; // we get int max

    // Using bit manipulation to get powers of 2
    cout << (1<<3) << endl; // 2^3 = 8
}
