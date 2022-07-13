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
map<pii, pii> parent;
vector<vector<bool>> lookup(200, vector<bool>(200));
vector<int> seen (200);
vector<vector<pii>> roads;

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
	// cout << start.fir << " " << start.sec << " "
	//  << finish.fir << " " << finish.sec << endl;

	//columns are changing
	for(auto r: roads){
		if(r[0] == start && r[1] == finish){
			return false;
		}
	}
	parent[finish] = start;
	return true;
}

void bfs(pii cow, int group){
	queue<pii> q;
	q.push(cow);
	seen[group] = 1;
	// cout << cow.fir << " " << cow.sec << " " << seen[group] << endl;
	parent[cow] = pii(-1, -1);
	while(!q.empty()){
		// cout << q.size() << endl;
		pii f = q.front();
		q.pop();
		if(f != cow){
			if(lookup[f.fir][f.sec] == 1){
				// cout << f.fir << " " << f.sec << endl;
				lookup[f.fir][f.sec] = 0;
				seen[group]++;
			}	
		}
		// cout << f.fir+1 << " " << f.sec << endl;
		// cout << valid(f, pii(f.fir+1, f.sec)) << endl;
		if(valid(f, pii(f.fir+1, f.sec))){
			// cout << f.fir+1 << " " << f.sec << endl;
			q.push(pii(f.fir+1, f.sec));
		}
		// cout << f.fir << " " << f.sec+1 << endl;
		// cout << valid(f, pii(f.fir, f.sec+1)) << endl;
		if(valid(f, pii(f.fir, f.sec+1))){
			// cout << f.fir << " " << f.sec+1 << endl;
			q.push(pii(f.fir, f.sec+1));
		}
		// cout << f.fir-1 << " " << f.sec << endl;
		// cout << valid(f, pii(f.fir-1, f.sec)) << endl;
		if(valid(f, pii(f.fir-1, f.sec))){
			// cout << f.fir-1 << " " << f.sec << endl;
			q.push(pii(f.fir-1, f.sec));
		}
		// cout << f.fir << " " << f.sec-1 << endl;
		// cout << valid(f, pii(f.fir, f.sec-1)) << endl;
		if(valid(f, pii(f.fir, f.sec-1))){
			// cout << f.fir << " " << f.sec-1 << endl;
			q.push(pii(f.fir, f.sec-1));
		}
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
  	roads.push_back({pii(r1, c1), pii(r2, c2)});
  	roads.push_back({pii(r2, c2), pii(r1, c1)});

  	// cout << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
  	// cout << r2 << " " << c2 << " " << r1 << " " << c1 << endl;

  	//indicates road between field at r1,c1 and r2, c2

  }
  // for(auto x: roads){
  // 	cout << "inmap " << x.fir.fir << " " << x.fir.sec << " " << x.sec.fir << " " << x.sec.sec << endl;
  // }
  for(int i = 0; i < K; i++){
  	int r, c;
  	fin >> r >> c;
  	cows.push_back(pii(r, c));
  	lookup[r][c] = 1;
  }

  for(int i = 0; i < cows.size()-1; i++){
  		if(lookup[cows[i].fir][cows[i].sec] == 1){
  			// cout << cows[i].fir << " " << cows[i].sec << endl;
  			bfs(cows[i], i+1);
  		}

  }
  
  vector<int> groups;
  for(int i = 0; i < seen.size(); i++){
  		if(seen[i] != 0){
  			// cout << seen[i] << endl;
  			groups.push_back(seen[i]);
  		}
  		
  }
  for(int i = 0; i < groups.size()-1; i++){
  	int sum = 0;
  	for(int j = i+1; j < groups.size(); j++){
  		sum += groups[j];
  		// cout << groups[j] << " " << groups[i] << endl;
  	}
  	tot += groups[i] * sum;
  }
  fout << tot << endl;

  // fout << c << endl;
  //run a bfs to see if there is any way for the cow to cross
  //without crossing road
  //each cow is a node
  //if there is a path from one cow to another such that
  //you do not have to pass a road, it is not distant


}