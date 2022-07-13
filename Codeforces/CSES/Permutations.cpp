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
const int maxN = 1e6;

int N;
deque<int> q = {3,1,4,2};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("filename.in"); ofstream fout("filename.out");
	cin >> N;
	if(N == 1) cout << 1 << endl;
	else if(N <= 3) cout << "NO SOLUTION" << endl;
	else{
		for(int i = 4; i < N; i++){
			if(i % 2 == 0) q.pb(i+1);
			else q.push_front(i+1);
		}
		for(auto a: q) cout << a << " ";
	}

	
}