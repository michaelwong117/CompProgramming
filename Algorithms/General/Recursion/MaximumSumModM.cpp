#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
#include <fstream>

using namespace std;

typedef long long ll;

vector<ll> subset, res;
void search(vector<ll> &v, ll k, ll M) {
    if (k == v.size()) {
    	int sum = 0;
    	// cout << subset.size() << endl;
    	for(int i = 0; i < subset.size(); i++){
    		sum += v[subset[i]];
    		sum %= M;
    	}
    	res.push_back(sum);
    } else {
       search(v, k+1, M);
       subset.push_back(k);
       search(v, k+1, M);
       subset.pop_back();
    }
} 
int main(){
	ll n, m;
	ifstream fin("five.in");
	cin >> n >> m;
	vector<ll> fhalf, shalf;
	for(ll i = 0; i < n/2; i++){
		ll a;
		cin >> a;
		// cout << a << " ";
		fhalf.push_back(a);
	}
	// cout << endl;
	// cout << endl;
	for(ll i = n/2; i < n; i++){
		ll a;
		cin >> a;
		// cout << a << " ";
		shalf.push_back(a);
	}
	// cout << endl;
	search(fhalf, 0, m);
	vector<ll> firsthalf = res;
	res.clear();
	search(shalf, 0, m);
	vector<ll> secondhalf = res;
	// for(int i = 0; i < firsthalf.size(); i++){
	// 	cout << firsthalf[i] << " ";
	// }
	// cout << endl;
	// for(int i = 0; i < secondhalf.size(); i++){
	// 	cout << secondhalf[i] << " ";
	// }
	// cout << endl;
	// cout << endl;
	ll max = 0;
	sort(secondhalf.begin(), secondhalf.end());
	if(secondhalf[secondhalf.size()-1] > max){
		max = secondhalf[secondhalf.size()-1];
	}
	for(ll i = 0; i < firsthalf.size(); i++){
		//we want to have an element from shalf whose sum module m + fhalf's sum module m is as close
		//to m-1 as possible or as close to 2m-1 as possible
		if(firsthalf[i] > max) max = firsthalf[i];
		ll half = firsthalf[i], key1 = m - half, key2 = 2*m - half;
		ll m1 = lower_bound(secondhalf.begin(), secondhalf.end(), key1)-secondhalf.begin()-1;
		ll m2 = lower_bound(secondhalf.begin(), secondhalf.end(), key2)-secondhalf.begin()-1;
		if(m1 < 0) m1 = 0;
		if(m2 < 0) m2 = 0;
		// cout << key1 << " " << secondhalf[m1] << " " << key2 << " " << secondhalf[m2] << endl;
		if((secondhalf[m1] + half) % m > max){
			max = (secondhalf[m1] + half) % m;
		}
		if((secondhalf[m2] + half) % m > max){
			max = (secondhalf[m2] + half) % m;
		}

	}
	cout << max << endl;


	
}