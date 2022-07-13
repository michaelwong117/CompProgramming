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
 
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

int n,a[200001];
Tree<pi> T;
ll ans = 0;
vpi query[200001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ifstream fin("filename.in"); ofstream fout("filename.out");
    fin >> n;
    for(int i = 1; i <= n; i++) fin >> a[i];
    for(int i = 1; i <= n; i++) if (i+1 <= min(n,a[i])) {
        query[i].pb({i,-1});
        query[min(a[i],n)].pb({i,1});
    }
  	 for(int i = 1; i <= n; i++) {
        T.insert({a[i],i});
        for(auto a: query[i]) ans += a.s*((int)T.size()-(int)T.order_of_key({a.f,-MOD}));
    }
    cout << ans;
}