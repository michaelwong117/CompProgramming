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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);
	int l, t;
	cin >> l >> t;	
	string s, pitch; cin >> s >> pitch;
	if(t > l){
		out(0); return 0;
	}

	//dp[i][j].f is the number of lights
	//dp[i][j].s is the minimum number of pitchforks
	//at pos i with mask j

	vector<vpi> dp(l+1, vpi((1<<t)+1, {1e9, 1e9}));
	vector<int> v1;
	for(int i = 0; i < l; i++) v1.pb(s[i] == '1' ? 1 : 0);
	
	int m = 0;
	for(int i = 0; i < t - 1; i++) m += (v1[i] << i);
	
	reverse(all(pitch));
	int fork = stoi(pitch, nullptr, 2);
	for(int i = 0; i < (1 << (t - 1)); i++)
	{
		int k = i + (v1[l - 1] << (t - 1));
		int ch = k ^ fork;
		int pc1 = __builtin_popcount(k);
		int pc2 = __builtin_popcount(ch);
		dp[l - t][i] = min(make_pair(pc1, 0), make_pair(pc2, 1));
	}
	for(int i = l - t - 1; i >= 0; i--){
		for(int j = 0; j < (1 << (t - 1)); j++){
			int k = j + (v1[i + t - 1] << (t - 1));
			int ch = k ^ fork;
			//int newmask = ((j<<1) | v1[i + t]) & ((1<<t)-1);
			//int newch = ((ch<<1) | v1[i + t]) & ((1<<t)-1);
			int newmask = k / 2;
			int newch = ch / 2;
			dp[i][j] = min(make_pair(dp[i + 1][newmask].f + k % 2,
				dp[i + 1][newmask].s),
				make_pair(dp[i + 1][newch].f + ch % 2,
				dp[i + 1][newch].s + 1));

		}
	}
	out(dp[0][m].s);
}