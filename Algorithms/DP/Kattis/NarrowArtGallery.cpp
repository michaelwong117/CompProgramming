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
const int mx = 201;

int N, K, col[2][mx], dp[2][mx][mx][2], fir = 1;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	while(1){
		int sum = 0;
		if(!fir){
			for(int i = 0; i < n; i++){
				cin >> col[0][i] >> col[1][i]; sum += col[0][i]+col[1][i];
			}
			for(int i = 0; i < 2; i++){
				for(int j = 0; j < N; j++){
					for(int k = 0; k < K; k++){
						dp[i+1][j+1][k+1][1] = min(dp[i+1][j+1][k+1][1], 
								min(dp[i][j+1][k][0],dp[i+1][j][k][0]))+val[i][j];
					}
				}
			}
			dp[1][0][1][0] = 0;
			dp[1][0][0][0] = 0;
			dp[0][1][1][1] = 0;


		}

		fir = 0;
		cin >> N >> K; 
		if(N == 0 && K == 0) break; 
	}
	dp[i][j][k][1]=min(dp[i-1][j][k-1][0],dp[i][j-1][k-1][0],dp[i][j][k][1])+val[i][j]
	for(int z = 0; z < 2; z++)
	dp[i][j][k][0] =  min( dp[i-1][j][k][z], dp[i][j-1][k][z], dp[i][j][k][0] )
}