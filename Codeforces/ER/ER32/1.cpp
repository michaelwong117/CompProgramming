#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
#include <fstream>

using namespace std;

int main(){

	int n, count = 0;
	cin >> n;
	vector<int> num;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		num.push_back(a);
	}
	for(int i = 1; i < n-1; i++){

		if((num[i-1] < num[i])&&(num[i+1] < num[i])){
			count++;
		}
		else if((num[i-1] > num[i])&&(num[i+1] > num[i])){

			count++;
		}
	}
	cout << count << endl;


}