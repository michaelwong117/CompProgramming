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
#define pq priority_queue<int, vector<int>, greater<int>> //min pq
#define endl '\n'
#define out(x) cout << x << endl
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef long double ld;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

ll n, k, m;

vi v;

ll s = 0;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n >> k >> m;
	for(int i = 0; i < n; i++){
		int x; cin >> x; v.pb(x); s += (ll) x;
	}
	sort(all(v));
	ll prevS = s, prevM = m, prevD = n;
	ld mx = (ld) (min(prevM, n*k) + prevS) / (ld) prevD;
	int it;
	if(m < n){
		it = m;
	}
	else if(m == n){
		it = m-1;
	}
	else if(n < m){
		it = n-1;
	}
	for(int i = 1; i <= it; i++){
		prevM--; 
		prevS -= (ll) v[i-1];
		ll prevN = min(prevM, (n-i)*k) + prevS;
		prevD--;
		mx = max(mx, (ld) prevN / (ld) prevD);
	}
	cout << fixed << setprecision(7) << mx << endl;
}
