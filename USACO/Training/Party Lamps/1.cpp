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

const int mx = 101;

int n, c;
vpi key;

void b1(vector<bool> &b){
	for(int i = 0; i < b.size(); i++) b[i] = !b[i];
}
void b2(vector<bool> &b){
	for(int i = 0; i < b.size(); i+=2) b[i] = !b[i];
}
void b3(vector<bool> &b){
	for(int i = 1; i < b.size(); i+=2) b[i] = !b[i];
}
void b4(vector<bool> &b){
	for(int i = 0; i < b.size(); i+=3) b[i] = !b[i];
}
bool check(vector<bool> &b){
	for(int i = 0; i < key.size(); i++){
		if(b[key[i].f] != key[i].s) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("lamps.in","r",stdin); //freopen("lamps.out","w",stdout);
	cin >> n >> c;	
	while(1){
		int x; cin >> x;
		if(x == -1) break;
		key.pb(x, 1);
	}
	while(1){
		int x; cin >> x;
		if(x == -1) break;
		key.pb(x, 0);
	}




}