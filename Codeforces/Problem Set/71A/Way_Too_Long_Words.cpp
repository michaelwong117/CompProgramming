#include <iostream>
#include <algorithm>
#include <string>


using namespace std;


string abbreviate(string s){
	string output = "";
	output += s[0];
	output += to_string(s.length() - 2);
	output += s[s.length()-1];
	return output;

}


int main(){

	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		if(s.length() > 10){
			cout << abbreviate(s) << endl;
		}
		else{
			cout << s << endl;
		}
	}


}