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
int n, c = 1;
vi v;
multiset<int> s;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("filename.in"); ofstream fout("filename.out");
	cin >> n;
	v.resize(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i < n; i++){
		if(!s.empty()){
			auto it = s.ub(v[i]);
			// cout << v[i] << " " << *it << endl;
			if(it == s.end()) c++;
			else s.erase(it);
		}
		s.insert(v[i]);
	}
	cout << c << endl;
}