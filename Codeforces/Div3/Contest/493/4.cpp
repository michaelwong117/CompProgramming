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

int n; 
string a, b;


int check(int i){
	int moves = 0;
	if(a[i] == a[n-i-1] && b[i] == b[n-i-1]) return 0;
	if(a[i] == a[n-i-1]) return 1;
	if(b[i] == b[n-i-1]) return 1;
	else if(a[n-i-1] == b[i]){
		if(a[i] != b[n-i-1]) moves++;
	}
	else if(b[n-i-1] == a[i]){
		if(b[i] != a[n-i-1]) moves++;
	}
	else if(a[i] == b[i] && a[n-i-1] != b[n-i-1]){
		moves++;
	}
	else if(a[i] != b[i] && a[n-i-1] == b[n-i-1]){
		moves++;
	}
	else if(a[i] != b[i] && a[n-i-1] != b[n-i-1]){
		moves += 2;
	}
	return moves;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);
	cin >> n;
	cin >> a >> b;	
	int moves = 0;
	for(int i = 0; i <= n/2; i++){
		if(i == n/2 && n % 2 == 1){
			if(a[i] != b[i]){
				moves++;
			}
		}
		if(a[i] != b[i] || a[n-i-1] != b[n-i-1]){
			int res = check(i);
			moves += res;

		}
	}
	cout << moves << endl;

}