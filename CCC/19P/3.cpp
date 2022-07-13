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

map<int, int> m;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if(m.find(x) == m.end()) m[x] = 1;
		else m[x]++;
	}

	int freqM = -1e9, freqm = -1e9;

	for(auto a: m){
		freqM = max(freqM, a.s);
	}
	int c = 0;
	for(auto a: m){
		if(a.s == freqM){
			c++;
		}
	}
	int mn = 1e9, mx = -1e9;
	if(c >= 2){
		for(auto a: m){
			if(a.s == freqM){
				mn = min(a.f, mn);
				mx = max(a.f, mx);
			}
		}
		cout << mx - mn << endl;
	}
	else{ // c must be 1
		vi posm;
		int opp = -1;
		for(auto a: m){
			if(a.s != freqM){
				freqm = max(freqm, a.s);
			}
			else{
				opp = a.f;
			}
		}
		if(opp == -1){
			cout << "BAD" << endl;
			return 0;
		}
		for(auto a: m){
			if(a.s == freqm){
				posm.pb(a.f);
			}
		}
		int best = -1e9;
		for(auto a: posm){
			best = max(best, abs(a-opp));	
		}
		cout << best << endl;
	}
}
