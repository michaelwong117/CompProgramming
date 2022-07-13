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

// int l = lower_bound(haybales, 0, haybales.size()-1, a);
// search index for the closest int greater then or equal to a
// v = lower_bound(haybales, 0, haybales.size()-1, b+1);
// find index for closest int greater than b

//v is original vector, low and high represent
//subvector you are searching in, key is what you're searching for

// first element >= x
// int lower_bound(vector<ll> &v, int low, int high, ll key){
// 	while(low < high){

// 		int mid = (high+low)/2;
// 		if(v[mid] == key){

// 			return mid;
// 		}

// 		if(v[mid] < key){
// 			low = mid+1;
// 		}
// 		else{
// 			high = mid;
// 		}
// 	}
// 	if(v[low] < key){
// 		return low+1;
// 	}

// 	return low;


// }
// first element > x
int upper_bound(vector<ll> &v, int low, int high, ll key){
	while(low < high){

		int mid = (high+low)/2;
		if(v[mid] == key){

			return mid;
		}

		if(v[mid] < key){
			low = mid+1;
		}
		else{
			high = mid;
		}
	}
	if(v[low] <= key){
		return low+1;
	}

	return low;
}



int main(){

	// ifstream fin("input.in");
	ll n, x, k;
	//n is size of array
	//x is what y needs to be divis by
	//k integers between ai and aj that are divis by x
	ll m = 0;
	cin >> n >> x >> k;
	vector<ll> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	
	for(int i = 0; i < n; i++){
		vector<ll>::iterator s = lower_bound(v.begin(), v.end(), max(v[i], x * (k + (v[i] - 1) / x)));
		vector<ll>::iterator end = lower_bound(v.begin(), v.end(), max(v[i], x * (k + 1 + (v[i] - 1) / x)));
		// cout << s << " " << end << endl;
		// cout << v[i] << " start " << x*(k + (v[i]-1) /x) << 
		// " end " << x*(k + 1 + (v[i]-1) /x) << endl;
		// cout << s << " " << end << endl;
		m += end - s;
		
	}
	cout << m << endl;
	

}