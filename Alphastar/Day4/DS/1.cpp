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

const int N = 201;

int n, x[N], y[N], c = 0;

unordered_map<ll,bool> hash1, hash2;

ll lpower(ll a, ll b, ll mod){
	ll res = 1;

	a %= mod;

	while(b > 0){

		if(b & 1){
			res = (res * a) % mod; b--;
		}
		a = (a * a) % mod; b /= 2;

	}
	return (res % mod);
}

long double slope(int i, int j){
	int num = y[j] - y[i], denom = x[j] - x[i];
	if(denom == 0) return -99999999.99999;
	long double res = (long double) num / denom;
	return res;
}


string to_string_with_precision(long double m, int prec){
    ostringstream out;
    out << setprecision(prec) << m;
    return out.str();
}


ll hashf(long double m){
	string s = to_string_with_precision(m, 8);
	ll res = 0, dig;
	for(int i = s.size()-1; i >= 0; i--){
		if(s[i] == '.') continue;
		dig = s[i] - '0' + 1;
		res += (dig * (lpower(11, s.size()-1-i, MOD) % MOD) % MOD);
	}
	return res;
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			long double m = slope(i, j);
			ll h = hashf(abs(m));
			if(m < 0){
				if(hash1[h]) continue;
				hash1[h] = 1; c++;
			}
			else{
				if(hash2[h]) continue;
				hash2[h] = 1; c++;
			}
		}
	}
	cout << c << endl;

}