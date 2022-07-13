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
typedef long long unsigned ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

int L;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> L;
	int cur = L, edges = 0, v = 20, tens = floor(log10(L));
	vpi powers;
	for(int i = 2; i <= 12; i++){
		ll now = i;
		for(int j = 1; j < 20; j++){
			if(now > 1000000) continue;
			powers.pb({now, j});
			// cout << now << " ";
			now *= i;
		}
		// cout << endl;
	}
	set<int> s;
	for(int i = 0; i < powers.size(); i++){
		for(int j = 0; j < powers.size(); j++){
			for(int k = 0; k < powers.size(); k++){
					if(s.find(powers[i].f+powers[j].f+powers[k].f+powers[a].f) == s.end()){
						s.insert(powers[i].f+powers[j].f+powers[k].f+powers[a].f);
					}
				}
			}
		}
	}
	for(auto a: s){
		cout << a << " ";
	}
	cout << endl;

}
