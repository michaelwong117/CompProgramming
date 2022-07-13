/*
ID: michaelwong11
PROG: milk2
LANG: C++     
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;


int main() {
	int N;  // Number of cows.
	ofstream fout("milk2.out");
	ifstream in("milk2.in");
	in >> N;
	vector<pii> t;
	int maxt = 0, maxidle = 0;
	for(int i = 0; i < N; i++){
		int start, fin;
		in >> start >> fin;
		t.push_back({start, fin});
	}
	sort(t.begin(), t.end());
	int start = t[0].f, fin = t[0].s, curt = fin-start;
	for(int i = 1; i < t.size(); i++){
		int newst = t[i].f, newfin = t[i].s;
		if(fin >= newfin) continue;
		else if(newst <= fin){ //overlap exists
			curt += newfin - fin;
		}
		else{
			maxt = max(maxt, curt);
			// cout << newst << " " << fin << endl;
			maxidle = max(maxidle, newst - fin);
			curt = newfin - newst;
		}
		start = newst;
		fin = newfin;
	}
	maxt = max(maxt, curt);
	fout << maxt << " " << maxidle << endl;
	

}













