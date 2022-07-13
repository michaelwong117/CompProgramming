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
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through

	int w, h, u1, d1, u2, d2;
	cin >> w >> h >> u1 >> d1 >> u2 >> d2;
	while(h > 0){
		w += h; 
		if(h == d1){
			w -= u1;
			w = max(w, 0);
		}
		if(h == d2){
			w -= u2;
			w = max(w, 0);
		}
		h--;
	}
	if(d1 == 0){
		w -= u1;
		w = max(w, 0);

	}
	if(d2 == 0){
		w -= u2;
		w = max(w, 0);

	}
	cout << w << endl;
}
