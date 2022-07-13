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


int main(){

	// ifstream fin("input.in");
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int sum1 = 0, sum2 = 0, min = 999;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			sum1 = 0;
			for(int k = i; k < j; k++){
				sum1 += v[k];
			}
			sum2 = 360 - sum1;
			if(abs(sum1 - sum2) < min){
				min = abs(sum1 - sum2);
			}


		}
	}
	if(n == 1){
		min = 360;
	}
	cout << min << endl;

}