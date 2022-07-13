
__builtin_clz(x): the number of zeros at the beginning of the number 
__builtin_ctz(x): the number of zeros at the end of the number
__builtin_popcount(x): the number of ones in the number
__builtin_parity(x): the parity (even or odd) of the number of ones

int x = 5328; // 00000000000000000001010011010000
cout << __builtin_clz(x) << "\n"; // 19
cout << __builtin_ctz(x) << "\n"; // 4
cout << __builtin_popcount(x) << "\n"; // 5
cout << __builtin_parity(x) << "\n"; // 1

x | (1 << k) sets the kth bit of x to one
x & ~(1<<k) sets the kth bit of x to zero
x ^ (1<<k) inverts the kth bit of x.
x & (x−1) sets the last one bit of x to zero //1010->1000
x & −x sets all the one bits to zero except the last one bit. //1010->0010
x | (x−1) inverts all the bits after the last one bit.  //1010->1011
any positive number x is a power of two exactly when x & (x−1)=0. //1000-&0111=0

//1 << 4 is 2^4
//bitset<8>(mask).to_string(); convert number mask to binary string

// Set implementation
// The following code declares an int variable x that can contain a subset of {0,1,2,...,31}. After this, the code adds the elements 1, 3, 4 and 8 to the set and prints the size of the set.
int x = 0;
x |= (1<<1);
x |= (1<<3);
x |= (1<<4);
x |= (1<<8);
cout << __builtin_popcount(x) << "\n"; // 4
//print elements of set x
for (int i = 0; i < 32; i++) {
    if (x&(1<<i)) cout << i << " ";
}
//all subsets of x
int b = 0; do {
    // process subset b
} while (b=(b-x)&x);