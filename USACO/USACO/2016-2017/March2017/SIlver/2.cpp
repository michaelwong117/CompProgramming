#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <unordered_set>

#define ll long long

using namespace std;


int main(){

	ifstream fin("cownomics.in");
	ofstream fout("cownomics.out");
	int N, M;
	fin >> N >> M;
	vector<string> norm, spot, coln, colspot;
	vector<vector<int>> v (M);
	set<int> checked;
	int sum = 0;
	for(int i = 0; i < N; i++){
		string s;
		fin >> s;
		spot.push_back(s);
	}
	for(int i = 0; i < N; i++){
		string s;
		fin >> s;
		norm.push_back(s);
	}
	for(int i = 0; i < M; i++){
		string cn = "", cp = "";
		for(int j = 0; j < N; j++){
			cn += norm[j][i];
			cp += spot[j][i];
			// cout << norm[j][i] << " " << spot[j][i] << endl;
		}
		// cout << endl;
		coln.push_back(cn);
		colspot.push_back(cp);

	}
	for(int i = 0; i < M; i++){
		// cout << coln[i] << " " << colspot[i] << endl;
		for(int j = 0; j < N; j++){
			if(coln[i][j] != colspot[i][j]){
				v[i].push_back(j);
			}
		}

	}
	for(int i = 0; i < v.size()-2; i++){
		for(int j = i+1; j < v.size()-1; j++){
			for(int k = j+1; k < v.size(); k++){
				// cout << i << " " << j << " " << k << endl;
				// cout << v[i].size() << " " << v[j].size() << " " << v[k].size() << endl;
				if(checked.find(16*i + 4*j + k) != checked.end()) continue;
				checked.insert(16*i + 4*j + k);
				if(v[i].size() == N || v[j].size() == N || v[k].size() == N) sum++;
				//if empty means all in that column were the same
				else{
					unordered_set<int> s(v[i].begin(), v[i].end());
					copy(v[j].begin(), v[j].end(), inserter(s, s.end()));
					copy(v[k].begin(), v[k].end(), inserter(s, s.end()));
					if(s.size() == M){
						sum++;
					}
				}
				



			}
		}

	}
	fout << sum << endl;
	
	


}