#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main(){ 
	//
	string s;
	cin >> s;
	if(s.find("0000000") != string::npos){
		cout << "YES" << endl;
	}
	else if(s.find("1111111") != string::npos){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	


}