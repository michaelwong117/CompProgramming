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

bool sortbysec(const pair<int,char> &a,
              const pair<int,char> &b){
	if(a.s == b.s) return a.f < b.f;
    return (a.s < b.s);
}

int n, k;
vector<pair<int, char>> v;
vector<pair<int, char>> res;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);
	cin >> n >> k;
	if(n == k){
		return 0;
	}
	for(int i = 0; i < n; i++){
		char c; cin >> c;
		v.pb({i, c});	
	}
	sort(all(v), sortbysec);
	for(int i = k; i < n; i++){
		res.pb({v[i].f, v[i].s});
	}
	if(res.size() == 0){
		return 0;
	}
	sort(all(res));
	//assert(res.size() == n-k);
	for(int i = 0; i < res.size(); i++){
		cout << res[i].s;
	}
	cout << endl;

}