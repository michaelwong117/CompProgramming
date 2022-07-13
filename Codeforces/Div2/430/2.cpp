#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

int main() {
	int r, d;
	int n;
	int count = 0;
	cin >> r >> d >> n;
	for(int i = 0; i < n; i++){
		int x, y, sr;
		cin >> x >> y >> sr;
		// check that the circle is inside the pizza (radius r) and only resides in the crust
		if(sqrt(x*x + y*y) + sr <= r){
			if(sqrt(x*x + y*y) - sr >= r - d){
				count++;
			}

		}
	}
	cout << count << endl;

}