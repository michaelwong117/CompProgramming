#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main(){

	int n, k, t;
	cin >> n >> k >> t;
	if(t <= k){
		cout << t << endl;
	}
	else if((t > k)&&(t < n+1)){
		cout << k << endl;
	}
	else if(t >= n+1){
		cout << k-(t-n) << endl;
	}


}