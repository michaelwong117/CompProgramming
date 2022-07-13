#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int fibb(int n){
	map<int,int> pastFibb;
	if(n <= 0){
		return 0;
	}
	else if(n == 1){
		return 1;
	}
	if(pastFibb.count(n) == 0){
		pastFibb[n] = fibb(n-1) + fibb(n-2);
	}
	return pastFibb[n];

}


int main(){
	cout << fibb(6) << endl;

}