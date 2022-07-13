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
#define out(x) cout << x << endl;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
const int mx = 1e7+1;
int n, bit[mx];

void upd(int k, int x){
	while(k <= mx){
		bit[k] += x; k += k&-k;
	}
}
//sum 1 to k
//query(r) - query(l-1) is sum from l to r
ll query(int k){
	ll sum = 0;
	while(k >= 1){
		sum += bit[k];
		k -= k&-k;
	}
	return sum;
}

ll query(int l, int r) { return query(r)-query(l-1); } // range query [l,r]

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("filename.in","r",stdin); //freopen("filename.out","w",stdout);	
	cin >> n;
	for(int i = 0; i < n; i++){
		int c; cin >> c;
		ll sum = 0;
		rep(i2,c){
			int a; cin >> a;
			sum += query(a, mx);
			upd(a, 1);
		}
		out(sum);
		memset(bit,0,sizeof bit);
	}
}