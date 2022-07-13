/*
ID: michaelwong11
PROG: barn1
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
#define fir first
#define sec second


using namespace std;

typedef pair<int,int> pii;
typedef pair<int, string> pis;


int main(){
	ofstream fout("barn1.out");
	ifstream fin("barn1.in");
	int M, S, C; 
	//max num of boards, num of stalls, num of cows
	fin >> M >> S >> C;
	vector<int> cows (C), gaps;
	for(int i = 0; i < C; i++){
		fin >> cows[i];

	}
	sort(cows.begin(), cows.end());
	for(int i = 0; i < C-1; i++){
		if(cows[i+1] - cows[i]-1 > 0){
			gaps.push_back(cows[i+1] - cows[i]-1);
		}
	}
	sort(gaps.begin(), gaps.end(), greater<int>());
	// for(auto g: gaps){
	// 	cout << g << endl;
	// }

	int count = cows[cows.size()-1] - cows[0] + 1;
	if(M >= C){
		fout << C << endl;
		return 0;
	}
	for(int i = 0; i < M-1; i++){
		count -= gaps[i];
	}
	fout << count << endl;
	
}