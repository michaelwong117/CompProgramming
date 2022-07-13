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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	int n; cin >> n;
	vi w(n);
	for(int i =0 ; i < n; i++){
		cin >> w[i];
	}
	if(w[0] == 3){
		cout << "NO" << endl;
		return 0;
	}
	int prev = w[0], spect;
	if(w[0] == 1) spect = 2;
	if(w[0] == 2) spect = 1;
	for(int i = 1; i < n; i++){
		if(spect == w[i]){
			cout << "NO" << endl;
			return 0;
		}
		
		if(w[i] == prev){
			set<int> s = {1,2,3};
			s.erase(w[i]); s.erase(spect);
			for(auto a: s){
				spect = a; 
			}
			continue;
		}
		spect = prev;
		prev = w[i];

		
		// if(w[i] == 1){
		// 	if(w[i] == prev) continue;
		// 	spect = prev;

		// }
		// if(w[i] == 2){
		// 	if(w[i] == prev) continue;
		// }
		// if(w[i] == 3){
		// 	if(w[i] == prev) continue;
		// 	spect = prev;
		// }
	}
	cout << "YES" << endl;

}
