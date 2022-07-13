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

//return x^y mod p
ll lpower(ll x, ll y, ll p)
{
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
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	int l; cin >> l;
	deque<char> tot;
	int diff = 1;
	if(l % 72 == 0) diff = 0;
	rep(i, l/72+diff){
		string s; cin >> s; 
		rep(j, s.size()){
			tot.pb(s[j]);
		}
	}
	tot.push_front(tot.back());
	tot.pop_back();
	// for(int i = 0; i < tot.size(); i++){
	// 	cout << tot[i] << endl;
	// }

	int firstchar;
	ll hash = 0, mhash;
	for(int i = 0; i < tot.size(); i++){
		hash += ((tot[i] - 'a' + 1) * lpower(31, tot.size()-i-1, MOD)) % MOD;
	}
	// cout << hash << endl;
	// for(int i = 0; i < tot.size(); i++){
	// 	cout << tot[i];
	// }
	// cout << endl;
	// cout << hash << endl;
	mhash = hash; firstchar = l-1;
	for(int i = 0; i < l-2; i++){
		//get rid of last character
		hash -= (tot.back() - 'a' + 1);
		//shift remaining characters down
		hash = ((hash * lpower(31,MOD-2,MOD) + MOD) % MOD) % MOD;
		//add last character
		hash = (hash + (tot.back() * lpower(31, tot.size()-1, MOD) + MOD) % MOD) % MOD;
 		tot.push_front(tot.back());
		tot.pop_back();
		// for(int i = 0; i < tot.size(); i++){
		// 	cout << tot[i];
		// }
		// cout << endl;
		// cout << hash << endl;
		if(hash < mhash){
			mhash = hash;
			firstchar = l-i-2;

		}

	}
	out(firstchar);
	//tot.push_front(tot.back());
	//tot.pop_back();


	

}