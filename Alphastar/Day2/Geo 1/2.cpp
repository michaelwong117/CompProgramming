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
const int N = 151;

int n, g, r; 

vpi circ(100);

int x[N], y[N], dp[N][N];
bool valid[N][N];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n >> g >> r;
	rep(i, n){
		cin >> x[i] >> y[i];
	}
	rep(i, g){
		cin >> circ[i].f >> circ[i].s;
	}
	//dp[i][j] is the maximum number of ropes possible given bounds
	//i...x and x... j where x is some number in between i and j
	for(int i = 0; i < n; i++){
		for(int j = i+2; j < n; j++){
			if(intersect(i, j)) valid[i][j] = 1;
		}
	}

	for(int l = 2; l <= n-1; l++){
		for(int i = 0; i+l < n; i++){
			int j = i+l;
			// cout << i << " " << j << endl;
			for(int x = j; x >= i; x--){

				//cout << i << " " << x << " " << j << endl;

				dp[i][j] = max(dp[i][j],dp[i][x]+dp[x][j]+valid[i][j]);
			}
		}
	}

	
	//consider it linear
	//go in ones around the circle
	//go in twos around the circle
	// eventually all i,j will be done
	//iterate over x inside



}