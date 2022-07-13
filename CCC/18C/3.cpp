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

int n, m;

vector<string> box;

int valid[101][101], vis[101][101], mn[101][101];

bool isConv(char c){
	if(c == 'L' || c == 'R' || c == 'D' || c == 'U') return true;
	return false;
} 

void cam(int i, int j){
	int oi = i, oj = j;
	while(i < n){
		if(box[i][j] == 'W') break;
		else if(box[i][j] == '.' || box[i][j] == 'S') valid[i][j] = 0;
		i++; 
	}
	i = oi;
	while(j < m){
		if(box[i][j] == 'W') break;
		else if(box[i][j] == '.' || box[i][j] == 'S') valid[i][j] = 0;
		j++; 
	}
	j = oj;
	while(i >= 0){
		if(box[i][j] == 'W') break;
		else if(box[i][j] == '.' || box[i][j] == 'S') valid[i][j] = 0;
		i--; 
	}
	i = oi;
	while(j >= 0){
		if(box[i][j] == 'W') break;
		else if(box[i][j] == '.' || box[i][j] == 'S') valid[i][j] = 0;
		j--; 
	}
	j = oj;

}
void solve(int i, int j, int d){
	if(i < 0 || i >= n || j < 0 || j >= m) return;
	if(!valid[i][j]) return;
	if(d >= mn[i][j]) return;
	// cout << i << " " << j << " " << d << endl;
	mn[i][j] = min(mn[i][j], d);
	// if(box[i][j] == '.') mn[i][j] = min(mn[i][j], d);
	// if(vis[i][j]) return;
	// vis[i][j] = 1;

	if(isConv(box[i][j])){
		if(box[i][j] == 'U'){
			solve(i-1, j, d);
		}
		if(box[i][j] == 'D'){
			solve(i+1, j, d);
		}
		if(box[i][j] == 'L'){
			solve(i, j-1, d);
		}
		if(box[i][j] == 'R'){
			solve(i, j+1, d);
		}
	}
	else{
		solve(i-1, j, d+1);
		solve(i+1, j, d+1);
		solve(i, j-1, d+1);
		solve(i, j+1, d+1);
	}

}



int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		box.pb(s);
	}
	pi st;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(box[i][j] == 'S'){
				st = {i, j};
			}
			valid[i][j] = 1;
			if(box[i][j] == 'W') valid[i][j] = 0;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(box[i][j] == 'C'){
				valid[i][j] = 0;
				cam(i, j);
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			mn[i][j] = 1e9;
		}
	}
	solve(st.f, st.s, 0);


	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(box[i][j] == '.'){
				if(mn[i][j] == 1e9) cout << -1 << endl;
				else cout << mn[i][j] << endl;
			}
		}
	}
	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < m; j++){
	// 		cout << box[i][j];
	// 	}
	// 	cout << endl;
	// }

	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < m; j++){
	// 		cout << valid[i][j];
	// 	}
	// 	cout << endl;
	// }


}
