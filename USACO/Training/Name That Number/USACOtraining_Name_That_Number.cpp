/*
ID: michaelwong11
PROG: namenum
LANG: C++14     
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getDigits(int num){
	vector<int> digits;
	while (num != 0){
		digits.push_back(num%10);
		num /= 10;
	}

	return digits;
}

int main() {
	ofstream fout("namenum.out");
	ifstream fin("namenum.in");
	int N;
	fin >> N;
	vector<vector<string>> usedDigits;
	vector<string> sec = {'A','B','C'};
	vector<string> third = {'D','E','F'};
	vector<string> fourth = {'G','H','I'};
	vector<string> fifth = {'J','K','L'};
	vector<string> six = {'M','N','O'};
	vector<string> sev = {'P','R','S'};
	vector<string> eig = {'T','U','V'};
	vector<string> nin = {'W','X','Y'};
	vector<vector<string>> touchTone = {sec, third, fourth, fifth, six, sev, eig, nin};
	vector<int> v = getDigits(N);
	vector<string> allPossibleCombos;
	for (int elem: v){
		usedDigits.push_back(touchTone[elem-2]);
	}
	for (int i = 0; i < usedDigits.size(); i++){
		for(int j = 0; j<3; j++){
			for(auto elem: usedDigits){
				elem[j]
			}
		}

	}







}