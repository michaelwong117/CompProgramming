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

int n, L[2000001], dp[4001];

map<int, int> w;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> L[i];
		if(w.find(L[i]) == w.end()) w[L[i]] = 1;
		else w[L[i]]++;
	}
	for(int tot = 2; tot <= 4000; tot++){
		for(auto a: w){
			if(w.find(tot-a.f) != w.end()){
				dp[tot] += min(w[tot-a.f], w[a.f]);
			}
		}
	}
	for(int tot = 2; tot <= 4000; tot++) dp[tot] /= 2;
	int mx = -1e9;
	for(int tot = 2; tot <= 4000; tot++){
		mx = max(mx, dp[tot]);
	}
	int c = 0;
	for(int tot = 2; tot <= 4000; tot++){
		if(dp[tot] == mx) c++;
	}
	cout << mx << " " << c << endl; 
	

}
