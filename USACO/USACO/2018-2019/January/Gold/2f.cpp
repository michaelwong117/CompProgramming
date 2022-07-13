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

vi v;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("sleepy.in","r",stdin); freopen("sleepy.out","w",stdout);	
	//before you start coding, think it through
	cin >> n;

	for(int i = 0; i < n; i++){
		int x; cin >> x;
		v.pb(x);
	}
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}
	int j = n-1;
	int sortedend = 1;
	while(j != 0 && v[j-1] < v[j]){
		j--; sortedend++;
	}
	cout << n-sortedend << endl;
	Tree<int> s;
	for(int i = j; i < n; i++){
		s.insert(v[i]);
	}
	for(int i = 0; i < j; i++){
		cout << s.order_of_key(v[i]) + j - i - 1;
		// auto it = s.upper_bound(v[i]);
		// cout << distance(s.begin(), it) + j - i - 1;
		if(i == j-1) cout << endl;
		else cout << " ";
		// cout << v[i] << " " << (*it) << endl;
		// cout << "DIST " << distance(s.begin(), it) + j - i - 1<< endl;
		s.insert(v[i]);
		// for(auto a: s) cout << a << " ";
		// cout << endl;

	}

	// for(int i = j; i < n; i++){
	// 	cout << v[i] << " "; 
	// }
	// cout << endl;
	


}
