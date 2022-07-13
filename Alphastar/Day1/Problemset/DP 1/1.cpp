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
const ll mx = 7*1e5+10;

int n;
vl bale (mx), A(mx), B(mx);
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n;
	rep(i, n) cin >> bale[i+1];
	A[n] = bale[n]; B[n] = 0;
	for(int i = n-1; i >= 1; i--){
		if(bale[i] + B[i+1] >= A[i+1]){
			A[i] = bale[i]+B[i+1];
			B[i] = A[i+1];
		}
		else{
			A[i] = A[i+1];
			B[i] = B[i+1];
		}
	}
	cout << A[1] << " " << B[1] << endl;
}