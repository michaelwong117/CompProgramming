/*
ID: michaelwong11
PROG: sort3
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;


int n, c = 0, ones = 0, twos = 0, threes = 0;
vector<int> org, v;

void findV(int index, int group, int elem){
	//there is wrong elem in group
	if(group == 1){
		auto it = find(v.begin(), v.begin()+ones, elem);
		if(it != v.end()){
			swap(v[index], v[it-v.begin()]);
		}
		else{
			v[index] = org[index];

		}
	}
	else if(group == 2){
		auto it = find(v.begin()+ones, v.begin()+ones+twos, elem);
		if(it != v.end()){
			swap(v[index], v[it-v.begin()]);
		}
		else{
			v[index] = org[index];

		}
	}
	else{
		auto it = find(v.begin()+ones+twos, v.begin()+ones+twos+threes, elem);
		if(it != v.end()){
			swap(v[index], v[it-v.begin()]);
		}
		else{
			v[index] = org[index];

		}
	}
}



int main(){
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");
	fin >> n;
	v.resize(n);
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

	org = v;
	sort(org.begin(), org.end());
	for(int i = 0; i < v.size(); i++){
		//if it's in the wrong place
		if(v[i] != org[i]){
			cout << v[i] << " " << org[i] << " " << i << endl;
			for(auto a: v){
				cout << a << " ";
			}	
			cout << endl;
			c++;
			//if it is a 2 or 3 where a 1 is supposed to be
			if(v[i] == 1){
				//1 in 2s
				if(i >= ones && i < ones+twos){
					findV(i, 1, 2);
							
				}
				//1 in 3s
				else{
					findV(i, 1, 3);
				}
			}
			else if(v[i] == 2){
				//2 in 1s
				if(i >= 0 && i < ones){
					findV(i, 2, 1);

				}
				//2 in 3s
				else{
					findV(i, 2, 3);
				}
			}
			else{
				//3 in 1s
				if(i >= 0 && i < ones){
					findV(i, 3, 1);
				}
				//3 in 2s
				else{
					findV(i, 3, 2);
				}
			}
		}
	}
	// cout << 0 << " " <<ones << " " << ones << " " << 
	// twos+ones << " " << twos+ones << " " << threes+twos+ones << endl; d
	fout << c << endl;
	// for(auto a: org){
	// 	cout << a << endl;
	// }
	


}