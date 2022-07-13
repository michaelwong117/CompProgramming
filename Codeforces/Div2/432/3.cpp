#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

int main(){

	int n, x, y;
	int c = 0, cost = 0;
	cin >> n >> x >> y;
	vector<int> list(n);
	vector<int> nonEven;
	for(int i = 0; i < n; i++){
		cin >> list[i];
	}
	for(int i = 0; i < n; i++){
		if(list[i] % 2 == 0){
			c++;
		}
		else{
			nonEven.push_back(i);
		}
	}
	for(int index: nonEven){
		if(x > y){
			cost += y;
		}
		else{
			cost += x;
		}
	}

	if(c == n){
		cout << 0 << endl;
	}

	
}