
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main(){
	string s;
	bool valid = true;
	cin >> s;
	if(islower(s[0])){
		for(int i = 1; i < s.length(); i++){
			if(!isupper(s[i])){
				valid = false;
				cout << s << endl;

				break;
			}
		}
		if(valid){
			s[0] = toupper(s[0]);

			for(int i = 1; i < s.length(); i++){

				s[i] = tolower(s[i]);
			}

			cout << s << endl;
		}
	
	}
	else{
		for(int i = 0; i < s.length(); i++){
			if(!isupper(s[i])){
				valid = false;
				cout << s << endl;
				break;
			}
		}
		if(valid){
			for(int i = 0; i < s.length(); i++){
				s[i] = tolower(s[i]);
			}

			cout << s << endl;
		}
	}


}