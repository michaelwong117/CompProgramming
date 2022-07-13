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


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// ifstream fin("creditcard.in");
	ll n, d, total = 0, c = 0, check = 0;
	cin >> n >> d;

	for(ll i = 0; i < n; i++){
		ll a;
		cin >> a;
		total += a;
		//not a copy

		// cout << total << endl;
		if(a == 0){
			if(check < 0){
				c++;
				check = d;
			}

			if(total < 0){
				total = 0;
			}
		}
		else{
			check = min(d, check+a);
			if(total > d){
				cout << -1 << endl;
				return 0;
			}

		
		}
	}
	cout << c << endl;

	

	
}