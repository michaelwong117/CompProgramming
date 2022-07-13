
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
#include <fstream>

using namespace std;



const vector<int> rPowers = {1, 26, 676, 17576, 456976};



string toLetterWw(const string & s){

	string output = "";
	int num = stoi(s);
	const int denom = 26;
	// cout << "  s = " << s << endl;
	for (int i=0; i<5; i++) {
		int r = num % denom;
		int q = num / denom;
		char c;
		if (r == 0 && q != 0) {
			c = 'Z';
			q--;
		} else {
			if(r == 0){
				break;
			}
			c = r + 64;
	    }

		// cout << "  i = " << i << "; q = " << q << "; r = " << r << "; c = " << c << endl;
		num = q;
		output += c;
	}
	reverse(output.begin(), output.end());
	return output;
}



	
string toNumber(const string & s){

	int len = s.length(), total = 0;
	for(int i = 0; i < len; i++){
		total += (s[i] - 64)*rPowers[len-i-1];

	}


	return to_string(total);
}
bool check(string & s){

	if(s[0] != 'R'){
		return false;
	}
	for(int i = 1; i < s.length(); i++){
		if(!isalpha(s[i])){
			for(int j = i; j < s.length(); j++){
				if(isalpha(s[j])){
					return true;
				}
			}
			return false;
		}
	}
	return false;
}



string convert(string s){
	if(check(s)){
		int br = s.find("C");
		string col1 = s.substr(1, br-1);
		string col2 = s.substr(br+1, s.length()-1-br);

		
		return toLetterWw(col2) + col1;
	}
	else{
        //if it's not in R and C form
		int split;
		for(int i = s.length()-1; i >= 0; i--){
			if(!isalpha(s[i])){
				split = i;
			}
		}
		string col1 = s.substr(0, split);
		string col2 = s.substr(split, s.length());

		string output = "R";
		output += col2;
		return output + 'C' + toNumber(col1);
	}

}


int main(){
	// ifstream fin("Spreadsheet.in");
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s = "";
		cin >> s;
		cout << convert(s) << endl;
	}
	// cout << convert("RZ228") << endl;
	// cout << convert("R228C494") << endl;
	// cout << toLetterWw("1") << '\n' << endl;
	// cout << toLetterWw("25") << '\n' << endl;
	// cout << toLetterWw("26") << '\n' << endl;
	// cout << toLetterWw("27") << '\n' << endl;
	// cout << toLetterWw("52") << '\n' << endl;

	// // "ZZ"
	// cout << toLetterWw("702") << '\n' << endl;

	// // "AAA"
	// cout << toLetterWw("703") << '\n' << endl;

	// // "AAZ"
	// cout << toLetterWw("728") << '\n' << endl;

	// // "ABA"
	// cout << toLetterWw("729") << '\n' << endl;

	
	

}
