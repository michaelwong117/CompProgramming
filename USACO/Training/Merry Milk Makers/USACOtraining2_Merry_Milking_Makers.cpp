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

using namespace std;

void print_map(const map<int, vector<int> > & farmers)
{
	for (auto const & x: farmers) {
		cout << "key = " << x.first << endl;
		cout << "  value = ";
		for (auto const & y: x.second) {
			cout << y << ' ';
		}
		cout << endl;
	}

}

int main(){

	ofstream fout("milk.out");
	ifstream fin("milk.in");
	int totalPrice = 0;
	int totalUnits = 0;
	int N;
	int M; 
	fin >> N >> M;
	cout << "N = " << N << "; M = " << M << endl;
	map<int, vector<int>> farmers;
	vector<int> stock;
	for(int i = 0; i<M; i++){
		int price;
		int units;
		fin >> price >> units;
		if (farmers.find( price ) == farmers.end()){
			// key not found.
			farmers[price] = {units};
			stock.push_back(units);

		}
		else {

			vector<int> value = farmers[ price ];
			value.push_back(units); // Add new value.
			farmers[ price ] = value;
			//stock.push_back(units);
			//farmers[price] = stock;
			// for(auto elem: farmers[price]){
			// 	cout << elem << endl;
			// }
			// for(auto elem: stock){
			// 	cout << elem << endl;
			// }


		}
	}

	// Take a look at what we parsed in.
	// print_map( farmers );

	for(auto const & x: farmers){

		// for(auto elem: x.second){
		// 		cout << elem << endl;
		// 	}
		for(int j = 0; j < x.second.size(); j++){
			// while((totalUnits < N) && (i < x.second[j])){

			for(int i = 0; i < x.second[j]; i++){
				if (totalUnits >= N){
					break;
				}
				// cout << x.second[j] << " " << j << endl;
				totalUnits++;
				// cout << x.second[j] << endl;
				totalPrice += x.first;
				// cout << "units = " << totalUnits << endl;
				// cout << "price is adding an additional " << x.first << " to add up to " << totalPrice << endl;
				// cout << totalUnits << endl;

			}

			if (totalUnits >= N){
				break;
			}
		}
	}
	// cout << totalUnits << endl;
	fout << totalPrice << endl;


}
