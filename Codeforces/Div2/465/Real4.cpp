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
#define pq priority_queue

typedef long long ll;
typedef pair<int, string> pis;
typedef pair<int,int> pii;

const ll MOD = 1000000007;

ll GCD(ll a, ll b)
{
   if (b==0) return a;

   return GCD(b,a%b);
}
void reduce_fraction(ll &num, ll&denom){
	ll both = GCD(num, denom);
	num /= both;
	denom /= both;
}
ll realMod(ll num, ll denom, ll MOD){
	for(int i = 0; ; i++){
		if((num + MOD*i) % denom == 0){
			return (num + MOD*i) / denom;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	ll n, m, denom = 1, num = 1, prob = 0;
	fin >> n >> m;
	bool zero = 1;
	vector<int> s1 (n), s2 (n), P (n);
	for(int i = 0; i < n; i++){
		fin >> s1[i];
	}
	for(int i = 0; i < n; i++){
		fin >> s2[i];
	}
	for(int i = 0; i < n; i++){
		reduce_fraction(num, denom);
		if(s1[i] != 0 && s2[i] != 0){
			reduce_fraction(num, denom);
			if(s1[i] > s2[i]){
				if(denom == 1) cout << 1 << endl;
				else{
					prob += realMod(num, denom, MOD);
					cout << prob << endl;
				}
				return 0;
			}
			else if(s2[i] > s1[i]){
				if(denom == 1) cout << 0 << endl;
				else cout << prob << endl;
				return 0;
			}
		}
		else if(s1[i] == 0 && s2[i] != 0){
			num *= (m-s2[i]);
			denom *= m;
			num %= MOD;
			denom %= MOD; 
			prob += realMod(num, denom, MOD);
			// prob *= (m-s2[i]) / m % MOD;
		}		
		else if(s1[i] != 0 && s2[i] == 0){
			denom *= m;
			num *= s1[i]-1;
			num %= MOD;
			denom %= MOD;
			prob += realMod(num, denom, MOD);
			// prob *= s1[i]-1 / m % MOD;

		}
		else{
			num *= m-1;
			denom *= 2*m;
			prob += realMod(num, denom, MOD);
		}
		if(s1[i] == 0 || s2[i] == 0) zero = 0;
		num = 1;
		denom = m;
	}
	if(zero) cout << 0 << endl;
	else{
		// cout << num << " " << denom << endl;
		cout << prob << endl;
	}
	
	
}