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

const int N = 1e5+1;

ll E[N], sums[N], n, k, dp[N], val[N];


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
 	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> E[i];
		sums[i] += E[i];
		sums[i+1] += sums[i];
	}
	priority_queue<pl> q;
	dp[0] = 0;
	for(int i = 1; i <= k; i++){
		q.push({0, i});
	}
	for(int i = 1; i <= n; i++){
		q.push({dp[i-1] - sums[i], i+k});
		
		while(i > q.top().s) q.pop();
		//cout << q.top().f << " " << q.top().s-k << endl;
		dp[i] = sums[i] + q.top().f;
	}
	//for(int i = 1; i <= n; i++) cout << dp[i] << endl;
	cout << dp[n] << endl;


}