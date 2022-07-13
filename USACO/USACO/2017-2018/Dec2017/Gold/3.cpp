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

const int N = 1e5+1;

ll n, m, f[N], S[N];

deque<int> d;
set<pi> cont;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("hayfeast.in","r",stdin); freopen("hayfeast.out","w",stdout);	
	//before you start coding, think it through
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> f[i] >> S[i];
	}
	int mnS = 1e9+10;
	ll curF = 0;
	for(int i = 1; i <= n; i++){
		d.pb(i); cont.insert({S[i], i});
		curF += f[i];
		// cout << curF << endl;
		// for(auto a: cont) cout << a.f << " " << a.s << endl;
		while(curF >= m){
			auto a = *cont.rbegin();
			mnS = min(mnS, a.f);
			// cout << a.f << " " << a.s << endl;
			int idx = d.front(); d.pop_front();
			curF -= f[idx];
			cont.erase({S[idx], idx});
		}
	}
	cout << mnS << endl;

}
