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
const int maxN = 20;

bool valid(pi p){
	if(p.f < 1 || p.f  > N){
		return false;
	}
	if(p.s < 1 || p.s > N){
		return false;
	}
	if(seenCoord[finish.fir][finish.sec]){
		return false;
	}
}

int N, dp[maxN][maxN][4][maxN][maxN][4], hb[maxN][maxN], dx[]={0, 0, 1,-1}, dy[]={1,-1, 0, 0};
void bfs(int x, int y){
	queue<pi> q;
	q.push({x,y});
	while(!q.empty()){
		int fr = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int nx = x+dx[i], ny = y+dy[i];
			if(valid(nx,ny)) q.push({nx,ny});
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("cownav.in");
	ofstream fout("cownav.out");
	fin >> N;
	for(int i = 1; i <= N; i++){
		string s;
		fin >> s;
		for(int j = 1; j <= N; j++){
			if(s[j-1] == 'H') hb[i][j] = 1;
		}
	}



	
}
