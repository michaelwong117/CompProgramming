#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define mxpq priority_queue<int>
#define endl '\n'
#define out(x) cout << x << endl
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	int n, b; cin >> n >> b; 
	vi v(n), even(n+1), odd(n+1);
	pq q;
	rep(i, n) cin >> v[i];
	for(int i = 0; i < n; i++){
		if(v[i] % 2 == 0) even[i]++;
		else odd[i]++;
		even[i+1] = even[i]; odd[i+1] = odd[i];
	}
	for(int i = 1; i < n-1; i += 2){
		if(even[i] == odd[i] && even[n-1]-even[i] == odd[n-1]-odd[i]){
			q.push(abs(v[i+1]-v[i]));
		}
	}
	int c = 0;
	while(!q.empty() && b-q.top() >= 0){
		b-= q.top(); c++; q.pop();

	}
	out(c);


}