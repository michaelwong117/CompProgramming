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
const int mx = 1e3;

int n, l[mx], r[mx]. dp[mx][mx];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("nocross.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n;
	rep(i, n) cin >> l[i];
	rep(i, n) cin >> r[i];
	dp[0][0] = (abs(l[0]-t[0])<=4);
	for(int i = 1; i < n; i++){
		dp[0][i] = max(dp[0][i-1], (abs(l[i]-t[i])<=4)); 
		dp[i][0] = max(dp[i-1][0], (abs(l[i]-t[i])<=4)); 
	}
	for(int i = 1; i < n; i++){
		for(int j = 1; j < n; j++){
			dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]+(abs(l[i]-t[i])<=4));
		}
	}
}