//g++ filename.cpp -std=c++14 -DH
#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define endl '\n'
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define pq priority_queue<int, vector<int>, greater<int>>
#define mpq priority_queue<int>
 
typedef long long ll; typedef vector<int> vi;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
vpi p;
bool collinear(pi a, pi b, pi c){
	return (ll) (a.s-b.s)*(ll)(a.f - c.f) == (ll)(a.s-c.s) * (ll)(a.f - b.f);
}
void check(pi a, pi b){
	vpi z;
	for(auto x: p) if(!collinear(a,b,x)) z.pb(x);
	for(int i = 2; i < z.size(); i++) if(!collinear(z[0],z[1],z[i])) return;
	cout << "YES" << endl;
	exit(0);
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("filename.in"); ofstream fout("filename.out");
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x,y; cin >> x >> y;
		p.pb({x,y});
	}
	if(n < 3){
		cout << "YES" << endl;
		return 0;
	}
	check(p[0],p[1]);
	check(p[0],p[2]);
	check(p[1],p[2]);
	cout << "NO" << endl;
}