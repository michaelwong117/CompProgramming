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
const int mx = 2*1e5+1;
int n, m;
vi v (mx);

ll greaterCount(int median){
	vi sums(n+1); 
	Tree<pi> T;
	ll res = 0;
	for(int i = 0; i < n; i++){
		if(v[i] >= median) sums[i+1]++;
		else sums[i+1]--;
		sums[i+1] += sums[i];
	}
	for(int i = 1; i <= n; i++){
		if(sums[i] >= 0) res++;
		if(!T.empty()) res += T.order_of_key({sums[i], 1e9});
		T.insert({sums[i], i-1e9});
	}
	// cout << endl;
	return res;

}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n >> m; 
	rep(i, n){
		cin >> v[i];
	}
	out(greaterCount(m));



	
}