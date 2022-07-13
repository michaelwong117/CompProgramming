
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
	//find the least amount of coins that sum up to 
	//more than the remaining coins
	string s;
	cin >> s;
	set<char> distinct;
	for(auto c: s){
		distinct.insert(c);
	}
	if(distinct.size() % 2 == 0){
		cout << "CHAT WITH HER!" << endl;
	}
	else{
		cout << "IGNORE HIM!" << endl;
	}

	

}