#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

#define ll long long
#define fir first
#define sec second


using namespace std;

typedef pair<int, string> pis;
typedef pair<int,int> pii;

//set tab size to 3

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("shuffle.in");
	ofstream fout("shuffle.out");
	int N, sum = 0;
	fin >> N;
	vector<int> cows (N+1);
	vector<vector<int>> adj (N+1);
	for(int i = 1; i <= N; i++){
		fin >> cows[i];
		if(adj[cows[i]].empty()){
			adj[i] = {cows[i]};
		}
		else{
			adj[i].push_back(cows[i]);
		}
	}
	queue<int> q;
	for(int i = 1; i <= adj.size(); i++){
		if(adj[i].empty()){
			q.push(i);
		}
	}
	while(!q.empty()){
		int f = q.front();
		q.pop();
		for(int i = 0; i < adj.size(); i++){
			if(adj)
		}

	}
	fout << sum << endl;
	
}