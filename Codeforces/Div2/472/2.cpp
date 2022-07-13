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

vector<string> v;
map<string, int> cost, group;
vi mincost;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("filename.in"); ofstream fout("filename.out");
	int n, k, m; cin >> n >> k >> m;
	v.resize(n+1); mincost.resize(k+1, 1e9);
	for(int i = 1; i <= n; i++){
		string s; cin >> s;
		v[i] = s;
	}
	for(int i = 1; i <= n; i++){
		int c; cin >> c;
		cost[v[i]] = c;
	}
	// for(auto a: cost) cout << a.f << " " << a.s << endl;
	for(int j = 1; j <= k; j++){
		int x; cin >> x;
		for(int i = 1; i <= x; i++){	
			int k; cin >> k;
			mincost[j] = min(mincost[j], cost[v[k]]);
			group[v[k]] = j;
		}
	}
	ll sum = 0;
	for(int i = 0; i < m; i++){
		string s; cin >> s;
		auto it = group.find(s);
		if(it == group.end()) sum += cost[s];
		else sum += mincost[group[s]];
	}
	cout << sum << endl;

}