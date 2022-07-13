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
	//freopen("input.in","r",stdin); //freopen("filename.out","w",stdout);	
	int n;
	string s;
	cin >> n >> s;
	map<string, int> m;
	for(int i = 0; i < n-1; i++){
		string a = "";
		for(int j = i; j <= i+1; j++){
			a += s[j];
		}
		if(m.find(a) != m.end()){
			m[a]++;
		}
		else{
			m[a] = 1;
		}
	}
	int mx = -1e9;
	string best = "";
	for(auto a: m){
		if(a.s > mx){
			mx = a.s;
			best = a.f;
		}
	}
	cout << best << endl;
}