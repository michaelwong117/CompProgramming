//g++ filename.cpp -std=c++14 -DH
#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define endl '\n'
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define pq priority_queue

typedef long long ll;
typedef pair<int, string> pis;
typedef pair<int,int> pii;

const int N = 200 * 1000 + 13;

int n, m;
ll a[N], dist[N];
vector<pair<int, ll>> g[N];
 
 
void Dijkstra(){
    set<pair<ll, int>> q;
    for(int i = 0; i < n; i++){
        dist[i] = a[i];
        q.insert({dist[i], i});
    }
    while (!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());
       
        for (auto it : g[v]){
            int u = it.first;
            ll w = it.second;
           
            if (dist[u] > dist[v] + w){
                q.erase({dist[u], u});
                dist[u] = dist[v] + w;
                q.insert({dist[u], u});
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int f, t;
        ll w;
        cin >> f >> t >> w;
        --f, --t;
        w *= 2;
        g[f].push_back({t, w});
        g[t].push_back({f, w});
    }
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
   
    Dijkstra();
    for(int i = 0; i < n; i++){
        cout << dist[i] << endl;
    }
    return 0;
}