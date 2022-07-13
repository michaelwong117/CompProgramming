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

vector<vector<bool>> seenCoord(20, vector<bool>(20));
vector<string> rows, cols;

bool valid(pii start, pii finish){
	
	//if it's out of bounds

	if(finish.fir < 1 || finish.fir > N){
		return false;
	}
	if(finish.sec < 1 || finish.sec > N){
		return false;
	}

	if(seenCoord[finish.fir][finish.sec]){
		return false;
	}
	seenCoord[finish.fir][finish.sec] = 1;
	return true;
}

void bfs(pii cow, int group){
	queue<pii> q;
	q.push(cow);
	//initialize the group of cows
	seen[group] = 1;
	//mark initial as seen
	seenCoord[cow.fir][cow.sec] = 1;
	while(!q.empty()){
		pii f = q.front();
		q.pop();
		//if you aren't looking at the saem cow
		if(f != cow){
			//if you find a cow
			if(lookup[f.fir][f.sec] == 1){
				lookup[f.fir][f.sec] = 0;
				//increment the size of the group
				seen[group]++;
			}	
		}
		if(valid(f, pii(f.fir+1, f.sec))){
			q.push(pii(f.fir+1, f.sec));
		}
		if(valid(f, pii(f.fir, f.sec+1))){
			q.push(pii(f.fir, f.sec+1));
		}
		if(valid(f, pii(f.fir-1, f.sec))){
			q.push(pii(f.fir-1, f.sec));
		}
		if(valid(f, pii(f.fir, f.sec-1))){
			q.push(pii(f.fir, f.sec-1));
		}
	}
	
}

bool PCL(int i, int j, int k, int l){
	// cout << i << " " << j << " " << k << " " << l << endl;
	bfs(pii(i, j));
	for(int a = i; a <= j; a++){
		for(int b = k; b <= l; b++){

			// cout << rows[a][b];
		}
		// cout << endl;
	}
	return true;
}




int main(){
	ifstream fin("where.in");
	ofstream fout("where.out");
	int N;
	fin >> N;
	cols.resize(N, "");
	for(int i = 0; i < N; i++){
		string a;
		fin >> a;
		rows.push_back(a);
		for(int i = 0; i < a.length(); i++){
			cols[i] += a[i];
		}
	}
	int count = 0;
	for(int i = 0; i < rows.size(); i++){
		for(int j = rows.size()-1; j >= i; j--){
			for(int k = 0; k < rows.size(); k++){
				for(int l = rows.size()-1; l >= k; l--){
					if(PCL(i,j,k,l)){
						count++;
						fout << count << endl;
						return 0;
					}
				}
			}
		}
	}	




	
}