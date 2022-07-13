#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
#include <fstream>

using namespace std;

int getSubsequences(string s){

	int count = 0;
	string a = "";
	for(int i = 0; i < s.length(); i++){
		for(int j = i+1; j < s.length(); j++){
			for(int k = j+1; k < s.length(); k++){
				a += s[i];
				a += s[j];
				a += s[k];

				// cout << a << endl;
				if(a == "QAQ"){
					count++;
				}
				a.clear();
			}
		}
	}
	return count;
}


int main(){
	string s;
	cin >> s;
	cout << getSubsequences(s) << endl;
	// cout << getSubsequences("QAQQQZZYNOIWIN") << endl;


}