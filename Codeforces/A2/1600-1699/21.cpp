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

//lang as idx, give all em
vi lang[101];
//for employee idx i, give all langs
vi emlang[101];
vi groups (101, -1);
//cur is current employee
void dfs(int cur, int name){
	for(int i = 0; i < emlang[cur].size(); i++){
		int curlang = emlang[cur][i];
		for(int j = 0; j < lang[curlang].size(); j++){
			//employee who shares a lang (translate or dir)
			int emlink = lang[curlang][j];
			if(groups[emlink] == -1){
				groups[emlink] = name;
				dfs(emlink, name);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	int n, m; cin >> n >> m;
	bool allzero = 1;
	rep(i, n){
		int k; cin >> k;
		rep(j, k){
			allzero = 0;
			int l; cin >> l;
			emlang[i].pb(l);
			lang[l].pb(i);
		}
	}
	if(allzero){
		out(n);
		return 0;
	}
	int c = 0;
	for(int i = 0; i < n; i++){
		if(groups[i] == -1){
			c++;
			groups[i] = c;
			dfs(i, c);
		}
	}
	out(c-1);

}