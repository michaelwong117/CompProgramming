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
const int maxN = 1000;
int seen[maxN][maxN], n, m, firSeen = 1, trap = 0;
char grid[maxN][maxN];

void dfs(int r,int c){
	if(!seen[r][c]) seen[r][c] = firSeen;
	else{
		if(seen[r][c] == firSeen) return;
		else{
			trap--;
			return;
		}
	}
	if(grid[r][c] == 'N') dfs(r-1,c);
	if(grid[r][c] == 'E') dfs(r,c+1);
	if(grid[r][c] == 'S') dfs(r+1,c);
	if(grid[r][c] == 'W') dfs(r,c-1);

}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int i2 = 0; i2 < m; i2++) grid[i][i2] = s[i2];
	}
	for(int i = 0; i < n; i++){
		for(int i2 = 0; i2 < m; i2++){
			if(!seen[i][i2]){
				dfs(i,i2);
				firSeen++;
				trap++;
			}
		}
	}
	cout << trap << endl;	
}