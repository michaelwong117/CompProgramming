#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main(){ 

	string s, out = "", vowels = "AOYEUIaoyeui";
	cin >> s;
	for(int i = 0; i < s.length(); i++){
		if(vowels.find(s[i]) == string::npos){
			out += ".";
			out += tolower(s[i]);
		}
	}
	cout << out << endl;


}