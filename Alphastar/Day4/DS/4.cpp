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
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	int n, k; cin >> n >> k;
	vector<string> v;
	rep(i, n){
		string s; cin >> s; v.pb(s);
		//cout << s << endl;
	}
	vector<string> start;

	for(int i = 0; i < v.size(); i++){
		string s = "";
		int sz = v[i].size(), end = min(sz, 5);
		for(int j = 0; j < end; j++){
			s += v[i][j];
		}
		start.pb(s);
	}

	vi dp()
	for(int i = 0; i < k; i++){
		for(int j = 0; j < start.size(); j++){
			for(int k = start[j].size(); k < v[j].size(); k++){
				dp[i][j]
			}
		}
	}


}