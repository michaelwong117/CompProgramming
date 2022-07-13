/*
ID: michaelwong11
PROG: dualpal
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

	ofstream fout ("dualpal.out");
	ifstream fin ("dualpal.in");
	int N;
	int S;
	int found = 0;
	bool firstCheck = false;
	fin >> N >> S;
	//cout << N << " " << S << endl;
	// while we have not found N number of palindromes greater than S
	// 	search for numbers only greater than S
	for(int i = S+1; i > S; i++){
		for(int j = 2; j <= 10; j++){
			string converted = baseConverter2(i, j);
			if((checkPalindrome(converted) == true) && (firstCheck == false)){
				firstCheck = true;
				// fout << i << " and converted = " << converted << endl;
				//fout << i << " " << j << endl;
			} else if((checkPalindrome(converted) == true) && (firstCheck == true)){
				found++;
				//fout << i << " " << j << endl;
				fout << i << endl;
				//cout << "converted = " << converted << endl;
				break;

			}

		}
		firstCheck = false;
		if (found == N){
			break;
		}


	}















}