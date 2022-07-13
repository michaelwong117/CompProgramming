//g++-7 filename.cpp -std=c++14 
#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define endl '\n'
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define pq priority_queue<int, vector<int>, greater<int>>
#define mpq priority_queue<int>
 
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
int x, d; 
vl final;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("filename.in"); ofstream fout("filename.out");
	fin >> x >> d;
	ll mn = 0, mx = 0;
	while(x > 0){
		final.pb(mx);
		mx++;
		if(mx - mn >= d){
			x -= pow(2ll, d-1)-1;
		}
		else{
			x -= pow(2ll, mx-mn)-1;
		}
	}
	if(x < 0) cout << -1 << endl;
	else{
		for(auto a: final){
			cout << a << " ";
		}
		cout << endl;
	}

	
}