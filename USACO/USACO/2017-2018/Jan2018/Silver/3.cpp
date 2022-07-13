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

struct newAdd {
	int p;
	pii adjWeight;
};

//set tab size to 3

vector<vector<pii>> v;
vector<newAdd> NA;
// set<pii> seen;
// set<int> Seen;
vector<bool> Seen (5001);
vector<vector<bool>> seen (5001, vector<bool> (5001));
int min = 999999999;

void dfsVisit(vector<pii> & adj, int parent, int minWeight){
	for(int i = 0; i < adj.size(); i++){
		int temp = minWeight;
		if(adj[i].sec < minWeight){
			temp = adj[i].sec;
		}
		// cout << p << " " << adj[i].fir << endl;

		if(seen[parent][adj[i].fir] == 0){
			// cout << parent << " " << adj[i].fir << endl;
			newAdd add;
			add.p = parent;
			add.adjWeight = pii(adj[i].fir, temp);
			if(add.p != add.adjWeight.fir){
				NA.push_back(add);
			}
			seen[add.p][adj[i].fir] = 1;
		}
		if(Seen[adj[i].fir] == 0){
			// cout << "hi" << endl;
			// cout << adj[i].fir << endl;
			Seen[adj[i].fir] = 1;
			dfsVisit(v[adj[i].fir], parent, temp);
		}
		
	}
}
int N, Q;
void buildGraph (){
	for(int i = 1; i < N+1; i++){
		Seen[i] = 1;
		dfsVisit(v[i], i, 1000000001);
		Seen.clear();
		Seen.resize(5001);
	}
}
int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("mootube.in");
	ofstream fout("mootube.out");
	fin >> N >> Q;
	v.resize(N+1);
	for(int i = 0; i < N-1; i++){
		int p, q, r;
		fin >> p >> q >> r;
		v[p].push_back(pii(q, r));
		v[q].push_back(pii(p, r));
		// cout << p << " " << q << " " << r << endl;
		seen[p][q] = 1;
		seen[q][p] = 1;
		// seen.insert(pii(p, q));
		// seen.insert(pii(q, p));
	}
	buildGraph();
	for(int i = 0; i < NA.size(); i++){
		v[NA[i].p].push_back(NA[i].adjWeight);
	}
	// for(int i = 0; i < v.size(); i++){
	// 	for(auto b: v[i]){
	// 		cout << i << " " << b.fir << " relevance = "  << b.sec << endl;
	// 	}
	// }
	for(int i = 0; i < Q; i++){
		int k, vid, count = 0;
		fin >> k >> vid;
		for(int i = 0; i < v[vid].size(); i++){
			if(v[vid][i].sec >= k){
				count++;
			}
		}
		fout << count << endl;
	}
	// cout << "hi" << endl;
}