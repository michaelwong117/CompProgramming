bitset<10> s(string("0010011010")); // from right to left
cout << s[4] << "\n"; // 1
cout << s[5] << "\n"; // 0
       
// The function count returns the number of ones in the bitset:
// The following code shows examples of using bit operations:
     
bitset<10> s(string("0010011010"));
cout << s.count() << "\n"; // 4
     
bitset<10> a(string("0010110110"));
bitset<10> b(string("1011011000"));
cout << (a&b) << "\n"; // 0010010000
cout << (a|b) << "\n"; // 1011111110
cout << (a^b) << "\n"; // 1001101110