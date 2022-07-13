

int k = 0, key;
vector<int> v;
//bsearch in jumps
for(int b = n/2; b >= 1; b/2){
  while(b+k < n && v[b+k] <= key) k += b;
}
if(v[k] == key) return 1;
///first value of ok that works
//z is some value that is true
//The initial jump length z has to be large enough
//for example some value for which we know beforehand that ok(z) is true.
int x = -1;
for(int b = z; b >= 1; b/2){
  while(!ok(b+x)) x += b;
}
int k = x+1;


//max val of a function that is first increasing then decreasing
for (int b = z; b >= 1; b /= 2) {
    while (f(x+b) < f(x+b+1)) x += b;
}
int k = x+1;

//how many elements x are in array

auto a = lower_bound(array, array+n, x);
auto b = upper_bound(array, array+n, x);
cout << b-a << "\n";

//closest element in some set s
auto it = s.lower_bound(x);
if (it == s.begin()) {
    cout << *it << "\n";
} else if (it == s.end()) {
it--;
    cout << *it << "\n";
} else {
    int a = *it; it--;
    int b = *it;
    if (x-b < a-x) cout << b << "\n";
    else cout << a << "\n";
}

// first element >= key
int l_bound(vector<int> a, int key) {
  if (key < a[0])
    return -1;

  int lo = 0, hi = a.size() - 1;

  while(lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (a[mid] == key)
      return mid;
    else if (a[mid] < key)
      lo = mid;
    else
      hi = mid - 1;
  }

  return lo;
}
//first element > key
int u_bound(vector<int> a, int key) {
  if (key > a[a.size()-1])
    return -1;

  int lo = 0, hi = a.size() - 1;

  while(lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (a[mid] == key)
      return mid;
    else if (a[mid] < key)
      lo = mid+1;
    else
      hi = mid;
  }

  return lo;
}
int b_search(vector<int> a, int key) {
  int lo = 0, hi = a.size() - 1;

  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] == key)
      return mid;
    else if (a[mid] < key)
      lo = mid+1;
    else
      hi = mid-1;
  }

  return -1;
}