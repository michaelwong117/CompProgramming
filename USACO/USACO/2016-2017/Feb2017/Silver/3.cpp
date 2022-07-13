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

//2 seconds runtimew
//256 megabytes
//X - incorrect, T - time limit, ! - runtime or memory
//E = empty output file, M - missing output file
//make sure that you have correct finder/terminal directories


vector<vector<int>> cows;
set<int> storedCoords;
map<int, int> parent, roads;
int N, K, R;
vector<bool> F (K, 0);

bool isValid(int i, int s, int f){
	//one is down, two is right, three is up, four is left
	if(i < 1 || i > N){
		return false;
	}
	if(roads.find(s) != roads.end()){
		if(roads[s] == f){
			return false;
		}
	}

	return true;
}

bool bfs(vector<int> &s){
	queue<vector<int>> q;
	q.push(s);
	parent[s[0] * 100000 + s[1]] = -1;
	// int i = 0;
	while(!q.empty()){
		vector<int> f = q.front();
		q.pop();
		int front = f[0]*100000 + f[1];
		if(isValid(f[0]+1, front, (f[0]+1) * 100000 + f[1])){
			if(parent.find((f[0]+1) * 100000 + f[1]) == parent.end()){
				q.push({f[0]+1, f[1]});
				parent[(f[0]+1) * 100000 + f[1]] = front;
				set<int>::iterator it = storedCoords.find((f[0]+1) * 100000 + f[1]);
				if(it != storedCoords.end()){
					if(F[it-storedCoords.begin()] == 0){
						F[it-storedCoords.begin()] = 1;
					}
					

				}

			}
			
		}
		if(isValid(f[1]+1, front, (f[0]) * 100000 + f[1]+1)){
			if(parent.find(f[0] * 100000 + f[1]+1) == parent.end()){
				q.push({f[0], f[1]+1});
				parent[f[0] * 100000 + f[1]+1] = front;
				set<int>::iterator it = storedCoords.find((f[0]) * 100000 + f[1]+1);
				if(it != storedCoords.end()){
					if(F[it-storedCoords.begin()] == 0){
						F[it-storedCoords.begin()] = 1;
					}
				}
				
			}
		}
		if(isValid(f[0]-1, front, (f[0]-1) * 100000 + f[1])){
			if(parent.find((f[0]-1)* 100000 + f[1]) == parent.end()){
				q.push({f[0]-1, f[1]});	
				parent[(f[0]-1) * 100000 + f[1]] = front;
				set<int>::iterator it = storedCoords.find((f[0]-1) * 100000 + f[1]);
				if(it != storedCoords.end()){
					if(F[it-storedCoords.begin()] == 0){
						F[it-storedCoords.begin()] = 1;
					}
				}
			}
			
		}
		if(isValid(f[1]-1, front, (f[0]) * 100000 + f[1]-1)){
			if(parent.find(f[0] * 100000 + f[1]-1) == parent.end()){
				q.push({f[0], f[1]-1});		
				parent[(f[0]) * 100000 + f[1]-1] = front;
				set<int>::iterator it = storedCoords.find((f[0]) * 100000 + f[1]-1);
				if(it != storedCoords.end()){
					if(F[it-storedCoords.begin()] == 0){
						F[it-storedCoords.begin()] = 1;
					}
				}
			}
			
		}
		// i++;
		// cout << "finished "  << i << endl;
		
	} 
	return true;
	

}
 


int main(){
  ifstream fin ("countcross.in");
  ofstream fout ("countcross.out");
  fin >> N >> K >> R;
  int c = 0;
  for(int i = 0; i < R; i++){
  	int r1, c1, r2, c2;
  	fin >> r1 >> c1 >> r2 >> c2;
  	roads[r1*100000+c1] = r2*100000+c2;
  	//indicates road between field at r1,c1 and r2, c2
  }
  for(int i = 0; i < K; i++){
  	int r, c;
  	fin >> r >> c;
  	cows.push_back({r, c});
  	storedCoords.insert(r*100000+c);

  }
  for(int i = 0; i < cows.size()-1; i++){
  		bfs(cows[i]);

  }
  fout << c << endl;
  //run a bfs to see if there is any way for the cow to cross
  //without crossing road
  //each cow is a node
  //if there is a path from one cow to another such that
  //you do not have to pass a road, it is not distant


}






