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
const int mx = 3*1e5+1;
vl a(mx), b(mx), preA(mx), preB(mx), lastd(mx), lastu(mx);
ll n;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0 ; i < n; i++){
		cin >> b[i];
	}
	for(int i = 1; i <= n; i++){
		preA[i] += a[i] + preA[i-1];
		preB[i] += b[i] + preB[i-1];
	}

	//base case all left then all right
	ll base = 0;
	for(ll i = 0; i < n; i++){
		base += a[i] * i;
		base += b[i] * (2 * n - i - 1);
	}
	ll up = 0, down = 0;
	for(ll i = 1; i < n; i++){
		lastu[i] = (2 * n - (i + i));
		lastd[i] = (2 * n - (i + i) - 2);
		if(i % 2 == 0){ //if i is odd the -2 / +2 pattern will resolve itself since it alternates
			lastu[i] -= 2;
			lastd[i] += 2;
		}
		//cout << lastu[i] << " " << lastd[i] << endl;
		up += a[i] * (2 * n - (i + i));
		down += b[i] * (2 * n - (i + i) - 2);
	}

	// cout << base << endl;
	// ll firstdiff = b[0] * (2 * n - (2 * (1)));
	// cout << firstdiff << " " << up << " " << down << endl;
	// cout << base - firstdiff - down + up << endl;

	// cout << base - up + down - firstdiff << endl;


	ll res = base, firstsum = 0;


	ll calc = base;

	for(ll i = 0; i < n; i++){

	 	ll cur = calc, firstdiff;

	 	if(i >= 1){
		 	// cout << up << " " << (i % 2 == 0 ? 1 : -1) * 2 * (preA[n] - preA[i]) << " " << lastu[i] << endl;
	 		// cout << down << " " << (i % 2 == 0 ? -1 : 1) * 2 * (preB[n] - preB[i]) << " " << lastd[i] << endl;

	 		up += (i % 2 == 0 ? 1 : -1) * 2 * (preA[n] - preA[i]);
	 		down += (i % 2 == 0 ? -1 : 1) * 2 * (preB[n] - preB[i]);
	 		up -= lastu[i] * a[i]; 
	 		down -= lastd[i] * b[i];

	 		// cout << "FINAL " << up << " " << down << endl;

	 	}

		if(i % 2 == 0){
			cur += up - down;
			firstdiff = b[i] * (2 * n - (2 * (i+1)));


			firstsum += a[i] * (i+i);
			firstsum += b[i] * (i+i+1);
		}
		else{
			cur += down - up;
			firstdiff = a[i] * (2 * n - (2 * (i+1)));


			firstsum += a[i] * (i+i+1);
			firstsum += b[i] * (i+i);
		}
		cur -= firstdiff;
		//cout << cur << endl;
		res = max(res, cur);
		calc = cur;


	}
	cout << max(firstsum, res) << endl;

	//got confused
	//mixed up my notes several times
	//went back and reviewed things several times that I already confirmed
	//lots of useless checking-- thinking something was wrong but it was still right
	//made one mistake in my notes that cost me at least half an hour to work out
	//messy, unreadable notes
	//not thinking in a clear order (for some i, we. compute this for this i)
	//not understanding what needed to be precomputed
	//writing down the wrong numbers several times, following completely wrong patterns
	//misunderstood question at the beginning
	//result? 4 hours spent on this problem

	//finally got problem after making checklist of small parts, writing clear, legible notes and writing out 
	//important numbers and calculations by hand

	//for each i 0...n-1
	//calculate the value when you cut off everything before and including column i
	//several parts
	//1. calculate the value of everything up to and including column i (keep a running sum)
	//2. calculate the the new value of everything after column i, var. after
	//several parts to computing after
	//1. have the previous after stored in two parts, up and down
	//2. use the -2 2 2 + 2 2 2. pattern to compute the new up and down from previous (up + down is the after)
	//this is the two pattern difference only for i >= 1, you precompute for i = 0;
	//prefix[i] bc 1-idxed
	//up += (i % 2 == 0 ? 1 : -1) * 2 * (prefix[n] - prefix[i]) 
	//down += (i % 2 == 0 ? -1 : 1) * 2 * (prefix[n] - prefix[i])
	//update up and down bc you move over one col





}