/*
ID: michaelwong11
PROG: combo
LANG: C++14     
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
int convert(int a, int n){

	if(a == 0){
		a = n;
	}
	if(a == -1){
		a = n-1;
	}
	if(a == n+1){
		a = 1;
	}
	if(a == n+2){
		a = 2;
	}




	return a;
}
using namespace std;

int main(){
	ofstream fout("combo.out");
	ifstream fin("combo.in");
	int N;
	set<vector<int>> workingCombos;
	vector<vector<int>> possibleFarmer(3);
	vector<vector<int>> possibleMaster(3);
	fin >> N;
	for(int i = 0; i < 3; i++){
		int a;
		fin >> a;
		possibleFarmer[i].push_back(convert(a, N));
		possibleFarmer[i].push_back(convert(a+1, N));
		possibleFarmer[i].push_back(convert(a+2, N));
		possibleFarmer[i].push_back(convert(a-1, N));
		possibleFarmer[i].push_back(convert(a-2, N));
	}
	for(int i = 0; i < 3; i++){
		int b;
		fin >> b;
		possibleMaster[i].push_back(convert(b, N));
		possibleMaster[i].push_back(convert(b+1, N));
		possibleMaster[i].push_back(convert(b+2, N));
		possibleMaster[i].push_back(convert(b-1, N));
		possibleMaster[i].push_back(convert(b-2, N));


	}
	for(auto j: possibleFarmer[0]){
		for(auto k: possibleFarmer[1]){
			for(auto l: possibleFarmer[2]){
				workingCombos.insert({j, k, l});
			}
		}
	}
	for(auto j: possibleMaster[0]){
		for(auto k: possibleMaster[1]){
			for(auto l: possibleMaster[2]){
				workingCombos.insert({j, k, l});
			}
		}
	}
	int i = 0;
	for(auto list: workingCombos){
		i++;
		cout << list[0] << "," << list[1] << "," << list[2] << endl;
	}
	if(N == 1){
		i = 1;
		fout << i << endl;
	}
	if(N == 2){
		i = 8;
		fout << i << endl;
	}
	else if(N > 2){
		fout << i << endl;
	}


}