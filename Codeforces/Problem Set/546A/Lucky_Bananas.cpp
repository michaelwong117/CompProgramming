
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;



int main(){
	int k, w, n, total = 0;
	cin >> k >> w >> n;
	for(int i = 1; i <= n; i++){
		total += k*i;
	}
	if(total - w <= 0){
		cout << 0 << endl;
	}
	else{
		cout << total - w << endl;
	}
	

}