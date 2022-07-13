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

	ifstream fin("input.in");
	ll n, x, k;
	//n is size of array
	//x is what y needs to be divis by
	//k integers between ai and aj that are divis by x
	fin >> n >> x >> k;
	vector<ll> v(n);
	for(int i = 0; i < n; i++){
		fin >> v[i];
	}
	ll m = 0;
	// cout << k << endl;
	ll count = -999999;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			// cout << count << endl;
			count = -9999999;
			for(ll z = v[i]; z <= v[j]; z++){
				if(z == v[i]){
					count = 0;
				}
				// cout << v[i] << " " << i << " " << z << " " << j << " " << v[j] << endl;
				// cout << "c = " << count << endl;
				if(z % x == 0){
					count++;
					// cout << count << " " << k << endl;
				}
				if(count > k){
					break;
				}
			}
			// cout << count << endl;
			// if(count > k){
			// 	break;
			// }
			if(count == k){
				m++;
			}
			
		}
	}
	cout << m << endl;


}