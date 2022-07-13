/*
ID: michaelwong11
PROG: palsquare
LANG: C++14   
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <stack> 
#include <string.h>
#include <set>
#include <stack>

using namespace std;
// g++ -g (program name) -std=c++14
// llbd ./a.out
// run
// quit
// long long baseConverter(int number, int base){
// 	int leftover = number % base;
// 	int divide = number / base;
// 	string reversedNum;
// 	while (divide != 0){
// 		number /= base;
// 		leftover = number % base;
// 		divide = number / base;
// 		//cout << "divide =, " << divide << endl;
// 		//cout << "leftover =  , " << leftover << endl;
// 		reversedNum += leftover
// 	}
// 	for(int i = convertedNum.size()-1; i >= 0; i--){
// 		reversedNum += to_string(convertedNum[i]);
// 	}

// 	return stoll(reversedNum);
// }


// baseConverter2(15, 16) returns 'F'.
// baseConverter2(17, 16) returns '11'.
string baseConverter2(int number, int base) {
	string reversedNum;
	int divide = 1;
	int leftover;
	while (divide != 0){ 
		//cout << "divide =, " << divide << endl;
		//cout << "leftover =  , " << leftover << endl;
		leftover = number % base;
		divide = number / base;
		if (leftover == 10){
			reversedNum += "A";
		}
		else if (leftover == 11){
			reversedNum += "B";
		}
		else if (leftover == 12){
			reversedNum += "C";
		}
		else if (leftover == 13){
			reversedNum += "D";
		}
		else if (leftover == 14){
			reversedNum += "E";
		}
		else if (leftover == 15){
			reversedNum += "F";
		}
		else if (leftover == 16){
			reversedNum += "G";
		}
		else if (leftover == 17){
			reversedNum += "H";
		}
		else if (leftover == 18){
			reversedNum += "I";
		}
		else if (leftover == 19){
			reversedNum += "J";
		}
		else {
			reversedNum += to_string(leftover);
		}

		number /= base;
	}

	reverse(reversedNum.begin(),reversedNum.end());

	return reversedNum;


}

string reverseNumber(string number){
	string reversedNum = number;
	reverse(reversedNum.begin(),reversedNum.end());
	return reversedNum;


}
bool checkPalindrome(string number){
	if(number == reverseNumber(number)){
		return true;
	}
	else{
		return false;
	}
}

int main() {

	//cout << baseConverter2(17, 16) << endl;

	ofstream fout ("palsquare.out");
	ifstream fin ("palsquare.in");
	//int output = baseConverter(1025, 15);
	//cout << output << endl;
	//cout << reverseNumber(8705) << endl;
	//cout << checkPalindrome(1000) << endl;
	int base;
	fin >> base;
	//cout << "base = " << base << endl;
	for(int i=1;i<=300;i++){
		int squared = i*i;
		const string converted = baseConverter2(squared, base);
		if (checkPalindrome(converted)){
			fout << baseConverter2(i, base) << " " << converted << endl;
		}

	}


}