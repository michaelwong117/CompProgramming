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
typedef long double ld;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
const int N = 1e3+1;
int n;
ld px[N], py[N];

pair<ld,ld> reflect(ld a, ld c, ld x, ld y){
	ld d = (x + (y - c) * a) / (1 + a*a);
	return {(ld)2*d - x, (ld)2*d*a - y + (ld)2*c};

	// Given (x,y) and a line y = ax + c we want the point (x', y') reflected on the line.
	// Set d = (x + (y - c)*a)/(1 + a^2)
	// Then x' = 2*d - x
	// and y' = 2*d*a - y + 2c
}
ld slope(int x1, int y1, int x2, int y2){
	if(x2-x1 == 0) return -1e9; //vertical slope
	if(y2-y1 == 0) return 0; //horizontal slope
	return ((ld) y2-y1) / ((ld) x2-x1);
}
ld perp(ld slope){
	if(slope == -1e9) return 0; //horizontal perp slope
	if(slope == 0) return -1e9; //vertical perp slope
	return ((ld) -1 / slope); //perp slope
}
ld yint(ld slope, ld x, ld y){
	return y - (slope * x); //get y-int by plugging in point 
}
void solve(int f){
	for(int i = 0; i < n; i++){
		if(i == f) continue;
		ld m = slope(px[i], py[i], px[f], py[f]), a = perp(m);
		ld yline = (ld) (py[i] + py[f]) / 2.0, xline = (ld) (px[i] + px[f]) / 2.0;
		// cout << xline << " " << yline << endl;

		pair<ld,ld> opp;

		// cout << m << " " << a << endl;

		// cout << px[i] << " " << py[i] << " " << px[f] << " " << py[f] << endl << endl;

		for(int j = 0; j < n; j++){
			if(a != 0 && a != -1e9) opp = reflect(a, c, px[j], py[j]);
			if(a == 0) opp = {px[j], 2*yline - py[j]};
			if(a == -1e9) opp = {2*xline - px[j], py[j]};
			// cout << px[j] << " " << py[j] << " " << opp.f << " " << opp.s << endl;

		}
		// cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> px[i] >> py[i];
	}
	solve(0), solve(1);


	

	

}