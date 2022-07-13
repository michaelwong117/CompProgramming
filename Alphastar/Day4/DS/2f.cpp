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

int n, k, x, y, a, b;

int H[3000000];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		cin >> x >> y >> a >> b;
		int cur = 0;
		for(int j = 1; j <= y; j++){
			cur = (cur + a) % n;
			H[(cur + b) % n] += x;

		}
	}
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += H[i];
		if(sum > 0) sum--;
	}
	for(int i = 0; i < n; i++){
		sum += H[i];
		if(sum > 0) sum--;
		else{
			cout << i << endl;
			break;
		}
	}

}
