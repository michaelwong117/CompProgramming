//g++ filename.cpp -std=c++14 -DH
#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define endl '\n'
#define pb push_back
#define fir first
#define sec second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define pq priority_queue

typedef long long ll;
typedef pair<int, string> pis;
typedef pair<int,int> pii;

int N;

vector<pii> cows;
int maxN = 20;
vector<vector<bool>> haybale(maxN, vector<bool> (maxN));
vector<vector<bool>> seen(maxN, vector<bool> (maxN));
int mDist = 999999999;
vector<vector<pii>> tries;

bool valid(pii finish){

	if(finish.fir < 1 || finish.fir > N){
		return false;
	}
	if(finish.sec < 1 || finish.sec > N){
		return false;
	}
	if(seen[finish.fir][finish.sec]){
		return false;
	}
	if(haybale[finish.fir][finish.sec]){
		return false;
	}
	return true;
}
void dfs(pii f, int dir, int d, vector<pii> &v){
	if(!valid(f)) return;
	seen[f.fir][f.sec] = 1;
	if(f.fir == N && f.sec == N){
		// tries.pb(v);
		cout << d << endl;
		return;
	}
	int cd1, cd2,cd3,cd4;
	if(dir == 1){
		cd1 = 0;
		cd2 = 1;
		cd3 = 2;
		cd4 = 1;
	}
	if(dir == 2){
		cd1 = 1;
		cd2 = 0;
		cd3 = 1;
		cd4 = 2;
	}
	if(dir == 3){
		cd1 = 2;
		cd2 = 1;
		cd3 = 0;
		cd4 = 1;
	}
	if(dir == 4){
		cd1 = 1;
		cd2 = 2;
		cd3 = 1;
		cd4 = 0;
	}
	dfs(pii(f.fir+1, f.sec), 1, d+1+cd1, v);
	dfs(pii(f.fir, f.sec+1), 2, d+1+cd2, v);
	dfs(pii(f.fir-1, f.sec), 3, d+1+cd3, v);
	dfs(pii(f.fir, f.sec-1), 4, d+1+cd4, v);

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("cownav.in");
	ofstream fout("cownav.out");
	fin >> N;
	for(int i = 1; i <= N; i++){
		string s;
		fin >> s;
		for(int j = 1; j <= N; j++){
			if(s[j-1] == 'H') haybale[i][j] = 1;
		}
	}
	vector<pii> t;
	dfs({1, 1}, 1, 0, t);
	int Up = mDist;
	mDist = 999999999;

	
}
