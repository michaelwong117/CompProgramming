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
const int mx =2001;
string s; vi cost(26);

vector<vi> dp(mx, vi(mx, -1)); 

int fix(int i, int j){
	if(dp[i][j] != -1) return dp[i][j];
	int res = 0;
	if(i >= j) return res;
	if(s[i] == s[j]) res += fix(i+1, j-1);
	else res += min(fix(i+1,j)+cost[s[i]-'a'], fix(i,j-1)+cost[s[j]-'a']);
	dp[i][j] = res;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	int n, m; cin >> n >> m;
	cin >> s;
	rep(i, n){
		char a; cin >> a;
		int x, y; cin >> x >> y;
		cost[a-'a'] = min(x,y);
	}
	out(fix(0, m-1));




}
