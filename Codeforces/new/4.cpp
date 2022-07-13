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

string s, h1, h2, cen;

bool odd = 0;

bool check(){
	for(int i = 1; i < s.size(); i++){
		string n = "", org;
		n += s.substr(i, string::npos); n += s.substr(0, i);
		org = n;
		reverse(all(n));
		if(n != s && n == org){
			// cout << org << endl;
			return true;
		}
			
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
   cin >> s;
	if(s.size() % 2){
		h1 = s.substr(0, s.size()/2);
		cen = s[s.size()/2];
		h2 = s.substr(s.size()/2+1, string::npos);
		odd = 1;
	}
	else{
		h1 = s.substr(0, s.size()/2);
		h2 = s.substr(s.size()/2, string::npos);
	}
	bool imp = true;
	for(int i = 1; i < h1.size(); i++){
		if(h1[i] != h1[i-1]) imp = false;
	}
	if(imp){
		cout << "Impossible" << endl;
	}
	else if(odd){
		if(check()) cout << 1 << endl;
		else cout << 2 << endl;
	}
	else{
		if(h1 != h2){
			cout << 1 << endl;
		}
		else{
			if(check()) cout << 1 << endl;
			else cout << 2 << endl;
		}
	}
	// cout << h1 << " " << cen << " " << h2 << endl;
}
