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
 
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
const int mx = 1e6;
int N, M, K;
ll ok[mx+1], bad[mx+1], tot = 1;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("spainting.in"); ofstream fout("spainting.out");
	fin >> N >> M >> K;
	// index i stores how many combos are ok or bad of length i.
	bad[0] = 1;
	// up to k-1 all solutions are bad.
	for(int i = 1; i < K; i++) {
		bad[i] = (bad[i-1]*M)%MOD;
		tot = (tot*M)%MOD;
	}
	tot = (tot*M)%MOD;
	ok[K] = M;
	bad[K] = (tot-M+MOD)%MOD;
	for(int i = K+1; i <= N; i++) {
		// all old okay streaks can continue in m ways.
		// bad streaks of length i-k can be made good in m-1 ways (all but the last color...)
		ok[i] = ((ok[i-1]*M)%MOD + (bad[i-K]*(M-1))%MOD)%MOD;
		// update and recalculating bad is easy - whole minus ok.
		tot = (tot*M)%MOD;
		bad[i] = (tot - ok[i] + MOD)%MOD;
	}

	fout << ok[N] << endl;
}