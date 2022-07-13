#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
	int n;
	int count;
	cin >> n;
	vector<int> input;
	vector<int> evenIndex;
	for(int i = 0; i<n; i++){
		int a;
		cin >> a;
		if(a % 2 == 0){
			evenIndex.push_back(i);
		}
		input.push_back(a);
	}
	if((input[0] % 2 != 0) && (input[n-1] % 2 != 0)){
		if(n % 2 != 0){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	else{
		cout << "NO" << endl;
	}



}