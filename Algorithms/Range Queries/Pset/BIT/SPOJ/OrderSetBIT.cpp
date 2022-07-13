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
const int mx = 2*1e6+1;

int n, arr[mx], bit[mx];
bool s[mx];
char c[mx];
vpi v;
unordered_map<int,int> m;
Tree<int> key;

void upd(int x, int val){
	while(x <= mx){
		bit[x] += val; x += x&-x;
	}
}
int query(int x){
	int sum = 0;
	while(x >= 1){
		sum += bit[x]; x -= x&-x;
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("filename.in","r",stdin); //freopen("filename.out","w",stdout);	
	cin >> n;
	rep(i, n){
		cin >> c[i]; cin >> arr[i];
		v.pb({arr[i], 0});
	}
	sort(all(v)); int l = 1;
	rep(i,v.size()) if(m.count(v[i].f)==0){
		m[v[i].f] = l++;
	}
	rep(i, n){
		int idx = m[arr[i]];
		if(c[i] == 'I'){
			key.insert(arr[i]);
			if(!s[idx]) upd(idx, 1);
			s[idx] = 1;
		}
		if(c[i] == 'D'){
			key.erase(arr[i]);
			if(s[idx]) upd(idx, -1);
			s[idx] = 0;
		}
		if(c[i] == 'C') out(query(idx-1));
		if(c[i] == 'K'){
			//mx-1 because mx would give segfault
			if(arr[i] > query(mx-1)) out("invalid");
			else out(*key.find_by_order(arr[i]-1));

		}
	}
}