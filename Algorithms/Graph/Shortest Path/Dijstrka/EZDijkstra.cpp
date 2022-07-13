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
const int V = 1e5+1;

int t, v, k;

template<int SZ> struct Dijkstra {
    priority_queue<pl, vector<pl>, greater<pl>> q;
    ll dist[SZ];
    Dijkstra(int start, vector<vpi> & adj) {
        for(int i = 0; i < SZ; i++) dist[i] = 1e18;
        dist[start] = 0; q.push({0, start});
        while(!q.empty()){
            pl ft = q.top(); q.pop();
            if(dist[ft.s] < ft.f) continue; //never visit a minimum node again
            for(auto a: adj[ft.s]){
                if(dist[a.f] > ft.f + (ll) a.s){
                    dist[a.f] = ft.f + (ll) a.s;
                    q.push({dist[a.f], a.f});
                }
            }
        }
    }

};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("input.in","r",stdin); //freopen("input.out","w",stdout); 
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> v >> k;
        //cout << v << " " << k << endl;
        vector<vpi> adj (v+1); 
        for(int i = 0; i < k; i++){
            int u, v, w; cin >> u >> v >> w;
            adj[u].pb({v, w});
        }
        int a, b; cin >> a >> b;
        Dijkstra<V+1> SP(a, adj);
        if(SP.dist[b] == 1e18) cout << "NO" << endl;
        else cout << SP.dist[b] << endl;
    }
}