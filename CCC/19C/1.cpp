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

string s;

vi v = {1,2,3,4};


void h(){
	vi n;
	n.pb(v[2]); n.pb(v[3]);
	n.pb(v[0]); n.pb(v[1]);
	v = n;
}
void ve(){
	vi n;
	n.pb(v[1]); n.pb(v[0]);
	n.pb(v[3]); n.pb(v[2]);
	v = n;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'H'){
			h();
		}
		else{
			ve();
		}
	}
	for(int i = 0; i < 2; i++){
		cout << v[i] << " ";
	}
	cout << endl;
	for(int i = 2; i < 4; i++){
		cout << v[i] << " ";
	}
	cout << endl;
}
