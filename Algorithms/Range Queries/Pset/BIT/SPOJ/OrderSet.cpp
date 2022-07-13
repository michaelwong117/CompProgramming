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
#define out(x) cout << x << endl
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

int n;
Tree<int> T;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("filename.in","r",stdin); //freopen("filename.out","w",stdout);

	//find_by_order(k) gives kth smallest element (indexed by 0)
	//to find kth largest element multiply everything by -1 (rT)
	
	// rep(i, 3){
	// 	T.insert(i+1);
	// }
	// for(auto a: T) cout << a << endl;
	// cout << *T.find_by_order(0) << " " << *T.find_by_order(1) << " " << *T.find_by_order(2) << endl;
	cin >> n;
	rep(i, n){
		char c; cin >> c;
		int x; cin >> x;
		if(c == 'I'){
			T.insert(x);
		}
		if(c == 'D'){
			T.erase(x);
		}
		if(c == 'C') out(T.order_of_key(x));
		if(c == 'K'){
			if(x > T.size()) out("invalid");
			else{
				cout << *T.find_by_order(x-1) << endl;
				// cout << endl;
				// for(auto a: rT) cout << a << " ";
				// cout << endl;
				// for(auto a: T) cout << a << " ";
				// cout << endl;
				// cout << *rT.find_by_order(0) << " " << *rT.find_by_order(1) << endl;
				// cout << *T.find_by_order(0) << " " << *T.find_by_order(1) << endl;
				// cout << (*rT.find_by_order(x-1)) << " " << x-1 << endl;
			}

		}


	}
}