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
#define MOD 1000000007LL
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
	string s, t; cin >> s >> t;
	string ans = "";

	vl H;

	ll tval = 0;

	//a * 31^t.size()-1, b * 31^t.size()-2

	// for(int i = t.size()-1; i >= 0; i--){
	// 	tval = (tval + ((t[i]-'a'+1)*lpower(31, t.size()-i-1, MOD)) % MOD) % MOD;
	// 	cout << t[i]-'a'+1 << " " << lpower(31, t.size()-i-1,MOD) << endl;
	// }

	//same as above

	for(int i = 0; i <= t.size()-1; i++){
		tval = (tval + ((t[i]-'a'+1)*lpower(31, t.size()-i-1, MOD)) % MOD) % MOD;
		// cout << t[i]-'a'+1 << " " << lpower(31, t.size()-i-1,MOD) << endl;

	}
	// cout << tval << endl;

	H.pb(0);
	for(int i = 0; i < s.size(); i++){
		ans += s[i];
		H.pb((((31*H.back()) % MOD)+(s[i]-'a'+1)) % MOD);
		if(H.size() <= t.size()) continue;
		// cout << H.back() << " " << H[H.size()-t.size()-1] << " ";
		// cout << ((H.back()) - ((H[H.size()-t.size()-1]) * lpower(31,t.size(),MOD) % MOD) + MOD) % MOD;
		// cout << " " << tval << endl;

		//let t.size() = 3, use example "moo"
		//H[0] = 0
		//H[1] = a
		//H[2] = a * 31 + b
		//H[3] = a * 31^2 + b * 31 + c
		//H[4] = a * 31^3 + b * 31^2 + c * 31 + d
		//H[5] = a * 31^4 + b * 31^3 + c * 31^2 + d*31 + e

		//a * 31^4 + b * 31^3 + c * 31^2 + d*31 + e - (H[6-3-1] * 31^3)
		//a * 31^4 + b * 31^3 + c * 31^2 + d*31 + e - (a * 31^4 + b * 31^3)
		//c * 31^2 + d*31 + e == t[0] * 31^2 + d * 31 + e  ?
		//you can just pop off then continue if it does

		//H.back() - (x * 31^t.size())
		if(((H.back()) - (((H[H.size()-t.size()-1] + MOD) % MOD) * lpower(31,t.size(),MOD) % MOD) + MOD) % MOD == tval){
			for(int j = 0; j < t.size(); j++){
				H.pop_back(); ans.pop_back();
			}
		}


		

	}
	//rep(i, H.size()) out(H[i]);
	out(ans);





	
}