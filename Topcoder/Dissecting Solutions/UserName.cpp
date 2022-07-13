#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
#include <fstream>

using namespace std;

string removeEnd(string s){
	for(int i = s.size()-1; i >=0; i--){
		if(isalpha(s[i])){
			return s.substr(0, i+1);
		}
	}
	return s;
}
string getEnd(string s){
	for(int i = s.size()-1; i >=0; i--){
		if(isalpha(s[i])){
			return s.substr(i+1, s.size()-i-1);
		}
	}
	return s;
}


class UserName {
	public:
		string newMember(string a[], string s);


};

string UserName::newMember(string a[], string s){
	s = removeEnd(s);
	int j = 0, min = 9999999;
	// cout << size << endl;
	for(int i = 0; i < a.size(); i++){
		cout << removeEnd(a[i]) << " " << s << endl;
		if(removeEnd(a[i]) == s){
			cout << getEnd(a[i]) << endl;
			if(!getEnd(a[i]).empty() && stoi(getEnd(a[i])) < min){
				min = stoi(getEnd(a[i]));
			} 

		}
	}
	if(min == 9999999){
		return s;
	}
	return s + to_string(min);


}

int main(){
	UserName u;
	string a[] = {"MasterOfDisaster", "TygerTyger1", "DingBat", "Orpheus", "TygerTyger", "WolfMan", "MrKnowItAll"};
	string output = u.newMember(a, "TygerTyger");
	cout << output << endl;
	// cout << getEnd("TylerTyler") << endl;
	// cout << "start" << getEnd("TylerTyler1") << "end" << endl;
}