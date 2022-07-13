//g++ filename.cpp -std=c++14 -DH

#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1e9 + 7

typedef long long ll;
typedef pair<int, string> pis;
typedef pair<int,int> pii;

struct Edge {
	ll length;
	ll to;
};

//set tab size to 3

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	ll n, m;
	cin >> n >> m;
	vector<vector<Edge>> graph (n);
	vector<ll> city (n);
	//dist from city i to all cities 
	vector<vector<ll>> dist (n);
	for(ll i = 0; i < m; i++){
		ll v, u, w;
		cin >> v >> u >> w;
		Edge e;
		e.to = v-1;
		e.length = w;
		graph[u-1].push_back(e);
		e.to = u-1;
		graph[v-1].push_back(e);
	}
	for(ll i = 0; i < n; i++){
		cin >> city[i];
	}
	for(ll i = 0; i < n; i++){
		dist[i].pb(city[i]);
		for(ll j = 0; j < graph[i].size(); j++){
			// cout << i << " " << graph[i][j].to << " ";
			// cout << city[graph[i][j].to] << " " << graph[i][j].length << endl;
			dist[i].pb(city[graph[i][j].to]+(2*graph[i][j].length));
		}
	}
	for(ll i = 0; i < dist.size(); i++){
		if(i == dist.size()-1) cout << *min_element(dist[i].begin(), dist[i].end()) << endl;
		else cout << *min_element(dist[i].begin(), dist[i].end()) << " ";
	}







}