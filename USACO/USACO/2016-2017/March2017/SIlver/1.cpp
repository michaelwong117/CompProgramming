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


int main(){

	ifstream fin("pairup.in");
	ofstream fout("pairup.out");
	int n;
	fin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++){
		int x, y;
		fin >> x >> y;
		for(int i = 1; i <= x; i++){
			v.push_back(y);
		}

	}
	sort(v.begin(), v.end());
	int max = 0;
	for(int i = 0; i < v.size() / 2; i++){
		if(v.at(i) + v.at(v.size()-1-i) > max){
			max = v.at(i) + v.at(v.size()-1-i);
		}
	}


	fout << max << endl;



	
}