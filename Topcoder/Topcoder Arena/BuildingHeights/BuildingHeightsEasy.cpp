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

class BuildingHeightsEasy {
    public:
    	int minimum(int m, vector<int> v);
};

int BuildingHeightsEasy::minimum(int m, vector<int> v) {
	int min = 99999999;
	sort(v.begin(), v.end());
    // for(auto a: v){
    //     cout << a << endl;
    // }
    int k = -1;
	for(int i = m-1; i < v.size(); i++){
        k++;
        int cost = 0;
        // cout << i << endl;
		for(int j = k; j <= i; j++){  
            // cout << v[i] << " " << v[j] << endl;
			cost += v[i] - v[j];
		}
        // cout << "min = " << min << " " << cost << endl;
		if(min > cost){
			min = cost;
		}
		
	}
	return min;
}

// int main(){

//     BuildingHeightsEasy B;
//     vector<int> v = {19, 23, 9, 12};
//     int min = B.minimum(3, v);
//     cout << min << endl;
// }
