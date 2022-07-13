#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
#include <fstream>

using namespace std;

int main(){
	int n; 
	cin >> n;
	int U = 0, D = 0, L = 0, R = 0;
	for(int i = 0; i < n; i++){
		char command;
		cin >> command;
		if(command == 'U'){
			U++;
		}
		else if(command == 'D'){
			D++;
		}
		if(command == 'L'){
			L++;
		}
		if(command == 'R'){
			R++;
		}
	}
	cout << (min(U, D) * 2) + (min(L, R) * 2) << endl;


	
}