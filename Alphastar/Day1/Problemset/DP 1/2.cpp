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

int dx[]={ 0, 0,+1,-1};
int dy[]={+1,-1, 0, 0};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	int n, m, t; cin >> n >> m >> t;
	vector<vector<bool>> grid(n, vector<bool> (m));
	rep(i, n){
		string s;
		cin >> s;
		rep(j, s.size()) if(s[j] == '*') grid[i][j] = 1;
	}
	int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
	//x row, y col, t cur seconds
	//dp[x][y][t] is the number of ways to get from r1, c1 to 
	vector<vector<vl>> dp (n, vector<vl> (m, vl (t+1, -1)));
	dp[r1-1][c1-1][0] = 1;
	for(int time = 1; time <= t; time++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				for(int k = 0; k < 4; k++){
					int x = i+dx[k], y = j+dy[k];
					if(x >= 0 && x < n && y >= 0 && y < m){
						if(grid[x][y]) continue;
						if(dp[i][j][time-1] != -1){
							if(dp[x][y][time] == -1) dp[x][y][time] = 0;
							dp[x][y][time] += dp[i][j][time-1];
						}
					}
					
				}
				
			}
		}
	}
	// rep(i, n){
	// 	rep(j, m){
	// 		cout << dp[i][j][2] << " ";
	// 	}
	// 	cout << endl;
	// }
	if(dp[r2-1][c2-1][t] == -1) out(0);
	else cout << dp[r2-1][c2-1][t] << endl;


}