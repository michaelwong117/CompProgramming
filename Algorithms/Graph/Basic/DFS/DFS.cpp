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


//for adjacency lists 
//recursively visit from node s

map<int, int> m;
//nodes 0, 1, 2...5, 6
vector<vector<int>> adj = {{}, {2, 4, 6}, {1, 5}, {5}, {1}, {2, 3}, {1}};

void dfsVisit(vector<int> &adjS, int s){
	for(int i = 0; i < adjS.size(); i++){
		if(m.find(adjS[i]) == m.end()){
			m[adjS[i]] = s;
			dfsVisit(adj[adjS[i]], adjS[i]);
		}
	}
}

//finds all the strongly connected components
void DFS(){
	for(int i = 0; i < adj.size(); i++){
		if(m.find(i) == m.end()){
			//mark node as seen
			m[i] = -1;
			// cout << "Visited " << i << endl;
			dfsVisit(adj[i], i);
		}
	}
}

int main(){
	DFS(adj);
}