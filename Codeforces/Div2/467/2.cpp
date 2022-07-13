//g++ filename.cpp -std=c++14 -DH
#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define endl '\n'
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define pq priority_queue<int, vector<int>, greater<int>>
#define heap priority_queue<int>
#define vi vector<int>




typedef long long ll;
typedef pair<int, string> pis;
typedef pair<int,int> pii;

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

bool miillerTest(int d, int n)
{
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    int a = 2 + rand() % (n - 4);
 
    // Compute a^d % n
    int x = lpower(a, d, n);
 
    if (x == 1  || x == n-1)
       return true;
 
    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;
 
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
 
    // Return composite
    return false;
}
 
// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool isPrime(int n, int k)
{
    // Corner cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
 
    // Find r such that n = 2^d * r + 1 for some r >= 1
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;
 
    // Iterate given nber of 'k' times
    for (int i = 0; i < k; i++)
         if (miillerTest(d, n) == false)
              return false;
 	return true;
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	int p, y;
	fin >> p >> y;
	for(int i = y; i > p; i--){
		if(isPrime(i, 4) || i % ){
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;



	
}