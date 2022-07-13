#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
#include <fstream>

#define ll long long

using namespace std;


// ll rPow(ll n, ll m){
// 	ll p = (n-1)*(m-1);
// 	ll product = 1;
// 	while(p > 0){
// 		product *= 2;
// 		if(product > mod){
// 			product %= mod;
// 		}

// 		p--;
// 	}
// 	return product;
// }

//return x^y mod p
ll lpower(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1){

            res = (res*x) % p;
            y--;
        }
 
        // y must be even now
        y = y/2; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}





int main(){

	ll n, m, mod = 1e9 + 7;
	// cout << mod << endl;
	int k;

	cin >> n >> m >> k;
	if((n+m) % 2 == 1 && k == -1){
		cout << 0 << endl;
	}
	else if(n == 1 || m == 1){
		cout << 1 << endl;

	}
	else{
		cout << lpower(lpower(2, n-1, mod), m-1, mod) << endl;
	} 
	
	// cout << power(power(2, 2, mod), 2, mod) << endl;
	
	
}