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

vector<int> minV, bags;
vector<vector<int>> feed;
int V, G;

int copies(int start, int key){
	if(start <= 0) return 999999999;
	if(key % start == 0){
		return key / start;
	}
	else{
		return key / start + 1;
	}
}

vector<int> findDiff(int next, vector<int> past){
	vector<int> cur;
	int mincopies = 999999999, i = next;
	while(minV[i] <= 0 && i < minV.size()) i++;
	if(i == minV.size()) return past;
	for(int j = 0; j < feed.size(); j++){
		int cop = copies(feed[j][i], minV[i]);
		// cout << feed[j][i] << " " << minV[i] << " mincopies ";
		// cout << mincopies << " copies " << cop << endl;
		if(mincopies > cop){
			mincopies = cop;
			cur.clear();
			cur.push_back(j);
		}
		else if(mincopies == cop) cur.push_back(j);
	}
	// for(auto a: cur){
	// 	cout << a << " ";
	// }
	// cout << endl;
	cur = findDiff(i+1, cur);

	return cur;

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
	for(int i = 0; i < G; i++){
		for(int j = 0; j < V; j++){
			int f;
			fin >> f;
			feed[i].push_back(f);
		}
	}
	int tot = 0;
	//iterating through types of vitamins
	for(int i = 0; i < V; i++){
		while(minV[i] > 0){
			//find best feed to scoop
			vector<int> cur = findDiff(i, {});
			int whatFeed = cur[0];
			//find how much you need to remove
			//iterate through the feed and subtract all vitamins in the feed * copies
			//from the needed total
			for(int k = 0; k < feed[whatFeed].size(); k++){
				minV[k] -= feed[whatFeed][k];
			}
			bags.push_back(whatFeed+1);
			tot++; 
			fill(feed[whatFeed].begin(), feed[whatFeed].end(), -1);
		}
	} 
	fout << tot << " ";
	sort(bags.begin(), bags.end());
	for(int i = 0; i < bags.size(); i++){
		if(i != bags.size()-1){
			fout << bags[i] << " ";
		}
		else{
			fout << bags[i] << endl;
		}	
		
	}




	// for(auto a: minV){
	// 	cout << a << endl;
	// }
	// for(auto a: feed){
	// 	for(auto b: a){
	// 		cout << b << endl;
	// 	}
	// }
}	
