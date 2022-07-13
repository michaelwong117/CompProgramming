 /*
ID: michaelwong11
PROG: milk
LANG: C++14     
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){

	ofstream fout("milk.out");
	ifstream fin("milk.in");
	int totalPrice = 0;
	int totalUnits = 0;
	int N;
	int M; 
	fin >> N >> M;
	cout << "N = " << N << "; M = " << M << endl;
	map<int, int> farmers;

	for(int i = 0; i<M; i++){
		int price;
		int units;
		fin >> price >> units;
		farmers[price] = units;
	}

	// for(auto const &x: farmers){
	// 	cout << x.first << " " << x.second << endl;
	// }

	for(auto const & x: farmers){
		// cout << x.first << " " << x.second << endl;

		int i = 0;

		while((totalUnits < N) && (i < x.second)){
			totalUnits++;
			totalPrice += x.first;
			// cout << "units = " << totalUnits << endl;
			// cout << "price is adding an additional " << x.first << " to add up to " << totalPrice << endl;
			i++;
			// cout << totalUnits << endl;

		}
		cout << totalPrice << endl;
		if (totalUnits >= N){
			break;
		}
	}
	// cout << totalUnits << endl;
	fout << totalPrice << endl;

}