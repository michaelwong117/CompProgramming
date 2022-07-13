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
const int maxN = 2*1e5;
int n, mx = 0;
vi v;
unordered_set<int> s;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("filename.in"); ofstream fout("filename.out");
	cin >> n;
	v.resize(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i < n; i++){
		while(s.find(v[i]) != s.end()){
			s.erase(v[i-s.size()]);
		}
		s.insert(v[i]);
		if(s.size() > mx) mx = s.size();
	}
	cout << mx << endl;
}