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
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<ll,ll> pl;
typedef vector<array<int,3>> multiv;

const int maxN = 1e6+1;

int N, a[maxN], dp[maxN][2][3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("hps.in");
	ofstream fout("hps.out");
	fin >> N;
	for(int i = 0; i < N; i++){
		char c;
		fin >> c;
		if(c == 'P') a[i] = 1;
		if(c == 'S') a[i] = 2;
	}
	for(int i = 1; i <= N; i++){
		for(int k = 0; k <= 1; k++){
			for(int st = 0; st < 3; st++){
				if(k == 0){
					dp[i][k][st] = dp[i-1][k][st];
				}
				else{
					int stx = (st+1)%3, sty = (st+2)%3;
					dp[i][k][st] = max(max(dp[i-1][k][st], dp[i-1][k-1][stx]), 
						dp[i-1][k-1][sty]);
				}
				if(a[i-1] == st) dp[i][k][st]++;
			}
		}
	}	
	fout << max(max(dp[N][1][0], dp[N][1][1]), dp[N][1][2]);

	
}