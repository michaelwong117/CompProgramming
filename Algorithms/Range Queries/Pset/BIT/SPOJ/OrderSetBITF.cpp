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
#define out(x) cout << x << endl
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

const int mx = 2*1e6+1;

char C[mx]; 
int in[mx], tmp[mx], bit[mx], N, x = 1, I = 1;
pi A[mx];

int bsearch(ll v){
    int lo=1, hi=I;
    while(lo<=hi){
        int m=(lo+hi)>>1;
        if(A[m].f>=v) hi=m-1;
        else lo=m+1;
    }
    return lo;
}
void upd(int i, int v){
    for(; i<=mx; i+=(i&-i))bit[i]+=v;
}
int query(int i){
    int ans=0;
    for(; i>0; i-=(i&-i)) ans+=bit[i];
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("filename.in","r",stdin);
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> C[i] >> in[i];
        if(C[i]=='I') tmp[x++]=in[i];
    }
    sort(tmp+1, tmp+x+1);
    for(int i=1; i<=x; i++){
        if(tmp[i-1]!=tmp[i]) A[I++].f=tmp[i];
    }
    for(int i=1; i<=N; i++){
        if(C[i]=='I'){
            int y=bsearch(in[i]); A[y].s++;
            if (A[y].s==1) upd(y, 1);
        }
        else if(C[i]=='D'){
            int y=bsearch(in[i]);
            if(A[y].s>0 && A[y].f==in[i]){upd(y, -1); A[y].s=0;}
        }
        else if(C[i]=='C'){
            int y=bsearch(in[i]), ans=query(y-1);
            cout << ans << endl;
        }
        else if(C[i]=='K'){
            int s=1, e=I;
            while(s<=e){
                int m=(s+e)>>1;
                if(query(m)>=in[i])e=m-1;
                else s=m+1;
            }
            if(s>I) cout << "invalid" << endl;
            else cout << A[s].f << endl;
        }
    }
    return 0;
}