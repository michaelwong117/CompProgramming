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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	int l, r; cin >> l >> r;
	string s, t; cin >> s >> t;
	string part1 = "", part2 = ""; 
	bool wild = false;
	if(s.size()-1 > t.size()){
		cout << "NO" << endl;
		return 0;
	}
	for(int i = 0; i < s.size(); i++){
		if(wild) part2 += s[i];
		else part1 += s[i];
		if(s[i] == '*') wild = true;
	}
	if(find(all(s), '*') == s.end()){
		if(s != t){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
		}
		return 0;
	}

	for(int i = 0; i < t.size(); i++){
		if(i < part1.size()-1) continue;
		cout << t.substr(i, part2.size()) << endl;
		if(t.substr(i, part2.size()) == part2){
			cout << "YES" << endl;
			return 0;
		}
	}
	s.erase(find(all(s), '*'));
	if(s == t){
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;

}