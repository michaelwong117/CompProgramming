
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){

	string s;
	cin >> s;
	bool first = false, second = false, third = false;
	bool fourth = false, fifth = false;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == 'h'){
			first = true;
		}
		else if((s[i] == 'e')&&(first)){
			second = true;
		}
		else if((s[i] == 'l')&&(second)&&(!third)){
			third = true;
		}
		else if((s[i] == 'l')&&(third)){
			fourth = true;
		}
		else if((s[i] == 'o')&&(fourth)){
			fifth = true;
		}


	}

	if((first)&&(second)&&(third)&&(fourth)&&(fifth)){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	

}