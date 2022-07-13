#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main(){ 

	int n, k, min, c = 0;
	vector<int> num;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(i == k-1){
			min = a;
		}
		num.push_back(a);
		
	}
	for(auto i: num){
		if((i >= min)&&(i > 0)){
			c++;
		}
	}
	cout << c << endl;


}