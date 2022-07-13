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

int t, m, r, bit[2*mx], idx[mx];


void upd(int idx, int val){
	while(idx <= 2*mx){
		bit[idx] += val; idx += idx&-idx;
	}
}
int query(int idx){
	int sum = 0;
	while(idx >= 1){
		sum += bit[idx]; idx -= idx&-idx;
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("filename.in","r",stdin); //freopen("filename.out","w",stdout);	
	cin >> t;
	rep(i, t){
		cin >> m >> r;
		rep(i, m) idx[i+1] = m-i;
		rep(i, m) upd(idx[i+1], 1);
		for(int j = m+1; j <= m+r; j++){
			int x; cin >> x;
			cout << m-query(idx[x]) << " ";
			upd(idx[x], -1);
			upd(j, 1); idx[x] = j;
		}
		cout << endl;
		memset(bit,0,sizeof bit);
	}

}