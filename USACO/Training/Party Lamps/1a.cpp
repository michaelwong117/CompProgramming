/*
ID: michaelwong11
PROG: lamps 
LANG: C++14     
*/
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


int n, c;

vector<pair<int,bool>> key;
vector<vector<bool>> v;

bool check(vector<bool> &b){
	for(int i = 0; i < key.size(); i++){
		if(b[key[i].f] != key[i].s) return false;
	}
	return true;
}

void button(int call, vector<bool> &b){
	if(call == 1) for(int i = 0; i < b.size(); i++) b[i] = !b[i];
	else if(call == 2) for(int i = 0; i < b.size(); i+=2) b[i] = !b[i];
	else if(call == 3) for(int i = 1; i < b.size(); i+=2) b[i] = !b[i];
	else for(int i = 0; i < b.size(); i+=3) b[i] = !b[i];
}

void findall(int x){
	vector<bool> b (n, 1);
	if(x % 2 == 0){
		if(x >= 0){
			//0
			if(check(b)) v.pb(b);
		}
		if(x >= 2){
			//0, 2
			for(int i = 1; i < 4; i++){
				for(int j = i+1; j <= 4; j++){
					button(i, b);
					button(j, b);
					if(check(b)) v.pb(b);
					fill(all(b), 1);
				}
			}	
		}
		if(x >= 4){
			//0, 2, 4
			for(int i = 1; i <= 4; i++) button(i, b);
			if(check(b)) v.pb(b);
			fill(all(b), 1);
		}
	}
	else{
		if(x >= 1){
			//1 
			for(int i = 1; i <= 4; i++){
				button(i, b);
				if(check(b)) v.pb(b);
				fill(all(b), 1);
			}
		
		}
		if(x >= 3){
			//1, 3
			for(int i = 1; i < 3; i++){
				for(int j = i+1; j < 4; j++){
					for(int k = j+1; k <= 4; k++){
						button(i, b);
						button(j, b);
						button(k, b);
						// if(check(b)){
						// 	v.pb(b);
						// 	cout << i << " " << j << " " << k << endl;
						// }
						fill(all(b), 1);
					}
				}
			}
		}
		
	}
}
bool sortbinary(const vector<bool> &a,
              const vector<bool> &b){
    rep(i, a.size()){
    	if(a[i] == b[i]) continue;
    	else return !a[i];
    }
    return true;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("lamps.in","r",stdin); freopen("lamps.out","w",stdout);
	cin >> n >> c;	
	while(1){
		int x; cin >> x;
		if(x == -1) break;
		key.pb({x-1, 1});
	}
	while(1){
		int x; cin >> x;
		if(x == -1) break;
		key.pb({x-1, 0});
	}
	findall(c); 
	if(v.size() == 0){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	sort(all(v), sortbinary);
	for(int i = 0; i < v.size(); i++){
		for(auto a: v[i]){
			cout << a;
		}
		cout << endl;
	}
	// vector<bool> t1 (10, 1);
	// vector<bool> t2 (10, 1);
	// button(1, t1); 
	// button(2, t2);
	// for(auto a: t1){
	// 	cout << a << " ";
	// }
	// out(endl);
	// for(auto a: t2){
	// 	cout << a << " ";
	// }
	// out(endl);

}
