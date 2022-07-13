
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

bool check (int n){
	string na = "12356890";
	for(auto c: to_string(n)){
		if(na.find(c) != string::npos){
			return false;
		}
		
	}
	return true;
}

int main(){
	int n, valid = false;
	cin >> n;
	for(int i = 0; i <= n; i++){
		if(check(i)){
			if(n % i == 0){
				valid = true;
				break;
			}
		}
	}
	if(valid){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}

}