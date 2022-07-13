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

int N, M, K;

vi word[6000], C, P;
ll dp[6000];
map<char, int> holder;
map<int, int> sy;
 


ll lpower(ll x, ll y, ll p){
    ll res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1){

            res = (res*x) % p;
            y--;
        }
 
        // y must be even now
        y = y/2; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("poetry.in","r",stdin); freopen("poetry.out","w",stdout);	
	//before you start coding, think it through
	// cout << dp[0] << " " << dp[5999] << endl; 
	cin >> N >> M >> K;
	for(int i = 0; i < N; i++){
		int x, y; cin >> x >> y;
		sy[x]++;
		word[y].pb(x);
	}
	for(int i = 0; i < M; i++){
		char c; cin >> c;
		holder[c]++;
	}
	dp[0] = 1;

	int pt = 0; //initialize some pointer

	while(pt <= K) {
	    for(auto a: sy) {
	        if (a.f > pt) break;
	        dp[pt] += (dp[pt-a.f] * a.s % MOD) % MOD;
	        dp[pt] %= MOD;
	    } 
	    pt++;
	}
	for(int i = 1; i <= N; i++){
		ll cur = 0;
		if(word[i].empty()) continue;
		for(auto a: word[i]){
			cur = (cur + dp[K-a] % MOD) % MOD;
		}
		C.pb(cur);
	}
	ll fin = 1;
	for(auto a: holder){
		ll cur = 0;
		for(auto b: C){
			cur = (cur + lpower(b, a.s, MOD) % MOD) % MOD;
			//cout << cur << " " << a.s << endl;
		}
		fin = (fin * cur % MOD) % MOD;
		fin %= MOD;
	}
	cout << fin << endl;
	


}
