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

using namespace std;
int method1(const vector<int> v){
	for(int i = 0; i < v.size(); i++){
		diff = max_element(v) - min_element(v);
		while(diff > 17){
			max_element(v)
		}
	}



}

int main(){

	ofstream fout("skidesign.out");
	ifstream fin("skidesign.in");
	int N;
	fin >> N;
	vector<int> heights;
	for(int i = 0; i < N; i++){
		int height;
		fin >> height;
		heights.push_back(height);
	}
	fout << method1(heights) << endl;


}

