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

int n, b, f[100001], s[100001], d[100001];

vpi v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("snowboots.in","r",stdin); freopen("snowboots.out","w",stdout);	
	//before you start coding, think it through

	cin >> n >> b;
	for(int i = 0; i < n; i++){
		cin >> f[i];
	}
	for(int i = 0; i < b; i++){
		cin >> s[i] >> d[i];
		v.pb({s[i], i});
	}
	sort(all(v));
	for(int i = 0; i < v.size(); i++){

		//remove all fs with f[i] > v[i];
	}

}
