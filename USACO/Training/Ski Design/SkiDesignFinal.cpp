/*
ID: michaelwong11
PROG: skidesign
LANG: C++14     
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {

	ofstream fout("skidesign.out");
	ifstream fin("skidesign.in");
	int N, mr = 17, cost=0;
	fin >> N;
	if(N == 1){
		fout << 0 << endl;
		return 0;
	}
	vector<int> h (N);
	for(int i = 0; i < N; i++){
		fin >> h[i];
	}
	sort(h.begin(), h.end());

	int i = 0, j = h.size()-1, t = 0, ij = 0, sumi = 0, sumj = 0;
	while(i != j){
		if(h[j] - h[i] <= mr){
			if(t == 0){
				j--;
				cost += sumj*sumj;
				sumj = 0;
				t = 1;
			}
			else{
				cost += sumi*sumi;
				sumi = 0;
				i++;
				t = 0;
			}
		}
		else{
			if(ij == 0){
				h[j]--;
				sumj++;
				ij = 1;
			}
			else{
				h[i]++;
				sumi++;
				ij = 0;
			}
		}
	}
	fout << cost << endl;
}