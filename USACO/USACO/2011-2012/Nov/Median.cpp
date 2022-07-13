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
const int mx = 1e5+1;
int N, X, a[2*mx], bit[2*mx], cur = 0;

int upd(int k, int val){
	k += mx;
	while(k <= 2*mx){
		bit[k] += val; k+=k&-k;
	}
}

int query(int k){
	int sum = 0; k += mx;
	while(k >= 1){
		sum += bit[k]; k-=k&-k;
	}
	return sum;
}
int query(int l, int r) { return query(r)-query(l-1); }


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("median.in","r",stdin); //freopen("median.out","w",stdout);	
	cin >> N >> X; 
	for(int i = 1; i <= N; i++){
		cin >> a[i];
		a[i] = (a[i] >= X) ? 1:-1;
	}
	ll res = 0; 
	upd(0,1);
	for(int i = 1; i <= N; i++){
		cur += a[i];
		int x = query(cur); res += x;
		upd(cur, 1);
	}
	cout << res << endl;


}