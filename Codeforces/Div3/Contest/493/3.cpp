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
vl v(mx);
ll res = 0;


void f(int n){
	int i = 0, j = n-1;
	ll sum1 = 0, sum2 = 0;
	while(i < j){
		sum2 += v[j]; j--;
		while(sum2 > sum1 && i < j){
			sum1 += v[i]; i++;
		}
		if(sum2 == sum1) res = max(res, sum1);
		if(i == j){
			if(sum2 > sum1) sum1 += v[i];
			else sum2 += v[i];
			if(sum2 == sum1) res = max(res, sum1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);
	int n; cin >> n; 
	rep(i, n) cin >> v[i];
	f(n);
	reverse(all(v));
	f(n);	
	out(res);







}