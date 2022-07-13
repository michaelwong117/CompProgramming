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
	ll n, d, total = 0, min = 0, maxTotal = 0;
	cin >> n >> d;
	
	for(ll i = 0; i < n; i++){
		ll a;
		cin >> a;
		total += a;
		if(total > d){
			cout << -1 << endl;
			return 0;
		}
		if(total > maxTotal && min > 0){
			maxTotal = total;
			// cout << d << " " << maxTotal << endl;
		}
		
		if(a == 0){
			if(min == 0){
				if(total < 0){
					min++;
					if(total < 0){
						total = 0;
					}
					maxTotal = total;

				}
			}
			else{
				//the maximum value the total can be after adding is equivelent to the 
				//d - the max sum of culmative consecutive integers you find before 
				//the next zero
				// cout << d << " " << maxTotal << endl;

				if(d - maxTotal + total < 0){
					min++;
					if(total < 0){
						total = 0;
					}
					maxTotal = total;

				}
			}
			
		}
	
	}

	cout << min << endl;
	

	
}