#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main(){
	long long n;
	long long m;
	long long a;
	cin >> n >> m >> a;
	long long div1 = n/a;
	long long div2 = m/a;
	if(n % a > 0){
		div1 = n/a + 1;

	}
	if(m % a > 0){
		div2 = m/a + 1;
	}

	cout << div1 * div2 << endl;

}