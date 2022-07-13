#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <map>

using namespace std;


int main(){

	int n;
	cin >> n;
	// n = 6;
	vector<int> cafes;
	map<int, int> cafesToVisited;

	for(int i = 0 ; i < n; i++){
		int a;
		cin >> a;
		// a = input[i];
		cafes.push_back(a);
	}
	for(int i = 0; i < n; i++){
		cafesToVisited[cafes[i]] = i;
		
	}
	int min = 999999;
	int key;
	for(auto x: cafesToVisited){
		if(x.second < min){
			min = x.second;
			key = x.first;
		}
	}
	cout << key << endl;
	

//////FAOIFASJO;FJA;SJ;OJ
	
}