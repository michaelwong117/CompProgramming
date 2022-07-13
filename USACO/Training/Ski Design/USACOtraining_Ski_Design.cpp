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

int main(){

	ofstream fout("skidesign.out");
	ifstream fin("skidesign.in");
	int N;
	int totalChange = 0;
	int iChange = 0;
	int jChange = 0;
	vector<int> heights;
	fin >> N;
	for(int i = 0; i < N; i++){
		int height;
		fin >> height;
		heights.push_back(height);
	}
	sort(heights.begin(),heights.end());
	// for(auto elem: heights){
	// 	cout << elem << endl;
	// }
	for(int j = heights.size()-1; j >= 0; j--){
		int jChange = 0;
		for(int i = 0; i < heights.size(); i++){
			int iChange = 0;
			int diff = heights[j] - heights[i];
			while(diff > 17){
				if(jChange <= iChange){
					jChange++;
					// cout << "j = " << heights[j] << endl;
					heights[j]--;
					// cout << "j = " << jChange << endl;
				}
				else{
					iChange++;
					// cout << "i = " << heights[i] << endl;
					// cout << "diff = " << diff << endl;
					heights[i]++;
					// cout << "i = " << iChange << endl;
				}
				diff = heights[j] - heights[i];
				// cout << "iChange, jChange = " << iChange << " " << jChange << endl;
				// cout << "diff = " << diff << endl;

				

			}
			// cout << heights[i] << endl;
			// cout << iChange << endl;
			totalChange += iChange * iChange;
		}
		// cout << jChange << endl;
		totalChange += jChange * jChange;




			
	}
	fout << totalChange << endl;
}