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


int findMidPoint(map<int, int> &numToFreq){
	int total = 0;
	vector<int> sums;
	for(auto x: numToFreq){
		// cout << x.second << endl;
		total += x.second;
		sums.push_back(total);
		// cout << total << endl;
	}
	// cout << total << endl;
	cout << sums[upper_bound(sums.begin(), sums.end(), total/2) - sums.begin()] << endl;
	return sums[upper_bound(sums.begin(), sums.end(), total/2) - sums.begin()];
}

int main(){

	ifstream fin("pairup.in");
	ofstream fout("pairup.out");
	int n;
	fin >> n;
	map<int, int> numToFreq; 
	map<int, int, greater<int>> rev;
	for(int i = 0; i < n; i++){
		int x, y;
		fin >> x >> y;
		// cout << x << endl;
		numToFreq[y] = x;
		rev[y] = x;

	}
	ll m = findMidPoint(numToFreq);
	ll max = 0, sum = 0;
	for(auto x: numToFreq){
		// cout << x.first << " " << x.second << endl; 
		for(auto y: rev){
			sum += y.second;
			if(y.second == 0){
				continue;
			}
			// cout << y.first << " " << y.second << endl;

			if(sum >= m){
				// cout << x.first << " " << y.first << endl;
				if(x.first == y.first && x.first + y.first > max){
					max = x.first + y.first;
				}
				fout << max << endl;
				return 0;
			}
			if(x.first + y.first > max){
				max = x.first + y.first;

			}
			if(x.second > y.second){
				numToFreq[x.first] -= y.second;
				// x.second -= y.second;
				rev[y.first] = 0;
				// y.second = 0;
				//combine same x with next y
			}
			else{
				rev[y.first] -= numToFreq[x.first];
				// y.second -= x.second;
				break;
				//combine same y with next x
			}
			
		}
	}



	
}