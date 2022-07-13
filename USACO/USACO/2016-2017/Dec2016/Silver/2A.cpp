#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main(){

	ifstream fin("citystate.in");
	ofstream fout("citystate.out");
	int n, count = 0;
	fin >> n;
	map<string, string> matches; 
	vector<string> seen;
	for(int i = 0; i < n; i++){
		//a = Florida
		//b = FL
		string a, b;
		fin >> a >> b;
		if(find(seen.begin(), seen.end(), b) != string::npos){
			continue;
		}
		seen.push_back(b);

		cout << "searching for " << a.substr(0, 2) << endl;
		

		if(matches.find(a.substr(0, 2)) != matches.end()){
			// cout << matches[a.substr(0, 2)] << " " << b << endl;

			if(b == matches[a.substr(0, 2)]){
				// cout << matches[a.substr(0, 2)] << " " << b << endl;
				
				count++;
				cout << "FOUND" << endl;
			}
		}
		matches[b] = a.substr(0, 2);
		cout << "now in map " << b << endl;
	}
	fout << count << endl;
}