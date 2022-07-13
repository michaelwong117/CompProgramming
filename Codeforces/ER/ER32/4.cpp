#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
#include <fstream>

using namespace std;



int main(){

	long long n, k;
	cin >> n >> k;

	long long sum = 1;

	if (k >= 2){
		sum += n*(n-1)/2;
	}
	if (k >= 3){
		sum +=  n* (n-1) * (n-2) / 3;
	}
	if(k >= 4){
		long long a =  3 * n*(n-1)*(n-2)*(n-3) / 8;
		sum += a;
	}
	cout << sum << endl;

	
}