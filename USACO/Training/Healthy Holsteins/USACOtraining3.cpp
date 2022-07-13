/*
ID: michaelwong11
PROG: holstein
LANG: C++14     
*/
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

using namespace std;

typedef pair<int,int> pii;

vector<int> minV, bags, base;
vector<vector<int>> feed;
vector<bool> a;
int V, G;
set<vector<int>> subset;
void generateSubsets(vector<int> &v, int low, int high){
	if(low > high){
		vector<int> s;
		for(int i = 0; i < a.size(); i++){
			if(a[i]) s.push_back(i);
		}
		subset.insert(s);
	}
	else{
		a[low] = 1;
		generateSubsets(v, low+1, high);
		a[low] = 0;
		generateSubsets(v, low+1, high);
	}
}

int main(){
	ifstream fin("holstein.in");
	ofstream fout("holstein.out");
	fin >> V;
	minV.resize(V);
	for(int i = 0; i < V; i++){
		//each index represents one type of vitamin
		fin >> minV[i];
	}
	fin >> G;
	feed.resize(G);
	a.resize(G); 
	for(int i = 0; i < G; i++){
		base.push_back(i);
		for(int j = 0; j < V; j++){
			int f;
			fin >> f;
			feed[i].push_back(f);
		}
	}
	generateSubsets(base, 0, G);
	vector<int> final (16);
	for(auto s: subset){
		vector<int> copy = minV;
		vector<bool> marked (25, 0);
		int done = 0;
		for(auto j: s){
			for(int k = 0; k < feed[j].size(); k++){
				// cout << copy[k] << " " << feed[j][k] << " " << marked[k] << endl;
				copy[k] -= feed[j][k];
				if(copy[k] <= 0 && !marked[k]){
					done++;
					marked[k] = 1;
				}
			}	
		}
		// cout << done << " " << V << endl;
		// cout << endl;
		// for(auto a: copy) cout << a << " ";
		// cout << endl;
		if(done == V){
			if(final.size() > s.size()){
				final = s;
			}
			else if (final.size() == s.size()){
				for(int l = 0; l < final.size(); l++){
					if(final[l] > s[l]) final = s; break;
				}
			}
		}
	}
	fout << final.size() << " ";
	for(int i = 0; i < final.size()-1; i++){
		fout << final[i]+1 << " ";
	}
	fout << final[final.size()-1]+1 << endl;
}	
