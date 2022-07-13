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
const int mx = 1e5+1;
int n, q, a[mx], T[2*mx];

int op(int x, int y) return min(x,y);
//used for 1-idx
void build(){
	for(int i = n; i < 2*n; i++) T[i] = a[i-n];
	for(int i = n-1; i >= 1; i--){
		T[i] = op(T[2*i],T[2*i+1]);
	
	}
}
//used for 1-idx

int query(int a, int b){
	a += n, b += n;
	int mn = 1e9;
	while(a <= b){
		if(a%2==1) mn = op(mn, T[a++]);
		if(b%2==0) mn = op(mn, T[b--]);
		a>>=1; b>>=1;
	}
	return mn;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("filename.in","r",stdin); //freopen("filename.out","w",stdout);	
	cin >> n;
	rep(i, n) cin >> a[i];
	build();
	cin >> q;
	rep(i, q){
		int l, r; cin >> l >> r;
		out(query(l,r));
	}

}