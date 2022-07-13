//g++-7 filename.cpp -std=c++14
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

bool overlap(pi l1, pi r1, pi l2, pi r2){
	if(l1.f >= r2.f || l2.f >= r1.f){
		return false;
	}
	if(l1.s >= r2.s || l2.s >= r1.s){
		return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	map<array<int,3>, array<int,3>> rect;
	multiv points;
	ll total = 0;
	int n; cin >> n;
	rep(i, n){
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int len = abs((x1-x2));
 		x1 += len; x2 -= len;
		total += abs((ll) (x1-x2) * (ll) (y1-y2));
		rect[{x2,y2,i}] = {x1,y1,i};
		points.pb({x1, y1, i}); points.pb({x2, y2, i});
	}
	//set a point
	//if you encounter a point, it will be the starting point of another rect
	//or the ending point of your set point 
	//if it's ending point then mark it so you don't set it later 

	//if you encounter the starting point of a rect x, 
	//mark the ending point of x
	//so that you won't subtract overlap twice

	vector<bool> seenEnd (points.size());
	for(int start = 0; start < points.size()-1; start++){
		if(seenEnd[start]) continue; 
		array<int,3> prev = points[start];

		vector<bool> overlapEnd (points.size());

		for(int i = start+1; i < points.size(); i++){
			array<int,3> next = points[i];

			if(overlapEnd[next[2]]) continue;
			//the next point is not the ending of set point
			if(rect[prev] != next){
				overlapEnd[next[2]] = 1;
				if(overlap({prev[0],prev[1]},{rect[prev][0],rect[prev][1]}, 
					{next[0], next[1]}, {rect[next][0], rect[next][1]})){
					int x1 = rect[prev][0], x4 = next[0];
					int y2 = max(prev[1], next[1]);
					int y3 = min(rect[next][1], rect[prev][1]);
					//cout << abs((ll) (x1-x4)* (ll) (y3-y2)) << endl;
					total -= abs((ll) (x1-x4)* (ll) (y3-y2));
				}
			}
			//is ending
			else{
				seenEnd[i] = 1;
				break;
			}

		}
	}


	out(total);




}