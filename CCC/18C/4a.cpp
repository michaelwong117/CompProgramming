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
#define pq priority_queue<int, vector<int>, greater<int>> //min pq
#define endl '\n'
#define out(x) cout << x << endl
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

int n;

const int N = 1e7+1;

ll dp[N];

unordered_map<int, ll> m;

ll solve(int n){
	if(n < N && dp[n] != -1){
		return dp[n];
	}
	else if(m.find(n) != m.end()){
		return m[n];
	}
	ll res = 0;
	for(int i = 1; i <= (int) sqrt(n); i++){
		int top = n / i, bot = ceil(n / (i+1));
		if(top-bot == 0) continue;
		res += solve(i) * (ll) (top - bot);
	}
	for(int i = floor(sqrt(n)); i >= 2; i--){
		if(n / i == floor(sqrt(n))) continue;
 		res += solve(n / i);
	}
	if(n < N) dp[n] = res;
	else m[n] = res;
	return res;
}



int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n;
	for(int i = 0; i < N; i++) dp[i] = -1;
	dp[1] = 1;	
	cout << solve(n) << endl;
	// for(int i = 1; i <= 10; i++){
	// 	cout << i << " " << dp[i] << endl;
	// }
}
