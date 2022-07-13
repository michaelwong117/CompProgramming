// The speciality of this set is that we have access to the 
// indices that the elements would have in a sorted array. 




// The function find_by_order returns an iterator to the element at a given position:

Tree<int> s;
s.insert(2);
s.insert(3);
s.insert(7);
s.insert(9);
auto x = s.find_by_order(2);

cout << *x << "\n"; // 7


And the function order_of_key returns the position of a given element:
If the element does not appear in the set,
we get the position that the element would have in the set:

cout << s.order_of_key(7) << "\n"; // 2
cout << s.order_of_key(6) << "\n"; // 2
cout << s.order_of_key(8) << "\n"; // 3
 