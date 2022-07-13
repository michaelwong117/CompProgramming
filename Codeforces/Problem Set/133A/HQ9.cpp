
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main(){
	string s, x = "HQ9";
	bool valid = false;
	cin >> s;
	for(int i = 0; i < s.length(); i++){
		if(x.find(s[i]) != string::npos){
			valid = true;
			cout << "YES" << endl;
			break;
		}

	}
	if(!valid){
		cout << "NO" << endl;
	}

}