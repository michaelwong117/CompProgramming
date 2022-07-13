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
	vector<int> org = v, one, two, three; 
	for(int i = 0; i < org.size(); i++){
		if(i >= 0 && i < ones){
			one.push_back(org[i]);
		}
		else if(i >= ones && i < ones+twos){
			two.push_back(org[i]);
		}
		else{
			three.push_back(org[i]);
		}
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < org.size(); i++){
		if(org[i] != v[i]){
			count++;
			if(org[i] == 1){
				if(i >= ones && i < ones+twos){
					vector<int>::iterator it = find(one.begin(), one.end(), 2);
					if(it != one.end()){
						swap(org[i], org[it-org.begin()]);
						ones[it-ones.begin()] = org[i];
					}
					else{
						vector<int>::iterator it = find(one.begin(), one.end(), 3);
						swap(org[i], org[it-org.begin()]);
						ones[it-ones.begin()] = org[i];
						
					}
				}
				else{
					vector<int>::iterator it = find(one.begin(), one.end(), 3);
					if(it != one.end()){
						swap(org[i], org[it-org.begin()]);
						ones[it-ones.begin()] = org[i];
					}
					else{
						vector<int>::iterator it = find(one.begin(), one.end(), 2);
						swap(org[i], org[find(one.begin(), one.end(), 2) - org.begin()]);
						ones[it-ones.begin()] = org[i];
					}
				}
			}
			else if(org[i] == 2){
				if(i >= 0 && i < ones){
					vector<int>::iterator it = find(two.begin(), two.end(), 1);
					if(it != one.end()){
						swap(org[i], org[it-org.begin()]);
						twos[it-twos.begin()] = org[i];
					}
					else{
						vector<int>::iterator it = find(two.begin(), two.end(), 3);
						swap(org[i], org[it - org.begin()]);
						twos[it-twos.begin()] = org[i];
					}
				}
				else{
					vector<int>::iterator it = find(two.begin(), two.end(), 3);
					if(it != one.end()){
						swap(org[i], org[it-org.begin()]);
						twos[it-twos.begin()] = org[i];
					}
					else{
						vector<int>::iterator it = find(two.begin(), two.end(), 1);
						swap(org[i], org[it - org.begin()]);
						twos[it-twos.begin()] = org[i];
						
					}
				}
			}
			else{
				if(i >= 0 && i < ones){
					vector<int>::iterator it = find(three.begin(), three.end(), 1);
					if(it != one.end()){
						swap(org[i], org[it-org.begin()]);
					}
					else{
						swap(org[i], org[find(three.begin(), three.end(), 2) - org.begin()]);

					}
				}
				else{
					vector<int>::iterator it = find(three.begin(), three.end(), 2);
					if(it != one.end()){
						swap(org[i], org[it-org.begin()]);
					}
					else{
						swap(org[i], org[find(three.begin(), three.end(), 1) - org.begin()]);
					}
				}
			}
		}
	}
	// cout << 0 << " " <<ones << " " << ones << " " << 
	// twos+ones << " " << twos+ones << " " << threes+twos+ones << endl; d
	// cout << count << endl;
	for(auto a: org){
		cout << a << endl;
	}
	


}