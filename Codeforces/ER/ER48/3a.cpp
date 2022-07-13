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
vl a(mx), b(mx), preA(mx), preB(mx);
ll n;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0 ; i < n; i++){
		cin >> b[i];
	}
	for(int i = 1; i <= n; i++){
		preA[i] += a[i] + preA[i-1];
		preB[i] += b[i] + preB[i-1];
	}

	//base case all left then all right
	ll base = 0;
	for(ll i = 0; i < n; i++){
		base += a[i] * i;
		base += b[i] * (2 * n - i - 1);
	}
	ll up = 0, down = 0;
	for(ll i = 1; i < n; i++){
		up += a[i-1] * (2 * n - (i + i));
		down += b[i-1] * (2 * n - (i + i) - 2);
	}
	ll best = base, calc = base;

	//ll lastup = a[0] * (2 * n - 2), lastdown = b[0] * (2 * n - 4);


	for(ll i = 0; i < n; i++){
	 	ll cur = calc, firstdiff;

		if(i != 0){
			if(i % 2 == 0){
				up -= lastup;
				down += lastdown;
				up += -2 * (preA[n] - preA[]);
				down += 2 * ();
			}
			else{
				up += 2 * ();
				down += 2* ();
				up += lastup;
				down -= lastdown;
			}
		}
		if(i % 2 == 0){
			cur -= up;
			cur += down;
			firstdiff = b[i] * (2 * n - (2 * (i+1)));
		}
		else{
			cur += up;
			cur -= down;
			firstdiff = a[i] * (2 * n - (2 * (i+1)));
		}
		cur -= firstdiff;


	}




}