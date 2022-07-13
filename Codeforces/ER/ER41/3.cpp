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
const int maxN = 101;
int a[maxN][maxN], b[maxN][maxN];
int c[4][maxN][maxN];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("filename.in"); ofstream fout("filename.out");
	int n; cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if((i+j)%2 == 0)
				a[i][j] = 1;
			else
				b[i][j] = 1;
		}
	}
	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < n; j++){
	// 		if(j % 2){
	// 			a[i][j] = 1;
	// 		} 
	// 		else{
	// 			b[i][j] = 1;
	// 		}
	// 	}
	// 	swap(a,b);
	// }
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				char d;
				cin >> d;
				c[i][j][k] = d - '0';
			}
		}
	}
	vpi v;
	for(auto d: c){
		int ac = 0, bc = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(d[i][j] != a[i][j]) ac++;
				if(d[i][j] != b[i][j]) bc++;
			}
		}
		v.pb({ac, bc});
	}
	int sol = 1e9;
	for(int i2 = 0; i2 < v.size(); i2++){
		for(int i3 = i2+1; i3 < v.size(); i3++){
			int res = 0;
			unordered_set<int> vc = {0,1,2,3};
			vc.erase(i2); vc.erase(i3);
			res += v[i2].f + v[i3].f;
			for(auto a: vc) res += v[a].s;
			sol = min(sol, res);
		}
	}
	cout << sol << endl;

	
}