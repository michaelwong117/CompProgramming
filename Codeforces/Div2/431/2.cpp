#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;



int main(){
	int n;
	vector<vector<int>> coords;
	cin >> n;
	for(int i = 0; i < n; i++){
		int x = i+1;
		int y;
		cin >> y;
		coords.push_back({x, y});

	}
	for(int i = 0; i < coords.size(); i++){
		for(int j = 0; j < coords.size(); j++){
			if(i < j){
				int slope = (coords[i][1] - coords[j][1]) / (coords[i][0] - coords[j][0]);
				

			}
		}

	}


}