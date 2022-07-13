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
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	ll n, m; cin >> n >> m;
	vl a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}	
	ll written = 0;
	for(int i = 0; i < n; i++){
		ll curnames = a[i], remain = m-written;
		if(remain > curnames){
			written += curnames;
			cout << 0 << " ";
		}
		else{
			curnames -= remain;
			cout << (curnames / m) + 1 << " ";
			written = curnames % m;
		}
	}
	//find how many more names can be written on current page (m - writtenalready)
	//if that's greater than the number of names you need to write on this day
	//update written += curnames
	//otherwise
	//subtract curnames - remain
	//find how many times curnames can be divided by m
	//update pages with curnames / m
	//add curnames % m to how many names have currently been written on the next page

}