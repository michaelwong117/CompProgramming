
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main(){
	int n, max = 0, total = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		total += b-a;
		if(total > max){
			max = total;
		}


	}
	cout << max << endl;
	


}