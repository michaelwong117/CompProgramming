
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
	//find the least amount of coins that sum up to 
	//more than the remaining coins
	int n, total = 0, sum = 0, count = 0;
	cin >> n;
	vector<int> coins;
	for(int i = 0; i < n; i++){
		int c;
		cin >> c;
		sum += c;
		coins.push_back(c);
	}
	sort(coins.begin(), coins.end());
	while(total <= sum){
		total += coins[coins.size()-1];
		sum -= coins[coins.size()-1];
		count++;
		coins.pop_back();

	}
	cout << count << endl;

	

}