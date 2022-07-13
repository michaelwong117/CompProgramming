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

const int N = 2*1e5+1;

vector<unordered_map<int,int>> digtomod(11);

int n, k, a[N], dig[N];

//i < j, i > j

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you  start coding, think it through
	cin >> n >> k;
 
	for(int i = 0; i < n; i++){
		cin >> a[i];
		int var = a[i], c = 0;
		while(var > 0){
			var /= 10;
			c++;
		}
		dig[i] = c;
	}

	int cur = 1;
	for(int i = 0; i < 10; i++){
		cur = (cur * 10) % k;
		//cout  << i+1  << " " << (a[0] * cur) % k << endl;
		digtomod[i+1][((ll) (a[0] % k) * (ll) cur) % k]++;
	}
	ll res = 0;
	for(int i = 1; i < n; i++){
		int left = a[i] % k;
		//cout << a[i] << " " << left << " " << digtomod[dig[i]][k-left] << endl;
		if(left == 0){
			res += digtomod[dig[i]][0];
			//cout << digtomod[dig[i]][0] << endl;
		}
		else{
			res += digtomod[dig[i]][k-left];
			//cout << digtomod[dig[i]][k-left] << endl;
		}
		cur = 1;
		for(int j = 0; j < 10; j++){
			cur *= 10;
			digtomod[j+1][((ll) (a[i] % k) * (ll) cur) % k]++;
			cur %= k;
		}

	}

	digtomod.clear(); digtomod.resize(11);

	cur = 1;
	for(int i = 0; i < 10; i++){
		cur *= 10;
		//cout << i+1 << " "  << (a[0] * cur) % k << endl;
		digtomod[i+1][((ll) (a[n-1] % k) * (ll) cur) % k]++;
		cur %= k;
	}
	for(int i = n-2; i >= 0; i--){
		int left = a[i] % k;
		//cout << a[i] << " " << left << " " << digtomod[dig[i]][k-left] << endl;
		if(left == 0){
			res += digtomod[dig[i]][0];
			//cout << digtomod[dig[i]][0] << endl;
		}
		else{
			res += digtomod[dig[i]][k-left];
			//cout << digtomod[dig[i]][k-left] << endl;
		}
		cur = 1;
		for(int j = 0; j < 10; j++){
			cur *= 10;
			digtomod[j+1][((ll) (a[i] % k) * (ll) cur) % k]++;
			cur %= k;
		}

	}

	cout << res << endl;
}
