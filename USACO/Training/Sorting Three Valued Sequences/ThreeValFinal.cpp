/*
ID: michaelwong11
PROG: sort3
LANG: C++14
*/

//g++ filename.cpp -std=c++14 -DH

#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;


using namespace std;


int main(){
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");
	int n, ans;
	fin >> n;
	vector<int> v (n), count(4);
	vector<vector<int>> out(4, vector<int>(4));
	for(int i = 0; i < n; i++){
		fin >> v[i];
		count[v[i]]++;
	}
	for(int i = 0; i < count[1]; i++){
		out[1][v[i]]++;
	}
	for(int i = count[1]; i < count[1]+count[2]; i++){
		out[2][v[i]]++;
	}
	for(int i = count[1]+count[2]; i < count[1]+count[2]+count[3]; i++){
		out[3][v[i]]++;
	}
	ans =  min(out[1][2], out[2][1]) + min(out[1][3], out[3][1]) + min(out[2][3], out[3][2]);
	fout << ans + 2*(max(out[1][2], out[2][1]) - min(out[1][2], out[2][1])) << endl;
}