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

int n; 

vector<vi> v1;

vector<vi> rotate(vector<vi> v){
	vector<vi> res;
	for(int i = 0; i < n; i++){
		vi line;
		for(int j = n-1; j >= 0; j--){
			line.pb(v[j][i]);
			// cout << v[j][i] << " " ;
		}
		res.pb(line);
		// cout << endl;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n;
	v1.resize(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int x; cin >> x;
			v1[i].pb(x);
		}
	}
	for(int i = 0; i < 4; i++){
		bool works = 1;
		v1 = rotate(v1);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < v1[i].size()-1; j++){
				if(v1[i][j] > v1[i][j+1]) works = 0;
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n-1; j++){
				if(v1[j][i] > v1[j+1][i]) works = 0;
			}
		}
		if(works == 1){
			for(auto a: v1){
				for(auto b: a){
					cout << b << " ";
				}
				cout << endl;
			}
			return 0;

		}
	
	}
	// vector<vi> test = {{1,2,3},{4,5,6},{7,8,9}};
	// vector<vi> r = rotate(v1);
	// for(auto a: r){
	// 	for(auto b: a){
	// 		cout << b << " ";
	// 	}
	// 	cout << endl;
	// }
}
