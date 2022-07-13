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
#define pq priority_queue

typedef long long ll;
typedef pair<int, string> pis;
typedef pair<int,int> pii;

const int MOD = 1000000007;
const int MX = 100000;

ll n,m, a[MX], b[MX], ans, cur = 1;

ll po (ll b, ll p) {
    if(p == 0) return 1;
    else{
        if(p&1){
            return po(b*b%MOD, p/2) * b % MOD;
        }
        else{
            return po(b*b%MOD, p/2) * 1 % MOD;
        }
    }
}

ll inv (ll b){
    return po(b,MOD-2);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (b[i] == 0) {
                ll t = cur*(m-1) % MOD;
                t = t*inv(2*m) % MOD;
                ans += t;
                cur = cur*inv(m) % MOD;
            } else {
                ll t = cur*(m-b[i]) % MOD;
                t = t*inv(m) % MOD;
                ans += t;
                cur = cur*inv(m) % MOD;
            }
        } else {
            if (b[i] == 0) {
                ll t = cur*(a[i]-1) % MOD;
                t = t*inv(m) % MOD;
                ans += t;
                cur = cur*inv(m) % MOD;
            } else {
                if (a[i] == b[i]) {
                    continue;
                } else {
                    if (a[i] > b[i]) ans += cur;
                    break;
                }
            }
        }
    }
    
    cout << (ans%MOD) << endl;
}