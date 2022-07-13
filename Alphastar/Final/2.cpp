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
const int N = 1001;

int v1[N][N], v2[N][N];


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	int n, ml, md; cin >> n >> ml >> md;

	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			v1[i][j] = -1e9; v2[i][j] = -1e9;
		}
	}
	for(int i = 0; i < ml; i++){
		int a, b, d; cin >> a >> b >> d;
		v1[a][b] = d;
	}
	for(int i = 0; i < ml; i++){
		int a, b, d; cin >> a >> b >> d;
		v2[a][b] = d;
	}
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			if(v1[i][j] == -1e9 || v2[i][j] == -1e9) continue;
			if(v1[i][j] < v2[i][j]){
				out(-1);
			}
		}
	}
	if(v1[1][n] != -1e9) out(v1[1][n]);
	else out(-2);
}