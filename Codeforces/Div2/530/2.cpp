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
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

ll n;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n;
	ll t = sqrt(n);
	ll mn = 1e18;

	for(int i = 1; i <= t+1; i++){

	     if(n % i == 0){

	     	if(i != n/i) mn = min(mn, (ll) (i + n/i));
	     	else mn = min(mn, (ll) i + i);

	   }
	}
	for(ll i = max(t-100, (ll) 1); i < t+6; i++){
		for(ll j = i+1; j < t+100; j++){
			if((ll) i*j >= n){
				mn = min(mn, i+j);
				break;
			}
		}
	}
	// for(ll i = t; ){

	// 	if((ll) i*i >= n){
	// 		mn = min(mn, i+i);
	// 		break;
	// 	}
	// }
	
	out(mn);
}
