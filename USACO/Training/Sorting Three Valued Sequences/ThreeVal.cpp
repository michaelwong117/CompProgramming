/*
ID: michaelwong11
PROG: frac1
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

void checkSwap(vector<int> &org, int num){
	if(num == 1){

	}
}
int findFirstUnsorted(vector<int> &org){
	int max = 0;
	for(int i = 0; i < org.size(); i++){
		if(org[i] >= max){
			max = org[i];
		}
		else{
			return i;
		}
	}
	return -1;
}



int main(){
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");

	int n, count = 0, ones = 0, twos = 0, threes = 0;
	fin >> n;
	vector<int> v (n);
	for(int i = 0; i < n; i++){
		fin >> v[i];
		if(v[i] == 1){
			ones++;
		}
		else if(v[i] == 2){
			twos++;
		}
		else{
			threes++;
		}

		// cout << v[i] << endl;
	}
	vector<int> org = v; 
	sort(v.begin(), v.end());
	for(int i = 0; i < org.size(); i++){
		// <------1------><-----2-----><---------3--------->
		//in wrong place 
		if(org[i] != v[i]){
			checkSwap(org, org[i]);
			if(i >= 0 && i < ones){
				//first section
			}
			else if(i >= ones && i < twos+ones){
				//second section	
			}
			else{
				//third section
				//you can swap a three into this section
				//you can swap a 1 to the front of the first section
				//you can swap a 2 to 
			}
			

		}
	}
	cout << 0 << " " <<ones << " " << ones << " " << 
	twos+ones << " " << twos+ones << " " << threes+twos+ones << endl;
	for(auto a: org){
		cout << a << " ";
	}
	cout << endl;
	


}