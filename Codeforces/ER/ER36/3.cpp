#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

#define ll long long
#define fir first
#define sec second


using namespace std;

typedef pair<int, string> pis;
typedef pair<int,int> pii;

//set tab size to 3

bool smallerorequal(string &a, string &b){
	for(int i = 0; i < a.length(); i++){
		if ((a[i] - '0') > (b[i] - '0')){
			return false;
		}
	}
	return true;
}
string fix(string start, int length){
	for(int i = 0; i < length - start.length(); i++){
		start += "0";
	}
	return start;
}

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	string a, b;
	fin >> a >> b;
	map<char, int> digitsleft;
	for(int i = 0; i < a.length(); i++){
		if(digitsleft.count(a[i]) == 0){
			digitsleft[a[i]] = 1;
		}
		else{
			digitsleft[a[i]]++;
		}
	}
	bool leading = 0;
	string start = "", current = "";
	for(int i = 0; i < a.length(); i++){
		if(leading){
			for(int j = 0; j < 10; j++){
				if(digitsleft[j + '0'] > 0){
					digitsleft[j + '0']--;
					start += j + '0';
					start = fix(start, )

				}
			}
		}
	}




	
}