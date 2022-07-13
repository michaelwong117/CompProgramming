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
ll c = 0;
int dx[8] = {-1,1,2,2,1,-1,-2,-2};
int dy[8] = {2,2,1,-1,-2,-2,-1,1};

bool valid(int x, int y){
	if(x >= 0 && x < n && y >= 0 && y < n) return true;
	else return false;
}
int block(int i, int i2){
	int b = 0;
	for(int j = 0; j < 8; j++) if(valid(i+dx[j], i2+dy[j])) b++;
	return b;
}

void solve(int idx){
	for(int i = 0; i < n; i++){
		for(int i2 = 0; i2 < n; i2++){
			c += n*n-block(i,i2)-1;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("filename.in","r",stdin); //freopen("filename.out","w",stdout);	
	cin >> n;
	cout << 0 << endl;
	int temp = n;
	for(int i = 2; i <= temp; i++){
		n = i;
		solve(i-1);
		cout << c/2ll << endl;
	}
	

}