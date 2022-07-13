#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

const int N = 1e3+1;

int n, m, q, l, r, cnt, prefix[N][N];


string s, t;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
//	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n >> m >> q;
	cin >> s >> t;

	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(j - m >= 0 && j - m >= i-1){
				// cout << s.substr(j-m, m) << endl;
				prefix[i][j] = (s.substr(j-m, m) == t);
			}
			prefix[i][j] += prefix[i][j-1];
			//cout << i << " " << j << " val " << prefix[i][j] << endl;
		}
		// cout << endl;
	}
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		cout << prefix[l][r] << endl;
	}


}