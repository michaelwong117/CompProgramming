/*

ID: michaelwong11
PROG: pprime
LANG: C++14

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <math.h>


using namespace std;



string Reverse(string s){
	string out = "";
	for(long long i = s.length()-1; i >= 0; i--){
		out += s[i];
	}
	return out;
}

bool isPalindrome(long long n){
	const string s = to_string(n);
	if(s == Reverse(s)){
		return true;
	}
	return false;

}
bool isPrime(int num) {
    if (num <= 3) {
        return num > 1;
    } else if (num % 2 == 0 || num % 3 == 0) {
        return false;
    } else {
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}



void generatePalindromePrimes(long long a, long long b){
	ofstream fout("pprime.out");
	//finding the largest palindrome above a
	long long largestPalindrome;
	for(long long i = a;;i++){
		if(isPalindrome(i)){
			largestPalindrome = i;
			break;
		}
	}
	if(largestPalindrome < 10){
		for(int i = largestPalindrome; i < 10; i++){
			if(isPrime(i)){
				fout << i << endl;
			}
		}
		largestPalindrome = 11;
	}

	
	string lp = to_string(largestPalindrome);
	string half = lp.substr(0, lp.length()/2);
	int i = 1;
	while(stoll(lp) <= b){
	 	//use i to switch between even and odd
		i*=10;
		//when to switch to uneven??
		
		//half of the palindrome
		
		//even palindrome; nothing in the middle

		while((stoll(half) % i != 0)&&(stoll(lp) <= b)){
			lp = half+Reverse(half);
			if(isPrime(stoll(lp))){
				//just generate all the palindromes up to b that are greater than a
				//time is not a problem
				if(stoll(lp) >= a){
					fout << lp << endl;
				}
			}
			//increment the half; 11-11 becomes 12-21
			half = to_string(stoll(half) + 1);
			
			



		}
		
		if(stoll(lp) > b){
			break;
		}
		//uneven palindrome; element in the middle
		half = to_string(stoll(half) / 10);
		lp = half + Reverse(half);
		lp.insert(lp.length()/2, 1, '0');
		while((stoll(half) % i != 0)&&(stoll(lp) <= b)){
			lp[(lp.length()/2)] = '0';

			while(((lp[(lp.length()/2)] - '0') < 10)&&(stoll(lp) <= b)){
				lp = half + lp[(lp.length()/2)] + Reverse(half);
				if(isPrime(stoll(lp))){
					//just generate all the palindromes up to b that are greater than a
					//time is not a problem
					if(stoll(lp) >= a){
						fout << lp << endl;
					}
				
				}
				//increment the middle element; 11-0-11 becomes 11-1-11
				if(('0' + (lp[(lp.length()/2)] - '0') + 1) == 10){
					break;
				}
				lp[(lp.length()/2)] = '0' + (lp[(lp.length()/2)] - '0') + 1;

			}
			//increment the half for uneven palindrome
			half = to_string(stoll(half) + 1);
			if(stoll(lp) > b){
				break;
			}

			

		}
		if(stoll(lp) > b){
			break;
		}
		

		

	}


}




int main(){
	
	ifstream fin("pprime.in");
	long long a, b;
	fin >> a >> b;
	generatePalindromePrimes(a, b);
	
	


}