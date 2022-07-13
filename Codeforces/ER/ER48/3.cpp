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
const int mx = 3*1e5+1;
vl a(mx), b(mx);
ll n;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i= 0 ; i < n; i++){
		cin >> b[i];
	}
	//base case all left then all right
	ll base = 0;
	for(ll i = 0; i < n; i++){
		base += a[i] * i;
		base += b[i] * (2 * n - i - 1);
	}
	ll best = base, calc = base;
	//ll firstsum = 0;
	for(ll i = 0; i < n; i++){
		ll cur = calc, firstdiff;

		if(i % 2 == 0){
			firstdiff = b[i] * (2 * n - (2 * (i+1)));

			// firstsum += a[i] * (i+i);
			// firstsum += b[i] * (i+i+1);
		}
		else{

			firstdiff = a[i] * (2 * n - (2 * (i+1)));

			// firstsum += a[i] * (i+i+1);
			// firstsum += b[i] * (i+i);
		}
		//checked both firstdiff and firstsum
		cur -= firstdiff;
		// cur += firstsum;






	}




}