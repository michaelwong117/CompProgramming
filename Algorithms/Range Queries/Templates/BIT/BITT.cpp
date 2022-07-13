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
#define pq priority_queue<int, vector<int>, greater<int>>
#define heap priority_queue<int>
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<ll,ll> pl;
typedef vector<array<int,3>> multiv;

const int maxN = 1e6+1;
int N, Q;
template<class T, int SZ> struct BIT {
    T bit[SZ+1];
    BIT() { memset(bit,0,sizeof bit); }
    void upd(int x, T val) { // add value to index x
        while(x <= SZ){ // upd BIT
            bit[x] += val; x += x&-x;
        }
    }
    T query(int x) { //query for sum [1,x]
        T sum = 0;
        while(x >= 1){
            sum += bit[x];
            x -= x&-x;
        }
        return sum;
    }
    T query(int l, int r) { return query(r)-query(l-1); } // range query [l,r]
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    BIT<ll, maxN> t;
    for(int i = 1; i <= N; i++){
        ll elem;
        cin >> elem;
        //filling in initial BIT
        t.upd(i, elem);
    }
    cin >> Q;
    for(int j = 0; j < Q; j++){
        char c;
        cin >> c;
        if(c == 'u'){
            int i;
            ll x;
            cin >> i >> x;
            t.upd(i, x);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << t.query(r) - t.query(l-1) << endl;
        }
    }
    
}