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
const int N = 702;

int a[N], n, r;
bool dp[N][N][2], pos[N][N];

int GCD(int a, int b)
{
   if(b==0) return a;

   return GCD(b,a%b);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int l = 1; l <= n; l++){
		dp[l][l][0] = 1;
		dp[l][l][1] = 1;
 	}
 	for(int l = 1; l <= n; l++){
 		for(int r = 1; r <= n; r++){
 			if(GCD(a[l], a[r]) > 1) pos[l][r] = 1;
 		}
 	}
 	for(int l = 1; l <= n; l++){
 		for(int r = l; r <= n; r++){
v 			dp[l-1][r][0] |= (dp[l][r][0] && pos[l-1][l]);
 			dp[l][r+1][1] |= (dp[l][r][1] && pos[r][r+1]);

 		}
 	}
 	for(int root = 1; root <= n; root++){
 		if(dp[1][root][1] && dp[root][n][0]){
 			cout << "YES" << endl;
 			return 0;
 		}
 	}
 	cout << "NO" << endl;
}
