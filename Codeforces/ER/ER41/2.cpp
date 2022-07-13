//g++ filename.cpp -std=c++14 -DH
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
 
typedef long long ll; typedef vector<int> vi;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
const int maxN = 1e5+1;

ll a[maxN];
bool b[maxN];
ll sum = 0;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("filename.in"); ofstream fout("filename.out");
	int n, k; cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++){
		cin >> b[i]; if(b[i]) sum += a[i];
	}
	ll res = 0;
	for(int i = 0; i < k; i++){
		if(!b[i]) res += a[i];
	}
	ll cur = res;
	for(int i = k; i < n; i++){
		if(!b[i]) cur += a[i];
		if(!b[i-k]) cur -= a[i-k];
		res = max(res, cur); 
	}
	cout << sum + res << endl;
	
}