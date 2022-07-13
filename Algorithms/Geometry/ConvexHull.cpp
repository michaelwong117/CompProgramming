x//g++-7 filename.cpp -std=c++14
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define pq priority_queue<int, vector<int>, greater<int>>
#define mpq priority_queue<int>
#define endl '\n'
#define out(x) cout << x << endl
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

typedef complex<int> point;

int cross(point a, point b) {
	return imag(a * conj(b));
	//conj(b) = (x2 - y2i)
	//a = (x1 + y1i)
	//z = x2x1 + x2y1i - y2x1i - y2y1
	//imag(z) = (x2y1 - x1y2)
	//return x1 * y2 - x2 * y2
}

int cross(point a, point b, point c){
	//this is doing it in pairs
	//x2 - x1, y2-y1, simplified
	return cross(a - b, c - b);
	//a - b and c - b is just combining the vectors into points
	//a - b is a vector in the direction from a to b
	//return cross((a.x - b.x, a.y-b.y), (c.x-b.x, c.y-b.y))
}

vector<point> convex_hull(vector<point> v) {
	vector<point> hull;
	sort(all(v));
	//upper hull and lower hull
	for(int i = 0; i < 2; i++){
		int sz = hull.size();
		for(point p: v){
			//hull.back() is hull[hull.size()-1]
			//equal allows collinear points on your hull
			//might have to delete multiple points to ensure that hull is convex

			while (hull.size() >= sz+2 && cross(p, hull.back(), hull[hull.size()-2]) 
				>= 0) hull.pop_back();
			hull.pb(p);
		}
		//we want to get rid of extra point that belongs to 
		//both upper and lower hull (leftmost, rightmost)
		//upper hull and lower hull you need to run twice bc you might miss points in first go
		hull.pop_back();
		reverse(all(v));
	}
	return hull;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
}