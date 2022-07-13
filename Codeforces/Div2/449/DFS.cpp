#include <iostream>
#include <vector>
#include <map>

using namespace std;



map<int, int> m;
//recursively visit from node s
vector<vector<int>> adj;

void dfsVisit(vector<int> adjS){
	for(int i = 0; i < adjS.size(); i++){
		if(m.find(adjS[i]) == m.end()){
			m[adjS[i]] = s;
			dfsVisit(adj[i]);
		}
	}
}

//finds all the strongly connected components
void DFS(vector<vector<int>> adj){
	map<int, int> m;
	for(int i = 0; i < adj.size(); i++){
		if(m.find(i) == m.end()){
			m[i] = -1;
			dfsVisit(adj[i]);
		}
	}
}