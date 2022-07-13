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
	int min = 99999999, cost = 0;
    	sort(v.begin(), v.end());
    	for(int i = m-1; i < v.size(); i++){
    		for(int j = 0; j <= i; j++){
    			cost += v[i] - v[j];
    		}
    		if(min > cost){
    			min = cost;
    		}
    		cost = 0;
    	}
    	return min;
}

