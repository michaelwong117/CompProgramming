
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
#include <fstream>

using namespace std;


const vector<int> powers = {456976, 17576, 676, 26, 1};
const vector<int> rPowers = {1, 26, 676, 17576, 456976};



string toLetterWw(const string & s){

	string output = "";
	int num = stoi(s);
	const int denom = 26;
	cout << "  s = " << s << endl;
	for (int i=0; i<4; i++) {
		int r = num % denom;
		int q = num / denom;
		char c;
		if (r == 0 && q != 0) {
			c = 'Z';
			q--;
		} else {
			c = r + 64;
	    }

		cout << "  i = " << i << "; q = " << q << "; r = " << r << "; c = " << c << endl;
		num = q;
	}

	// string output = "";
	// int i = stoi(s);
	// for(int j = 0; j <= 4; j++){
	// 	const int power = powers[j];
	// 	//if(i > power){
	// 		const int div = i / power;
	// 		if (div >= 1) {
	// 			const char c = (div) + 64;
	// 			cout << "  i = " << i << "; power = " << power 
	// 			     << "; div = " << div << "; c = " << c << endl;
	// 			output += c;
	// 			i -= div*power;
	// 			cout << "  i = " << i << endl;
	// 		}
	// 	//}
	// }

	
	return output;
}

string toLetter(const string & s){

	string output = "";
	int i = stoi(s);
	for(int j = 0; j <= 4; j++){
		int power = powers[j];
		if(i >= power){
			cout << "i = " << i << "; power = " << power << endl;
			int div = i / power;
			// if((i % power == 0)&&(power != 1)){
			// 	if(div > 1){
					
			// 		char c = div-1 + 64;
			// 		output += c;
			// 	}

			// 	for(int i = 0; i < 4 - j; i++){
			// 		output += 'Z';
			// 	}

			// 	break;

			
			// }
			// else{
			char c = (div) + 64;
			output += c;
			i -= div*power;
			// }
			



		}
		
		
	}

	
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

		
		return toLetter(col2) + col1;
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
	// int n;
	// cin >> n;
	// for(int i = 0; i < n; i++){
	// 	string s = "";
	// 	cin >> s;
	// 	cout << convert(s) << endl;
	// }
	// cout << convert("RZ228") << endl;
	// cout << convert("R228C494") << endl;
	cout << toLetterWw("1") << '\n' << endl;
	cout << toLetterWw("25") << '\n' << endl;
	cout << toLetterWw("26") << '\n' << endl;
	cout << toLetterWw("27") << '\n' << endl;

	// "ZZ"
	cout << toLetterWw("702") << '\n' << endl;

	// "AAA"
	cout << toLetterWw("703") << '\n' << endl;

	// "AAZ"
	cout << toLetterWw("728") << '\n' << endl;

	// "ABA"
	cout << toLetterWw("729") << '\n' << endl;

	
	

}
