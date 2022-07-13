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

int n, k;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n >> k;

	string t; cin >> t;
	if(k == 1){
		cout << t << endl;
		return 0;
	}
	string st = t;
	for(int i = 1; i < t.size(); i++){
		//cout << t.substr(i, t.size()-i) << " " << t.substr(0, t.size()-i) << endl;
		if(t.substr(i, t.size()-i) == t.substr(0, t.size()-i)){
			st = t.substr(t.size()-i, i);
			break;
		}

	}
	string final = t;
	int c = 1;
	while(c < k){
		final += st; c++;
	}
	cout << final << endl;
}
