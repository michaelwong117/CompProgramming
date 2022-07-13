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

bool valid(pii start, pii finish){

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
	cout << f.fir << " " << f.sec << " " << dir << " " << d << endl;
	seen[f.fir][f.sec] = 1;
	if(f.fir == N && f.sec == N){
		tries.pb(v);
		return;
	}
	if(valid(f, pii(f.fir+1, f.sec)) && dir == 1){
		//point now at, dir, distance, moved one in pair.fir, now at pair.sec dir
		v.pb({1, 1});
		dfs(pii(f.fir+1, f.sec), 1, d+1, v);
		v.pop_back();
		v.pb({1, 2});
		dfs(pii(f.fir+1, f.sec), 2, d+2, v);
		v.pop_back();
		v.pb({1, 4});
		dfs(pii(f.fir+1, f.sec), 4, d+2, v);
	}
	
	if(valid(f, pii(f.fir, f.sec+1)) && dir == 2){
		v.pb({2, 2});
		dfs(pii(f.fir, f.sec+1), 2, d+1, v);
		v.pop_back();
		v.pb({2, 3});
		dfs(pii(f.fir, f.sec+1), 3, d+2, v);
		v.pop_back();
		v.pb({2, 1});
		dfs(pii(f.fir, f.sec+1), 1, d+2, v);
	}
	if(valid(f, pii(f.fir-1, f.sec)) && dir == 3){
		v.pb({3, 3});
		dfs(pii(f.fir-1, f.sec), 3, d+1, v);
		v.pop_back();
		v.pb({3, 4});
		dfs(pii(f.fir-1, f.sec), 4, d+2, v);
		v.pop_back();
		v.pb({3, 2});
		dfs(pii(f.fir-1, f.sec), 2, d+2, v);
	}
	if(valid(f, pii(f.fir, f.sec-1)) && dir == 4){
		v.pb({4, 4});
		dfs(pii(f.fir, f.sec-1), 4, d+1, v);
		v.pop_back();
		v.pb({4, 1});
		dfs(pii(f.fir, f.sec-1), 1, d+2, v);
		v.pop_back();
		v.pb({4, 3});
		dfs(pii(f.fir, f.sec-1), 3, d+2, v);
	}
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
	for(auto a: tries){
		int dir = 2, dist = 0;
		pii start = {1, 1};
		for(int i = 0; i < a.size(); i++){
			// cout << a[i].fir << " " << a[i].sec << "  ";
			if(start.fir == N && start.sec == N){
				mDist = min(mDist, dist);
				break;
			}
			dist++;
			if(a[i].fir == a[i].sec || dir == a[i].sec){
				if(dir == 1){
					start.fir++;
				}
				if(dir == 2){
					start.sec++;
				}
				if(dir == 3){
					start.fir--;
				}
				if(dir == 4){
					start.sec--;
				}
			}
			else{
				if(a[i].fir == 1){
					if(a[i].sec == 4){
						dir = 4;
					}
					if(a[i].sec == 2){
						dir = 2;
					}
				}
				if(a[i].fir == 2){
					if(a[i].sec == 3){
						dir = 3;
					}
					if(a[i].sec == 1){
						dir = 1;
					}
				}
				if(a[i].fir == 3){
					if(a[i].sec == 4){
						dir = 4;
					}
					if(a[i].sec == 2){
						dir = 2;	
					}
				}
				if(a[i].fir == 4){
					if(a[i].sec == 1){
						dir = 1;
					}
					if(a[i].sec == 3){
						dir = 3;	
					}
				}
				i--;
			}
			//moved in direction a[i].fir
			//now facing direction a[i].sec

		}
		// cout << endl;
	}

	
}
