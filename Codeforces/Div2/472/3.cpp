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


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("filename.in"); ofstream fout("filename.out");
	int n; cin >> n;
	if(n <= 5) cout << -1 << endl;
	else{
		 cout << "1 2\n1 3\n1 4\n2 5\n2 6" << endl;
		 for(int i = 7; i <= n; i++){
		 	cout << "2 " << i << endl;
		 }
	}
	for(int i = 2; i <= n; i++){
		cout << 1 << " " << i << endl;
	}
}