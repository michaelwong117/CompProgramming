#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <queue> 


#define ll long long

using namespace std;

ll n, p;

vector<ll> gold;

map<int, int> m;
ll cost;
ll sum = 0;

void dfsV(vector<vector<ll>> & pairs, ll p){
	vector<ll> & adjL = pairs[p];
	for(int i = 0; i < adjL.size(); i++){
		if(m.find(adjL[i]) == m.end()){
			m[adjL[i]] = p;
			// cout << cost << " " << gold[adjL[i]] << endl;
			if(gold[adjL[i]] < cost){
				cost = gold[adjL[i]];
			}
			// cout << adjL[i] << endl;
			dfsV(pairs, adjL[i]);
		}

	}
}

void dfs(vector<vector<ll>> &pairs){
	for(int i = 0; i < gold.size(); i++){
		if(m.find(i) == m.end()){
			m[i] = -1;
			cost = gold[i];
			dfsV(pairs, i);
			sum += cost;
		}
		

		
	}


}


int main(){
	// ifstream fin("input.in");
	cin >> n >> p;
	ll res = 0;
	vector<vector<ll>> pairs (n);
	for(ll i = 0; i < n; i++){
		ll g;
		cin >> g; 
		gold.push_back(g);
		// cout << g << endl;
	}
	for(ll i = 0; i < p; i++){
		ll a, b;
		cin >> a >> b;
		// cout << a << " " << b << endl;
		pairs[a-1].push_back(b-1);
		pairs[b-1].push_back(a-1);	
		

	}
	dfs(pairs);
	cout << sum << endl;
}