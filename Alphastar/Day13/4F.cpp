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

const int N = 20;
const int M = (1 << 20);

int dp[M], H[N], W[N], S[N], n, h;


//smarter dp is just dp[i][j] where j is state and i is number of cows, keep track of maximum safety

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n >> h;
	for(int i = 0; i < n; i++){
		cin >> H[i] >> W[i] >> S[i];
	}

	for(int j = 0; j < M; j++) dp[j] = -1e9;

	dp[0] = 1e9;
	
	for(int i = 0; i < n; i++){
		dp[(1 << i)] = S[i];
	}

	for(int st = 0; st < (1 << n); st++){

		for(int cow = 0; cow < n; cow++){

			if(st & (1 << cow)) continue;

			int mask = (st | (1 << cow));

			if(dp[st] - W[cow] >= 0) dp[mask] = max(dp[mask], min(dp[st] - W[cow], S[cow]));

		}

	}
	// for(int st = 0; st < (1 << n); st++){
	// 	cout << (bitset<8>(st).to_string()) << " " << dp[st] << endl;
	// }
		
	
	int safety = -1e9;

	for(int st = 0; st < M; st++){

		ll tot = 0;

		for(int cow = 0; cow < n; cow++){

			if(st & (1 << cow)) tot += (ll) H[cow];
		}

		if(dp[st] >= 0 && tot >= (ll) h) safety = max(safety, dp[st]);

	}
	if(safety == -1e9) cout << "Mark is too tall" << endl;
	else cout << safety << endl;



}