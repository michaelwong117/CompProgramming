/*
ID: michaelwong11
PROG: nocows
LANG: C++11   
*/
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
typedef paeir<ll,ll> pl; typedef vector<array<int,3>> multiv;

int n, k, dp[201][101];

int solve(int nodes, int depth)
{
	if(nodes > n || depth > k || nodes < 0 || depth < 0) return 0;
	cout << nodes << " " << depth << endl;
	if(dp[nodes][depth] != -1) return dp[nodes][depth];

	int res = 0;
	//can't have too many nodes than pos for a height or 
	//less than the min # of nodes
	if(nodes <= pow(2, depth) - 1 && nodes > 1 + (depth - 1) * 2) 
	{
		res += solve(nodes - 2, depth);
	}
	res += solve(nodes - 2, depth - 1);

	dp[nodes][depth] = res;

	return dp[nodes][depth];



}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("nocows.in","r",stdin); //freopen("nocows.out","w",stdout);	
	//before you start coding, think it through
	cin >> n >> k;

	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= k; j++)
		{
			dp[i][j] = -1;
		}
	}

	dp[1][1] = 1;
	solve(n, k); 

	cout << dp[n][k] << endl;
	// dp[i][h] = dp[i+2][h+1]
	// if(i < pow(2, k) - 1) dp[i][h] = dp[i+2][h];
	

	//(1) (n + 1) / 2 ... pow(2, k) - 1 nodes (1)

}