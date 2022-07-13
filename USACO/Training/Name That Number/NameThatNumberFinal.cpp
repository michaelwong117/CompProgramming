/*
ID: michaelwong11
PROG: namenum
LANG: C++14     
*/

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

typedef pair<int,int> pii;
typedef pair<int, string> pis;

map<int, string> m;


bool check(string s, ll n){
	string temp = to_string(n);
	if(s.length() != temp.length()){
		return false;
	}
	for(int i = 0; i < temp.length(); i++){
		// cout << m[temp[i]] << endl;
		// cout << temp[i] <<  " " << m[temp[i] - '0'] << endl;
		string key = m[temp[i] - '0'];
		if(key.find(s[i]) == string::npos){
			return false;
		}
	}
	return true;
}
int main() {

	ofstream fout("namenum.out");
	ifstream fin("namenum.in");
	ifstream in("dict.txt"); 
	ll N, c = 0;
	fin >> N;
	m[2] = "ABC";
	m[3] = "DEF";
	m[4] = "GHI";
	m[5] = "JKL";
	m[6] = "MNO";
	m[7] = "PRS";
	m[8] = "TUV";
	m[9] = "WXY";
	for(int i = 0; i < 4617; i++){
		string s;
		in >> s;
		if(check(s, N)){
			c++;
			fout << s << endl;
		}
	}
	if(c == 0){
		fout << "NONE" << endl;
	}
}