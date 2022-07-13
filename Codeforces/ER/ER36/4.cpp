#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <iostream>

#define ll long long
#define fir first
#define sec second


using namespace std;

typedef pair<int, string> pis;
typedef pair<int,int> pii;

//set tab size to 3

bool cycle = 0, firstCycle = 1;
map<int, int> visited;
vector<bool> seenCoord(501);
vector<int> Time(501);
vector<pii> omit;
int o1 = -1, o2 = -1;

void dfsCycle(vector<vector<int>> & adj, vector<int> &adjS, int s, int curTime){;
	for(int i = 0; i < adjS.size(); i++){
		if(cycle == 1){
			break;
		}
		Time[adjS[i]] = curTime + 1;
		if(o1 == adjS[i] && o2 == s){
			cout << "omitting " << o1 << " " << o2 << endl;
			continue;
		}
		if(seenCoord[adjS[i]] == 0){
			visited[adjS[i]] = s;
			seenCoord[adjS[i]] = 1;
			dfsCycle(adj, adj[adjS[i]], adjS[i], Time[adjS[i]]);
		}
		// if(seenCoord[adjS[i]] != 0){
		// 	cout << Time[s] << " " << Time[adjS[i]] << " " << s << " " << adjS[i] << endl;
		// }
		// else if (visited.find(adjS[i]) != visited.end()){
		// 	cout << Time[s] << " " << Time[adjS[i]] << " " << s << " " << adjS[i] << endl;
		// }
		else if(visited.find(adjS[i]) != visited.end() && Time[s] < Time[adjS[i]]){
			cout << Time[s] << " " << Time[adjS[i]] << " " << s << " " << adjS[i] << endl;
			if(firstCycle){
				for(auto x: visited){
					// cout << x.fir << " " << x.sec << endl;
					omit.push_back(pii(x.fir, x.sec));
				}
				omit.push_back(pii(adjS[i], s));
				// cout << "cycle found " << adjS[i] << " " << s << endl;
				firstCycle = 0;
			}
			// for(auto x: visited){
			// 	cout << x.fir << " " << x.sec << endl;
			// }
			// cout << "cycle found " << adjS[i] << " " << s << endl;
			cycle = 1;
			break;
		}
	}
}
void isCycle(vector<vector<int>> & adj){
	cycle = 0;
	for(int i = 0; i < adj.size(); i++){
		if(!adj[i].empty()){
			if(seenCoord[i] == 0){
				seenCoord[i] = 1;
				visited[i] = -1;
				Time[i] = 1;
				dfsCycle(adj, adj[i], i, Time[i]);
				visited.clear();
				Time.clear();
				Time.resize(501);
				if(cycle == 1){
					break;
				}

			}
		}
	}
	seenCoord.clear();
	seenCoord.resize(501);

		
		
}

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	int n, m;
	fin >> n >> m;
	vector<vector<int>> adj (n+1);
	for(int i = 0; i < m; i++){
		int u, v;
		fin >> u >> v;
		adj[u].push_back(v);
	}
	isCycle(adj);
	if(cycle == 0){
		cout << "YES" << endl;
		return 0;
	}
	for(int i = 0; i < omit.size(); i++){
		o1 = omit[i].fir;
		o2 = omit[i].sec;
		isCycle(adj);
		if(!cycle){
			// cout << o1 << " " << o2 << endl;
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;




}