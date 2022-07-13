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
#define heap priority_queue<int>
#define vi vector<int>



typedef long long ll;
typedef pair<int, string> pis;
typedef pair<ll,ll> pii;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("teleport.in");
	ofstream fout("teleport.out");
	int N;
	fin >> N;
	vector<pii> piles;
	vector<ll> med;
	ll minSum = 999999999999999999;
	for(int i = 0; i < N; i++){
		ll a, b;
		fin >> a >> b;
		piles.pb({a, b});
		// cout << abs(b-a) << " " << abs(a) << endl;
		if(abs(a-b) > abs(a)){
			med.pb(b);
		}
	}
	
	for(auto median: med){
		ll sum = 0;
		for(int i = 0; i < piles.size(); i++){
			int a = piles[i].f, b = piles[i].s;
			ll direct = abs(a-b);
			// cout << direct << " " << abs(a) + abs((median - b)) << endl;
			if(direct < abs(a) + abs((median - b))){
				sum += direct;
			}
			else{
				sum += abs(a) + abs((median - b));
			}

		}
		minSum = min(minSum, sum);
	}
	// cout << sum << endl;
	fout << minSum << endl;
}