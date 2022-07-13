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

void print_map(const map<int, int> & results) {
	for (auto it=results.begin(); it!=results.end(); it++) {
		cout << "low = " << it->first << "; cost = " << it->second << endl;
	}

}


int main() {

	ofstream fout("skidesign.out");
	ifstream fin("skidesign.in");
	int N;
	const int maxDiff = 17;

	vector<int> heights;
	fin >> N;
	for(size_t i = 0; i < N; i++){
		int height;
		fin >> height;
		heights.push_back(height);
	}

	int heightMin = *min_element(heights.begin(), heights.end());
	int heightMax = *max_element(heights.begin(), heights.end());
	cout << "heightMin = " << heightMin << "; heightMax = " << heightMax << endl;

	// [ low of sliding window ] = cost
	map< int, int> results;

	for (int low=heightMin; low<=heightMax-maxDiff+2; low++) {
		// At a sliding window whose width is 17.

		// This is the current high of the window.
		const int high = low + maxDiff;

		int cost = 0;
		for (size_t i=0; i<N; i++) {
			// At each height.
			if (heights[i] > high) {
				// Chop it.
				const int delta = heights[i] - high;
				cost += delta*delta;
			} else if (heights[i] < low) {
				// Bring it up.
				const int delta = low - heights[i];
				cost += delta*delta;
			} else {
				// Do nothing.
			}
		}

		// Store results.
		results[low] = cost;
	}

	// print_map( results );
	int minVal = 999999;
	for(auto const x: results){
		if(x.second < minVal){
			minVal = x.second;
		}
	}
	fout << minVal << endl;
	return 0;
}
