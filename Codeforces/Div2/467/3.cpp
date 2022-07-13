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

ll gcd(ll a, ll b)
{
   if (b==0) return a;

   return gcd(b,a%b);
}


class Frac {
    

    public:
        long long numer, denom;

        Frac() {
            numer = 0;
            denom = 1;
        }

        Frac(long long n, long long d) {
            if (d==0) {
                cerr << "denom may not be 0." << endl;
                exit(0);
            } else if (n == 0) {
                numer = 0;
                denom = 1;
            } else {
                ll sign = 1;
                if (n < 0) {
                    sign *= -1;
                    n *= -1;
                }
                if (d < 0) {
                    sign *= -1;
                    d *= -1;
                }

                long long tmp = gcd(n, d);
                numer = n/tmp*sign;
                denom = d/tmp;
            }
        }

        operator ll() {return (numer)/denom;}
        operator float() {return ((float)numer)/denom;}
        operator double() {return ((double)numer)/denom;}
}; 

Frac operator+(const Frac& lhs, const Frac& rhs) {
    Frac tmp((lhs.numer*rhs.denom
                +rhs.numer*lhs.denom) % MOD,
                (lhs.denom*rhs.denom) % MOD);
    return tmp;
}

Frac operator+=(Frac& lhs, const Frac& rhs) {
    Frac tmp((lhs.numer*rhs.denom
                +rhs.numer*lhs.denom) % MOD,
                (lhs.denom*rhs.denom) % MOD);
    lhs = tmp;
    return lhs;
}

Frac operator-(const Frac& lhs, const Frac& rhs) {
    Frac tmp(lhs.numer*rhs.denom
                -rhs.numer*lhs.denom,
                lhs.denom*rhs.denom);
    return tmp;
}

Frac operator-=(Frac& lhs, const Frac& rhs) {
    Frac tmp(lhs.numer*rhs.denom
                -rhs.numer*lhs.denom,
                lhs.denom*rhs.denom);
    lhs = tmp;
    return lhs;
}

Frac operator*(const Frac& lhs, const Frac& rhs) {
    Frac tmp((lhs.numer*rhs.numer)%MOD,
               (lhs.denom*rhs.denom)%MOD);
    return tmp;
}

Frac operator*=(Frac& lhs, const Frac& rhs) {
    Frac tmp((lhs.numer*rhs.numer) % MOD,
               (lhs.denom*rhs.denom) % MOD);
    lhs = tmp;
    return lhs;
}

Frac operator*(ll lhs, const Frac& rhs) {
    Frac tmp((lhs*rhs.numer)% MOD,(rhs.denom) % MOD);
    return tmp;
}

Frac operator*(const Frac& rhs, ll lhs) {
    Frac tmp((lhs*rhs.numer) % MOD,(rhs.denom) % MOD);
    return tmp;
}

Frac operator/(const Frac& lhs, const Frac& rhs) {
    Frac tmp((lhs.numer*rhs.denom) % MOD,
                 (lhs.denom*rhs.numer) % MOD);
    return tmp;
}



typedef long long ll;
typedef pair<int, string> pis;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	ll k, d, t;
	fin >> k >> d >> t;
	Frac F(1, 1);
	Frac cur(0, 1);
    double numMinutes;
	while(cur.numer*F.denom < F.numer*cur.denom){
		Frac cook(k, t);
		cur += cook;
        numMinutes += k;
		if(cur.numer*F.denom >= F.numer*cur.denom){
            cur -= cook;
            cur += (F - cur);
            numMinutes -= k;
            cout << numMinutes << endl;
            numMinutes +=  double(F)-double(cur);
            break;
            // cout << (double(cur.numer)/cur.denom) << endl;
		}
		
        if(d >= k){
            Frac othercook(d-k, 2*t);
            cur += othercook;
            numMinutes += d;
            if(cur.numer*F.denom >= F.numer*cur.denom){
                cur -= othercook;
                cur += (F - cur);
                numMinutes -= (d);
                numMinutes += (double(F)-double(cur))*2.0;
                break;
                // cout << (double(cur.numer)/cur.denom) << endl;
            }
        }
	}
    cout << fixed << showpoint;
    cout << setprecision(10);
    cout << numMinutes << endl;
	
}