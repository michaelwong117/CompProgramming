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

ll n, k, a[2*100000+1];

unordered_map<char, int> used;

unordered_map<char, priority_queue<ll, vl, greater<ll>>> m;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	string s; cin >> s;
	ll cur = 0; char prev = '*';

	for(int i = 0; i < n; i++){
		if(prev != s[i]){
			used[prev] = 0;
			used[s[i]] = 0;
			m[prev] = {};
		}
		if(used[s[i]] == k){
			if(m[s[i]].top() < a[i]){
				cur -= m[s[i]].top(); m[s[i]].pop(); 

				m[s[i]].push(a[i]); cur += (ll) a[i];
			}
		}
		else{
			used[s[i]]++;
			cur += a[i];
			m[s[i]].push(a[i]);
		}
		prev = s[i];
	}


	// for(char c = 'a'; c <= 'c'; c++){
	// 	while(!m[c].empty()){
	// 		cout << m[c].top() << " ";
	// 		m[c].pop();
	// 	}
	// 	cout << endl;
	// }
	cout << cur << endl;
}
