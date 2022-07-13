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
const int maxN = 250;
int N, grid[maxN][maxN], mx = 0;
bool s[maxN][maxN];
vector<pair<int,pi>> pos;
int dx[]={ 0, 0,+1,-1};
int dy[]={+1,-1, 0, 0};
bool valid(int x, int y, int a, int b){
	if(x >= N || y >= N || x < 0 || y < 0) return false;
	if(a != grid[x][y] && b != grid[x][y]) return false;
	if(s[x][y]) return false;
	else s[x][y] = 1;
	return true;
}
int bfs(int x, int y, int a, int b){
	queue<pi> q;
	q.push({x,y});
	s[x][y] = 1;
	int SZ = 0;
	while(!q.empty()){
		pi ft = q.front(); q.pop();
		SZ++; 
		// cout << ft.f << " " << ft.s << endl;
		for(int i = 0; i < 4; i++){
			if(valid(ft.f+dx[i],ft.s+dy[i],a,b)){
				q.push({ft.f+dx[i],ft.s+dy[i]});
			}
			
		}
	}
	// cout << "NEXT" << endl << endl << endl;
	memset(s, 0, sizeof s);
	return SZ;

}
void fill(pair<int,pi> u, pair<int,pi> v){
	//allowed teams
	int a = u.f, b = v.f;
	//coords
	int x1 = u.s.f, y1 = u.s.s;
	int x2 = v.s.f, y2 = v.s.s;
	mx = max(mx, bfs(x1,y1,a,b));
	if(x2 != -1) mx = max(mx, bfs(x2,y2,a,b));
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("multimoo.in"); ofstream fout("multimoo.out");
	fin >> N;
	for(int i = 0; i < N; i++){
		for(int i2 = 0; i2 < N; i2++){
			fin >> grid[i][i2];
			pos.pb({grid[i][i2], {i,i2}});
		}
	}
	for(auto a: pos){
		fill(a,{-1,{-1,-1}});
	}
	int mxi = mx;
	mx = 0;
	for(int i = 0; i < pos.size(); i++){
		for(int j = i+1; j < pos.size(); j++){
			fill(pos[i],pos[j]);
		}
	}
	fout << mxi << endl << mx << endl;
	// for(int j = 1; j <= N; j++){
	// 	for(int i = 1; i <= N; i++){
	// 		cout << grid[j][i] << " ";
	// 	}
	// 	cout << endl;
	// }
}