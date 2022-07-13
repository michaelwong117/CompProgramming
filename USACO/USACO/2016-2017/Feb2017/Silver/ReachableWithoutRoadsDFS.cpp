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

typedef pair<int,int> pii;

int N, K, R;
vector<pii> cows;
map<pii, pii> parent, roads;
vector<vector<bool>> lookup(200, vector<bool>(200)), roadRow(200, vector<bool>(200)), roadCol(200, vector<bool>(200));
vector<int> seen (200);

//roadRow is always in increasing order (0,0 -> 0,1) is represented as 0,0
//same with road Col (0,0 -> 1,0) is represented as 0,0


bool valid(pii start, pii finish){

	if(finish.fir < 1 || finish.fir > N){
		return false;
	}
	if(finish.sec < 1 || finish.sec > N){
		return false;
	}
	if(parent.find(finish) != parent.end()){
		return false;
	}
	//columns are changing
	if(start.fir == finish.fir){
		//col decreasing
		if(start.sec > finish.sec){
			if(roadCol[start.fir][start.sec-1] == 1){
				return false;
			}
		}
		//col increasing
		else{
			if(roadCol[start.fir][start.sec] == 1){
				return false;
			}
		}
		
	}
	//rows are changing
	else{
		//row decreasing
		if(start.fir > finish.fir){
			if(roadRow[start.fir-1][start.sec] == 1){
				return false;
			}
		}
		//row increasing
		else{
			if(roadRow[start.fir][start.sec] == 1){
				return false;
			}
		}
	}
	parent[finish] = start;
	return true;
}

void dfs(pii f, int group){
	if(lookup[f.fir][f.sec] == 1 && f != cows[group-1]){
		lookup[f.fir][f.sec] = 0;
		seen[group]++;
	}
	if(valid(f, pii(f.fir+1, f.sec))){
		dfs(pii(f.fir+1, f.sec), group);
	}
	
	if(valid(f, pii(f.fir, f.sec+1))){
		dfs(pii(f.fir, f.sec+1), group);
	}
	if(valid(f, pii(f.fir-1, f.sec))){
		dfs(pii(f.fir-1, f.sec), group);
	}
	if(valid(f, pii(f.fir, f.sec-1))){
		dfs(pii(f.fir, f.sec-1), group);
	}

}
int main(){
  ifstream fin ("countcross.in");
  ofstream fout ("countcross.out");
  fin >> N >> K >> R;
  int tot = 0;
  for(int i = 0; i < R; i++){
  	int r1, c1, r2, c2;
  	fin >> r1 >> c1 >> r2 >> c2;
  	if(r1 == r2){
  		if(c1 > c2){
  			roadCol[r1][c1-1] = 1;
  		}
  		else{
  			roadCol[r1][c1] = 1;
  		}
  	}
  	else{
  		if(r1 > r2){
  			roadRow[r1-1][c1] = 1;
  		}
  		else{
  			roadRow[r1][c1] = 1;
  		}
  	}


  	//indicates road between field at r1,c1 and r2, c2

  }
  for(int i = 0; i < K; i++){
  	int r, c;
  	fin >> r >> c;
  	cows.push_back(pii(r, c));
  	lookup[r][c] = 1;
  }

  for(int i = 0; i < cows.size(); i++){
  		if(lookup[cows[i].fir][cows[i].sec] == 1){
  			seen[i+1] = 1;
  			parent[cows[i]] = pii(-1, -1);
  			dfs(cows[i], i+1);
  		}

  }
  
  vector<int> groups;
  for(int i = 0; i < seen.size(); i++){
  		if(seen[i] != 0){
  			groups.push_back(seen[i]);
  		}
  		
  }
  for(int i = 0; i < groups.size()-1; i++){
  	int sum = 0;
  	for(int j = i+1; j < groups.size(); j++){
  		sum += groups[j];
  	}
  	tot += groups[i] * sum;
  }
  //use prefix sums to find tot amount of cows that can't 
  //reach each other
  fout << tot << endl;

  //run a dfs to see if there is any way for the cow to cross
  //without crossing road
  //each cow is a node
  //if there is a path from one cow to another such that
  //you do not have to pass a road, it is not distant


}