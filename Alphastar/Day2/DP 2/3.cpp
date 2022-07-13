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

int l, t; 

int shift(int base, int next){
	int res = ((base << 1) + next) & ((1 << t) - 1);
	return res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> l >> t;
	string s, pitch; cin >> s >> pitch;
	vector<bool> bit;
	if(t > l){
		out(0); return 0;
	}
	rep(i, s.size()){
		bit.pb(s[i] == '1');
	}
	//rep(i, bit.size()) cout << bit[i];
	int pitch10 = stoi(pitch,nullptr,2);
	//out(pitch10);

	//at pos i with mask j
	//dp[i][j].f is min number of lights, dp[i][j].s is min number of pitch
	vector<vpi> dp(l+1, vpi((1 << t)+1, {1e9,1e9}));

	//base case
	string base = "";
	int base10, baseT;
	rep(i, t){
		base += s[i];
	}
	base10 = stoi(base,nullptr,2);
	dp[0][base10] = {__builtin_popcount(base10), 0};
	dp[0][base10 ^ pitch10] = {__builtin_popcount(base10 ^ pitch10), 1};

	// string test = "101011";
	// rep(i, test.size()-4){
	// 	//cout << i << " " << test.substr(i, 4) << endl;
	// 	int test10 = stoi(test.substr(i, 4),nullptr,2);
	// //	cout << test.substr(i, 4) << endl;
	// 	int newtest = ((test10 << 1) + test[i+3]-'0') & ((1 << 4) - 1);
	// 	cout << (bitset<8>(newtest).to_string()) << endl;

	// }
	
	for(int i = 1; i <= l-t; i++){
		//iterate over all masks, only build from possibles, i.e., not 1e9
		//0 = 00000...
		//(1 << t) - 1 = 11111...
		//cout << bit[i+t] << endl;
		for(int mask = 0; mask <= (1 << t)-1; mask++){
			//shifting (see test)
			// 101011
			// 1010 -> 10100 -> 10101 -> 0101
			// 0101 - > 01010 -> 01011 - >  1011
			int newm = shift(mask, bit[i+t-1]);

			//applying a change
			int ch = newm ^ pitch10;
			//change result
			//KEY
			int diff = __builtin_popcount(ch) - __builtin_popcount(newm);
	
			// int newch = ((ch << 1) + bit[i+t]) & ((1 << t)-1);
			// int newm = ((mask << 1) + bit[i+t]) & ((1 << t)-1);

			dp[i][ch] = min(dp[i][ch], {dp[i-1][mask].f + diff + bit[i+t-1],
					dp[i-1][mask].s + 1});

			dp[i][newm] = min(dp[i][newm], {dp[i-1][mask].f + bit[i+t-1], 
					dp[i-1][mask].s});


		} 
	}
	pi res = {1e9, 1e9};
	for(int mask = 0; mask <= (1 << t)-1; mask++){
		res = min(res, dp[l-t][mask]);
	}
	out(res.s);
	// cout << res.f << " " << res.s << endl;






















}