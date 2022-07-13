#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
#include <fstream>

using namespace std;

bool checkFactor(int key, vector<int> &v, int i){
	int count = 0;
	for(int j = 0; j < v.size(); j++){
		if(j != i){
			if(v[j] % key == 0){
				count++;
			}
		}
	}
	if(count == v.size()-1){
		return true;
	}
	return false;

}


int main(){
	int n;
	cin >> n;
	vector<int> v, output;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	for(int i = 0; i < v.size(); i++){
		if(!checkFactor(v[i], v, i)){
			output.push_back(v[i]);
		}
	}
	if(output.size() == 0){
		cout << -1 << endl;
	}
	cout << output.size() << endl;
	for(int i = 0; i < output.size(); i++){
		cout << output[i] << " ";
	}

	
} 