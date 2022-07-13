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
typedef unsigned long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

const int N = 2*1e5+1;

unsigned hash_f(unsigned x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}
struct chash {
    int operator()(int x) const { return hash_f(x); }
};
gp_hash_table<ll, int, chash> digtomod[11];

int n, k, dig[N];
ll a[N], ten[10];

// i != j all at once

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you  start coding, think it through
	cin >> n >> k;
 
	for(int i = 0; i < n; i++){
		cin >> a[i];
		ll var = a[i], c = 0;
		while(var > 0){
			var /= 10;
			c++;
		}
		dig[i] = c;
	}
	ten[0] = 10;
	for(int i = 1; i < 10; i++) ten[i] = ten[i-1] * 10 % k;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < 10; j++){
			digtomod[j+1][((a[i] % k) * ten[j]) % k]++;
		}
	}
	ll res = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 10; j++){
			digtomod[j+1][((a[i] % k) * ten[j]) % k]--;
		}

		int left = a[i] % k;
		//cout << a[i] <<  " " << left << " " << digtomod[dig[i]][k-left] << endl;
		if(digtomod[dig[i]].find((k - left) % k) != digtomod[dig[i]].end()){
			res += digtomod[dig[i]][(k - left) % k];
		}

		for(int j = 0; j < 10; j++){
			digtomod[j+1][((a[i] % k) * ten[j]) % k]++;
		}

	}

	cout << res << endl;
}
