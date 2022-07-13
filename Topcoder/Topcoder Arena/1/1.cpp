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

class FiveRooksDiv2 {
    public:
    	int findMax(vector<string> v);
};

int FiveRooksDiv2::findMax(vector<string> v) {
    int maxCol = 0, maxRow = 0;
    vector<int> colSums(v.size(), 0);
	for(int i = 0; i < v.size(); i++){
        int rowCount = 0;
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j] == 'R'){
                colSums[j]++;
                rowCount++;
            }
        }
        if(rowCount > maxRow){
            maxRow = rowCount;
        }  
    }
    for(auto a: colSums){
        if(a > maxCol){
            maxCol = a;
        }
    }
    return max(maxCol, maxRow);
}


