#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <queue> 


#define ll long long

using namespace std;

void solve(){
	int h = 1000000, l = 0;
	while(l < h){
		int mid = (h+l)/2;
		string a;
		cout << mid << endl;
		fflush(stdout);
		cin >> a;
		if(a == ">="){
			l = mid;
		}
		else{
			h = mid-1;
		}
	}
	cout << "! " << l << endl;
	fflush(stdout);

}

int main(){
	solve();


}