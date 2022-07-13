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
const int N = 1e5+1;

ll n, r, avg;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	

	cin >> n >> r >> avg;
	vl a (n);
	vector<pl> b (n);

	ll sum = 0, essays = 0;

	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i].f;
		b[i].s = i;
		sum += a[i];
	}
	if((sum / n) >= avg){
		out(essays); return 0;
	}

	sort(all(b));

	int i = 0;
	ll diff = (ll) avg * (ll) n - sum;

	while(diff > 0){
		//cout << diff << " " << r << " " << a[b[i].s] << " " << b[i].f << endl;
		if(diff >= r - a[b[i].s]){
			diff -= r - a[b[i].s]; essays += (r-a[b[i].s]) * b[i].f;
			i++;
		}
		else{

			break;
		}
	}
	if(diff == 0){
		out(essays); return 0;
	}

	essays += diff * b[i].f;

	out(essays);
	

}