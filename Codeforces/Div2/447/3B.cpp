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

bool checkFactor(int key, vector<int> &v){
	for(int j = 0; j < v.size(); j++){
		if(v[j] != key){
			if(v[j] % key != 0)
				return false;
		}			
	}
	return true;
	
}
int main(){
	// ifstream fin("marco.in");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, gcd;
	cin >> n >> gcd;
	vector<int> v (n);
	v[0] = gcd;
	bool valid = true;
	for(int i = 1; i < n; i++){
		cin >> v[i];
		if(v[i] % gcd != 0){
			valid = false;
			break;
		}
		
	}
	if(valid){
		cout << 2*v.size() << endl;
		for(int i = 0; i < v.size(); i++){
			cout << gcd << " " << v[i] << " ";
		}
	}
	else{
		cout << -1;
	}

	cout << endl;


}