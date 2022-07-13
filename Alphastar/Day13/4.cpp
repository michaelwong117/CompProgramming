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

const int N = 21;
const int M = (1 << 20) + 1;

pi dp[2][M];
int H[N], W[N], S[N], n, h;

//dp[i][j] is the best height for the first i % 2 cows and using cows in mask M

//smarter dp is just dp[i][j] where j is state and i is number of cows, keep track of maximum safety

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n >> h;
	for(int i = 1; i <= n; i++){
		cin >> H[i] >> W[i] >> S[i];
	}
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < M; j++){
			dp[i][j] = {-1e9, -1e9};
		}
	}

	dp[0][0] = {0, 1e9};
	dp[0][1] = {H[1], S[1]};

	for(int i = 2; i <= n; i++){

		int cur = (i % 2 == 0) ? 1: 0;
		int prev = i % 2;

		for(int st = 0; st < M; st++){

			for(int cow = 1; cow <= i; cow++){

				if(st & (1 << cow)) continue;

				int mask = (st & (1 << cow));



				dp[cur][mask] = max(dp[cur][mask], 

					{dp[prev][st].f + H[cow], min(dp[prev][st].s - W[cow], S[cow])});

				dp[cur][st] = dp[prev][st];

 			}
		}
		for(int st = 0; st < M; st++){
			dp[prev][st] = {-1e9, -1e9};
		}
	}
	int safety = -1e9;
	for(int st = 0; st < M; st++){
		if(dp[(n % 2 == 0) ? 1 : 0][st].f >= h) safety = max(safety, dp[(n % 2 == 0) ? 1 : 0][st].s);
	}
	if(safety == -1e9) cout << "Mark is too tall" << endl;
	else cout << safety << endl;



}