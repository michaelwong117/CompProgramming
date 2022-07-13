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

int N, M;
vector<vi> adj, revadj;
vi res = {4};
bool valid(vi &fir, int nx){
	for(auto a: fir) if(a == nx) return false;
	for(auto a: adj[nx]){
		return valid(fir, a);
	}
	return true;
}
int minelem(vi &v){
	int mn = 1e6;
	for(auto a: v){
		mn = min(mn, a);
	}
	return mn;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("milkorder.in"); ofstream fout("milkorder.out");
	fin >> N >> M;
	adj.resize(N+1);
	revadj.resize(N+1);
	for(int i = 0; i < M; i++){
		int o, front; fin >> o >> front;
		vi fir;
		fir.pb(front);
		for(int i = 1; i < o; i++){
			int nx; fin >> nx;
			if(valid(fir, nx)){
				for(auto a: fir){
					adj[a].pb(nx);
					for(auto b: revadj[nx]){
						adj[a].pb(b);
					}
				}
				for(auto a: fir) revadj[nx].pb(a);
			}
			else{
				//output lexographically smallest somehow?!
				return 0;
			}
			fir.pb(nx);
		}
		// debugging
		cout << "NEXT" << endl;
		for(int a = 1; a < adj.size(); a++){
			cout << a << "->" << endl;
			for(auto b: adj[a]){
				cout << b << " ";
			}
			cout << endl << endl;
		}
	}

	
}