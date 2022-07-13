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

vector<string> v;

int col, st;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++){
		string s = "";
		for(int j = 0; j < m; j++){
			char c; cin >> c;
			s += c;
		}
		v.pb(s);
	}
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v[i].size(); j++){
			if(v[i][j] == 'B'){
				int beg = i;
				while(i+1 < n && i+2 < n && v[i+1][j] == 'B' && v[i+2][j] == 'B'){
					i += 2;
				}
				st = j; 
				int k = st;
				while(k+1 < v[i].size() && v[i][k+1] == 'B') k++;
				if(i == beg){
					cout << i+1 << " ";
				}
				else{
					cout << (i + beg) / 2 + 1 << " ";
				}
				if(k == st){
					cout << k+1 << " ";
				}
				else{
					cout << (k + st) / 2 + 1 << " "; 
				}

				return 0;
			}
		}
	}
}
