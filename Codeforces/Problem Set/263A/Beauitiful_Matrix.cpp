
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
	vector<vector<int>> rows;

	for(int i = 0; i < 5; i++){
		vector<int> row;
		for(int j = 0; j < 5; j++){
			int elem;
			cin >> elem;
			row.push_back(elem);
		}
		rows.push_back(row);

	}
	int iDiff = 3, jDiff = 3;
	for(int i = 0; i < rows.size(); i++){
		for(int j = 0; j < rows[i].size(); j++){
			if(rows[i][j] == 1){
				if(abs(i - 2) < iDiff){
					iDiff = abs(i - 2);
				}
				if(abs(j - 2) < jDiff){
					jDiff = abs(j - 2);
				}
			}
				

		}
	}
	cout << jDiff + iDiff << endl;


	

}