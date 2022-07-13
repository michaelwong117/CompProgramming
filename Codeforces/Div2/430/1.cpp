#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {

	long long l, r, x, y, k;
	bool correct = false;
	cin >> l >> r >> x >> y >> k;
	// l = 1;
	// r = 10;
	// x = 1;
	// y = 10;
	// k = 1;
	for(long long i = x; i <= y; i++){
		if((k*i >= l) && (k*i <= r)){
			cout << "YES" << endl;
			correct = true;
			break;
		}
	}
	if(!correct){
		cout << "NO" << endl;
	}
	
	


}