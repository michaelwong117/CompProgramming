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

ll p, sum;
 


ll createPalindrome(ll input, ll b)
{
    ll n = input;
    ll palin = input;
 
    
    while (n > 0)
    {
        palin = palin * b + (n % b);
        n /= b;
    }
    return palin;
}
 
void generatePalindromes(ll k)
{
    ll number;
 
        
    ll i = 1;
    while (i <= k)
    {
    	number = createPalindrome(i, 10);
    	sum += number;
        sum %= p;
        // cout << number << " ";
        i++;
    }
    
}

int main(){
	// ifstream fin("input.in");
	ll k;
	cin >> k >> p;
	generatePalindromes(k);
	cout << sum << endl;
	// cout << 10 % 1 << endl;


	
}