//g++ filename.cpp -std=c++14 -DH

#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1e9 + 7

typedef long long ll;
typedef pair<int, string> pis;
typedef pair<int,int> pii;

//set tab size to 3

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	ll n, k;
	cin >> n >> k;
	vector<ll> cap;
	ll minr = 100000000000000000000, val, amount;
	for(ll i = 0; i < k; i++){
		ll c;
		cin >> c; 
		if(n % c < minr){
			minr = n % c;
			val = i+1;
			amount = n / c;
			
		}
	}
	cout << val << " " << amount << endl;



	
	
}