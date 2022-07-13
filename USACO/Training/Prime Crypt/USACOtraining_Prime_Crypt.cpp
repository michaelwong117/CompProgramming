/*
ID: michaelwong11
PROG: crypt1
LANG: C++14     
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// template <class BidirIter, class Function>
// Function
// for_each_permutation(BidirIter first,
//                      BidirIter mid,
//                      BidirIter last,
//                      Function f);
bool digitChecker(int N, vector<int> d){
	//checks if N is composed only of digits in d
	bool valid = true;
	string stringN = to_string(N);
	for(char c: stringN){
		int C = c - '0';
		if(find(d.begin(), d.end(), C) == d.end()){
			valid = false;
		}
	}
	return valid;
}
vector<int> abcGenerator(vector<int> & digits){
	vector<int> viable;
	for(int a: digits){
		for(int b: digits){
			for(int c: digits){
				viable.push_back((100*a)+(10*b)+c);
			}
		}
	}
	return viable;
	//returns all viable possibilities of abc

}
vector<int> deGenerator(vector<int> & digits){
	vector<int> viable;
	for(int d: digits){
		for(int e: digits){
			viable.push_back((10*d)+e);
		}
	}
	return viable;
	//returns all viable possibilities of de

}
vector<vector<int>> viablePartialProducts(vector<int> abc, vector<int> de, vector<int> usableDigits){

	vector<vector<int>> partialProducts;

	for(int i: de){
		for(int j: abc){
			int p1 = (i%10) * j;
			int p2 = (i/10) * j;
			if((digitChecker(p1, usableDigits)) && (p1 <= 999)){
			
				if((digitChecker(p2, usableDigits)) && (p2 <= 999)){
					// cout << "p2 = " << p2 << endl;
					// cout << "p1 = " << p1 << endl;
					partialProducts.push_back({p1, p2});
				}
			}

		}
	}

	return partialProducts;
	//returns all possibilities of e*abc and d*abc that use viable digits
}
int viableProducts(vector<vector<int>> viablePartialProducts, vector<int> usableDigits){

	int vP = 0;

	for(auto elem: viablePartialProducts){
		int a = elem[0];
		int b = elem[1];
		if(digitChecker(a+(10*b), usableDigits)){
			// cout << a << " " << b << endl;
			vP++;
			
		}
	}
	return vP;
	//e*abc + 10*d*abc has viable digits
	//returns count of crypts that are viable

}



int main(){
	ofstream fout("crypt1.out");
	ifstream fin("crypt1.in");
	int N;
	vector<int> usableDigits;
	fin >> N;
	for(int i = 0; i < N; i++){
		int digit;
		fin >> digit;
		usableDigits.push_back(digit);
	}
	auto viable = viablePartialProducts(abcGenerator(usableDigits), deGenerator(usableDigits), usableDigits);
	// cout << for_each_permutation(usableDigits.begin(), usableDigits.begin()+3, usableDigits.end(), false) << endl;
	// auto partial = viablePartialProducts(abcGenerator(usableDigits), deGenerator(usableDigits));
	// int product = viableProducts(partial[0], partial[1], usableDigits);
	// fout << product << endl;
	int output = viableProducts(viable, usableDigits);
	fout << output << endl;
	return 0;




}