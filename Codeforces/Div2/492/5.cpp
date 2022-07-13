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

int n;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n;
	multiv v (n);
	vi moves (n);
	rep(i, n){
		cin >> v[i][0] >> v[i][1];
		v[i][2] = i;
	};
	while(1){
		pl p = {0,0};
		for(int i = 0; i < v.size(); i++){
			ll x1 = p.f + v[i][0], y1 = p.s + v[i][1];
			ll x2 = p.f - v[i][0], y2 = p.s - v[i][1];
			if(x1*x1 + y1*y1 < x2*x2 + y2*y2){
				p.f = x1, p.s = y1;
				moves[v[i][2]] = 1;
			}
			else{
				p.f = x2, p.s = y2;
				moves[v[i][2]] = -1;
			}
		}
		if(p.f*p.f+p.s*p.s <= 2250000000000ll){
			rep(j, moves.size()){
				cout << moves[j] << " ";
			}
			cout << endl;
			return 0;
		}
		random_shuffle(all(v));
	}

}