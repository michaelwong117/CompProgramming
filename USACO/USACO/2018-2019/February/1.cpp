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
typedef long double ld;

const int N = 1e6;

struct P {
	ld sum, run, cur;
};

int a[N];
P prob[N];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("cowdate.in","r",stdin); freopen("cowdate.out","w",stdout);	
	//before you start coding, think it through
	int n, mx = 0; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		prob[i].cur = (ld) a[i] / N;
		if(i > 0){
			prob[i].sum = prob[i-1].sum * ((ld) 1 - prob[i].cur);
			prob[i].sum += prob[i-1].run * prob[i].cur;
			prob[i].run = prob[i-1].run * ((ld) 1 - prob[i].cur);
		}
		else{
			prob[i].sum = prob[i].cur;
			prob[i].run = (ld) 1 - prob[i].cur;
		}
		mx = max((int) (N * prob[i].sum), mx);
	}
	for(int i = 1; i < n; i++){
		ld upsum = prob[i].sum, uprun = prob[i].run;
		// cout << upsum << " " << uprun << endl;
		for(int j = 0; j < i; j++){
			ld opp = (ld) 1 - prob[j].cur;
			upsum = (upsum - ((uprun / opp) * prob[j].cur)) / opp;
			uprun /= opp;
			mx = max((int) (N * upsum), mx);
			// cout << upsum << " " << uprun << endl;s
		}
	}
	cout << mx << endl;
}
