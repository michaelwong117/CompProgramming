//g++-7 filename.cpp -std=c++14
#include <bits/stdc++.h>
using namespace std;
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

int N; vector<vi> v;

vi seen (101, 0);

void viewPaths(int par, int count){
	seen[par] = 1;
	for(int i = 0; i < v[par].size(); i++){
		if(seen[v[par][i]] == 1){
			cout << -1 << endl;
			exit();
		}
		else{
			seen[v[par][i]] = 1;

		}
		count = viewPaths(org, v[par], count+1)
	}
}

int main()
{
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> N;
	v.resize(N+1);
	for(int i = 1; i <= N-1; i++){
		int a, b; cin >> a >> b;
		v[b].pb(a); //reverse edges
	}
	// for(int i = 1; i <= N; i++){
	// 	cout << "current " << i << endl;
	// 	// cout << v[i].size() << endl;
	// 	for(int j = 0; j < v[i].size(); j++){
	// 		cout << v[i][j] << endl;
	// 	}
	// }
	for(int i = 1; i <= N; i++){
		viewPaths(i, 1);
		seen.resize(101, 0);
	}








}
