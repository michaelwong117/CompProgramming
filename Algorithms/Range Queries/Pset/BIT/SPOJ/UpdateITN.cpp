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
#define out(x) cout << x << endl
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
const int mx = 1e4+1;
int t, a[mx];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("filename.in","r",stdin); //freopen("filename.out","w",stdout);	
	cin >> t;
	rep(i, t){
		int n, u; cin >> n >> u;
		rep(i2, u){
			int l, r, val; cin >> l >> r >> val;
			a[l] += val; a[r+1] -= val;
			// cout << l << " " << a[l] << " " << a[r+1] << " " << r+1 << endl;
		}
		for(int j = 1; j < n; j++) a[j] = a[j]+a[j-1];
		int q; cin >> q;
		rep(i2, q){
			int idx; cin >> idx;
			out(a[idx]);
		}
		memset(a,0,sizeof a);
	}
}