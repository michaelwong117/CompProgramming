/*
ID: michaelwong11
PROG: subset
LANG: C++14     
*/
//g++-7 subset.cpp -std=c++14
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
const int mx = 1e4;
int N, sum = 0;
ll dp[mx];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("subset.in","r",stdin); freopen("subset.out","w",stdout);	
	cin >> N;
	rep(i, N) sum += i+1;
	if(sum % 2 == 1){
		out(0); return 0;
	}
	sum /= 2;
	dp[0]=1;
	for(int i = 1; i <= N; i++){
		for(int w = sum-i; w >= 0; w--){
			dp[w+i] += dp[w];
		}
	}
	out(dp[sum]/2);
}