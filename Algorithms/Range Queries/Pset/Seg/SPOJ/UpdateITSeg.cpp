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
int t, n, u, a[mx], T[2*mx];
//used for 1-idx, do l+1, r+1 for 0-idx
void upd(int l, int r, int val){
	l += n; r += n+1;
	T[l] += val; T[r] -= val;
	for(l*=2; l >= 1; l*=2){
		T[l]=T[2*l]+T[2*l+1];
	}
	for(r*=2; r >= 1; r*=2){
		T[r]=T[2*r]+T[2*r+1];
	}
}
//used for 1-idx, do q+1 for 0-idx
int query(int a, int b) {
    a += n; b += n;
    int s = 0;
    while (a <= b) {
       if (a%2 == 1) s += T[a++];
       if (b%2 == 0) s += T[b--];
       a /= 2; b /= 2;
    }
    return s; 
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("filename.in","r",stdin); //freopen("filename.out","w",stdout);	
	cin >> t;
	rep(i, t){
		cin >> n >> u;
		rep(i2, u){
			int l, r, val; cin >> l >> r >> val;
			upd(l+1,r+1,val);
		}
		int q; cin >> q;
		rep(i2, q){
			int idx; cin >> idx;
			out(query(1,idx+1));
		}
		memset(a,0,sizeof a); memset(T,0,sizeof T);
	}
}