struct cow {
	int day;
	int id;
	int change;
};

sort(v.begin(), v.end(), [](cow& a, cow& b) {
		return a.day < b.day;
	});
sort(A.begin(), A.end(), [](const measurement& a, const measurement& b) {
    return a.day < b.day;
});


// For example, the following struct P contains the x and 
// y coordinates of a point. 
// The comparison operator is defined so 
// that the points are sorted primarily by the
// x coordinate and secondarily by the y coordinate.

struct P {
    int x, y;
    bool operator<(const P &p) {
       if (x != p.x) return x < p.x;
       else return y < p.y;
} };


vector<P> v;
sort(all(v));

// For example, the following comparison function comp sorts 
// strings primarily by length and secondarily by alphabetical order:
bool comp(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}