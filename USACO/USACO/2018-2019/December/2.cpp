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

int n, cow[50001][5];

unordered_map<int, vector<int>> f;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("cowpatibility.in","r",stdin); freopen("cowpatibility.out","w",stdout);	
	//before you start coding, think it through 
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 5; j++){
			int flav; cin >> flav;
			if(f.find(flav) == f.end()){
				f[flav] = {i};
			}
			else{
				f[flav].pb(i);
			}
			cow[i][j] = flav;
		}
	}

	// for(auto a: f){
	// 	cout << a.f << " " << a.s.size() << endl << endl;
	// 	for(auto b: a.s) cout << b << endl;
	// 	cout << endl;
	// }
	int res = 0;

	bool good[n+1];

	for(int i = 1; i <= n; i++){
		int gc = 0;
		memset(good,0,sizeof good);
		for(int j = 0; j < 5; j++){
			for(auto a: f[cow[i][j]]){
				//a > i means you don't double count back
				//or count i itself again
				if(a > i && !good[a]){
					good[a] = 1; gc++;
				}
			}
		}
		//pairs that are possible minus good cows
		res += (n - i - gc);

	}
	cout << res << endl;
}
