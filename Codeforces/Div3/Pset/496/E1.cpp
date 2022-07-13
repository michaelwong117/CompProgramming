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
//think of how to combine greater-less for the median
//instead of thinking in pairs, you only care about the final result of greater-less, 
//not the individual greater and less
//there think about it in terms of combination
//also remember prefix sums

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	int n, m; cin >> n >> m; 
	vi v(n), sums(n), count(2*n+10);
	int midpt;
	rep(i, n){
		cin >> v[i];
		if(v[i] == m) midpt = i;
	}
	for(int i = 0; i < n; i++){
		if(v[i] > m) sums[i]++;
		if(v[i] < m) sums[i]--;
		if(i != 0) sums[i] += sums[i-1];
		if(i < midpt){
			if(sums[i] < 0){
				count[sums[i]*-1]++;
			}
			else{
				count[sums[i]+n]++;
			}
		}
	}
	ll res = 0;
	for(int i = midpt; i < n; i++){
		if(sums[i] == 0 || sums[i] == 1) res++;
		if(sums[i] < 0){
			res += count[sums[i]*-1];
		}
		else{
			res += count[sums[i]+n];
		}
		if(sums[i]-1 < 0) res += count[(sums[i]-1)*-1];
		else res += count[sums[i]-1+n];
	}
	cout << res << endl;



	
}