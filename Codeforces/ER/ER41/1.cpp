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


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("filename.in"); ofstream fout("filename.out");
	int n, m; cin >> n >> m;
	map<int, int> col;
	for(int i = 1; i <= n; i++){
		col[i] = 0;
	}
	int d = 0;
	for(int i = 0; i < m; i++){
		int c; cin >> c;
		col[c]++;
		bool r = 1;
		for(auto a: col){
			// cout << a.f << " " << a.s << endl;
			if(a.s == 0) r = 0;
		}
		// cout << endl;
		if(r){
			d++;
			for(auto &a: col){
				a.s--;
			}
		}
	}
	cout << d << endl;
	
}