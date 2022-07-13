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



int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	

	int n; cin >> n;

	vi a(n+1), sums(n+1);

	rep(i, n){
		cin >> a[i+1];
		sums[i+1] += a[i+1];
		sums[i+1] += sums[i];
	}
	int total = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < i; j++){


			if((sums[i] - sums[j-1]) % 2 != 0) continue;

			vi dp (sums[i] - sums[j-1] + 1);

			dp[0] = 1;

			int goal = (sums[i] - sums[j-1]) / 2;

			for(int k = j; k <= i; k++){
				for(int w = goal-a[k]; w >= 0; w--){
					dp[w+a[k]] += dp[w];
				}
			}
			total += dp[goal];
		}
	}
	out(total);
}