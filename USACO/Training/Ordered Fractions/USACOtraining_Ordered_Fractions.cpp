/*
ID: michaelwong11
PROG: frac1
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;



typedef struct Fraction Fraction;

struct Fraction {

    int numerator;
    int denominator;

};

int partition(vector<Fraction> &a, int start, int end){
	Fraction pivot = a[end];
	int pIndex = start;
	for(int i = 1; i < end; i++){
		int num = a[i].numerator;
		int denom = a[i].denominator;
		cout << denom << " " << pivot.denominator << endl;
		if(num / denom <= pivot.numerator / pivot.denominator){
			swap(a[pIndex], a[i]);
			pIndex++;
		}

	}
	swap(a[pIndex], a[end]);
	return pIndex;


}

void quickSort(vector<Fraction> &a, int start, int end){
	if(start < end){
		int pIndex = partition(a, start, end);
		quickSort(a, start, pIndex-1);
		quickSort(a, pIndex+1, end);
	}
}

int main(){

	ifstream fin("frac1.in");
	ofstream fout("frac1.out");
	int n;
	vector<Fraction> fractions;
	fin >> n;
	//generate a list of all possible fractions a / b where  0 <= a <= b and b (1....n)x
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= i; j++){
			Fraction a;
			a.numerator = j;
			a.denominator = i;
			// cout << j << " " << i << endl;
			fractions.push_back(a);

		}
	}
	quickSort(fractions, 0, fractions.size()-1);
	// for(auto f: fractions){
	// 	fout << f.numerator << "/" << f.denominator << endl;
	// }
	




}