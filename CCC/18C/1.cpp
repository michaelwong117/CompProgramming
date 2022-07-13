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

int n;

vi v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x; v.pb(x);
	}
	sort(all(v));
	double mn = 2*1e9+1;
	for(int i = 1; i < n-1; i++){
		double szL = (abs((double)v[i] - v[i-1])) / 2;
		double szR = (abs((double)v[i+1] - v[i])) / 2;
		double L = (double) v[i-1] + szL, R = (double) v[i+1] - szR;
		// cout << i << " " << L << " " << R << endl;
		mn = min(mn, abs(R - L));
		// cout << fixed << showpoint << setprecision(1) << abs(R - L) << endl;
		// cout << endl;
	}
	cout << fixed << showpoint << setprecision(1) << mn << endl;
}
