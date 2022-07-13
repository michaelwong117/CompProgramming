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


int main(){
	// ifstream fin("input.in");
	ll n, m;
	cin >> n >> m;
	vector<ll> gold;
	vector<bool> seen (n);
	vector<vector<int>> pairs (n);
	ll res = 0;
	for(ll i = 0; i < n; i++){
		ll g;
		cin >> g; 
		gold.push_back(g);
		// cout << g << endl;
	}
	ll sum = 0;
	for(ll i = 0; i < m; i++){
		ll a, b;
		cin >> a >> b;
		pairs[a-1].push_back(b-1);
		pairs[b-1].push_back(a-1);	
		

	}
	int start = 0;
	while(1){
		int first = -1;
		for(int i = start; i < seen.size(); i++){
			if(!seen[i]){
				first = i;
				break;
			}
		}
		if(first == -1){
			break;
		}
		start = first+1;
		queue<int> q;
		q.push(first);
		ll cost = gold[first];
		while(!q.empty()){
			int f = q.front();
			q.pop();
			cost = (cost < gold[f] ? cost:gold[f]);
			if(!seen[f]){
				seen[f] = 1;
				for(int j = 0; j < pairs[f].size(); j++){
					q.push(pairs[f][j]);
				}
			}
		}
		res += cost;

	}
	cout << res << endl;


	
	// for(auto a: gold){
	// 	sum += a;
	// }
	// cout << sum << endl;


	
}