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
	fin >> N;
	vector<int> heights;
	for(int i = 0; i < N; i++){
		int height;
		fin >> height;
		heights.push_back(height);
	}
	sort(heights.begin(), heights.end());
	vector<int> editedHeights = heights;

	for(int j = editedHeights.size()-1; j >= 0; j--){
		for(int i = 0; i < editedHeights.size(); i++){
			int diff = editedHeights[j] - editedHeights[i];
			while(diff > 17){
				if(heights[j] - editedHeights[j] > editedHeights[i] - heights[i]){

					editedHeights[j]--;

				}
				else{

					editedHeights[i]++;

				}
				diff = editedHeights[j] - editedHeights[i];

				

			}

		}

		
	}
	for(int i = 0; i<heights.size(); i++){
		cout << editedHeights[i] << endl; 
		totalChange += (heights[i] - editedHeights[i])*(heights[i] - editedHeights[i]);
	}
	fout << totalChange << endl;
}






