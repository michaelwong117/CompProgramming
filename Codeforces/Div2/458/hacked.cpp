#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define ll long long


int n, inp, big;
bool arr[10000000];

int main(){
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	fin >> n;
	for(int i = 0; i < n; i++){
		fin >> inp;
		if(inp > big){
			big = inp;
		}
		arr[inp] = (arr[inp]+1)%2;
	}
	for(int i = big; i > 0; i--){
		if(arr[i] == 1){
			cout << "Conan" << endl;
			return 0;
		}
	}
	cout << "Agasa" << endl;
}
