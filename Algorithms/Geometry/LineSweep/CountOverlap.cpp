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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("input.in","r",stdin); //freopen("input.out","w",stdout);
    int n; cin >> n;
    //start of pair, end of pair
    vi v (2*n), st (n,-1), end (n,-1);
    int res = 0;
    rep(i, 2*n){
        cin >> v[i]; v[i]--;
        if(st[v[i]] == -1){
            st[v[i]] = i;
        }
        else{
            end[v[i]] = i;
            // count the things in between a pair that have started 
            // but haven't yet ended
            for(int j = st[v[i]]+1; j < end[v[i]]; j++){
                if(st[v[j]] != -1 && end[v[j]] == -1) res++;
            }
        }
    }
    out(res);
   
}