#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

#define ll long long
using namespace std;

ll p;

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


int NumDigits(int n) {
    int digits = 0;
    if (n <= 0) {
        n = -n;
        ++digits;
    }
    while (n) {
        n /= 10;
        ++digits;
    }
    return digits;
}



ll generatePalindromeEven(long long a, long long k){
	ll sum = 0, c = 0;
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
			if(c == k){
				break;
			}
			if(NumDigits(i) % 2 == 0){
				cout << i << endl;
				sum += i; 
				c++;
				sum %= p;
			}
		}
		largestPalindrome = 11;
	}


	string lp = to_string(largestPalindrome);
	string half = lp.substr(0, lp.length()/2);
	int i = 1;
	while(c < k){
	 	//use i to switch between even and odd
		i*=10;
		//when to switch to uneven??
		
		//half of the palindrome
		
		//even palindrome; nothing in the middle

		while((stoll(half) % i != 0)&&(c < k)){
			lp = half+Reverse(half);
			if(NumDigits(stoll(lp)) % 2 == 0){
				//just generate all the palindromes up to b that are greater than a
				//time is not a problem
				if(c < k){
					cout << lp << endl;
					sum += stoll(lp);
					c++;
					sum %= p;
				}
			}
			//increment the half; 11-11 becomes 12-21
			half = to_string(stoll(half) + 1);
			
			



		}
		
		if(c == k){
			break;
		}
		//uneven palindrome; element in the middle
		half = to_string(stoll(half) / 10);
		lp = half + Reverse(half);
		lp.insert(lp.length()/2, 1, '0');
		while((stoll(half) % i != 0)&&(c < k)){
			lp[(lp.length()/2)] = '0';

			while(((lp[(lp.length()/2)] - '0') < 10)&&(c < k)){
				lp = half + lp[(lp.length()/2)] + Reverse(half);
				if(NumDigits(stoll(lp)) % 2 == 0){
					//just generate all the palindromes up to b that are greater than a
					//time is not a problem
					if(c < k){
						cout << lp << endl;
						sum += stoll(lp);
						c++;
						sum %= p;
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
			if(c == k){
				break;
			}

			

		}
		if(c == k){
			break;
		}
		

		

	}
	return sum;


}


int main(){
	ifstream fin("input.in");
	ll k;
	fin >> k >> p;
	cout << generatePalindromeEven(0, k) << endl;

	// cout << 10 % 1 << endl;


	
}