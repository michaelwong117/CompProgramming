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
const int mx = 1e5;
//dp[i][k][s] resembles the max score at pos i, # of changes k, and cur state s
int N, K, a[mx], dp[mx][21][3];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("hps.in","r",stdin); freopen("hps.out","w",stdout);
	cin >> N >> K;
	rep(i, N){
		char c; cin >> c;
		if(c == 'P') a[i] = 1;
		if(c == 'S') a[i] = 2;
	}
	for(int s = 0; s < 3; s++){
		dp[0][0][s] = (s == a[0]);
	}

	if(K >= 1){
		dp[0][1][0] = (a[0] == 0);
		dp[0][1][1] = (a[0] == 1);
		dp[0][1][2] = (a[0] == 2);
	}
	for(int i = 1; i < N; i++){
		for(int k = 0; k <= K; k++){ 
			for(int s = 0; s < 3; s++){
				dp[i][k][s] = -1e9; 
			}
		}
	}
	for(int i = 1; i < N; i++){
		for(int k = 0; k <= K; k++){
			for(int s = 0; s < 3; s++){
				int c = (s==a[i]);
				dp[i][k][s] = max(dp[i][k][s], dp[i-1][k][s]+c);
				for(int ch = 0; ch < 3; ch++){
					if(ch == s || k < 1) continue;
					dp[i][k][s] = max(dp[i][k][s], dp[i-1][k-1][ch]+(ch==a[i]));
				}
			}
		}
	}
	int mx = -1e9;
	for(int k = 0; k <= K; k++){
		for(int s = 0; s < 3; s++){
			mx = max(mx, dp[N-1][k][s]);
		}	
	}
	cout << mx << endl;


}