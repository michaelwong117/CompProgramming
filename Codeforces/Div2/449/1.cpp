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
using namespace std;



string Sreplace(string s, int l, int r, char c1, char c2){
	// cout << s[l-1] << " " << s[r-1] << endl;
	for(int i = l-1; i <= r-1; i++){
		// cout << s[i] << " " << c1 << endl;
		if(s[i] == c1){
			s[i] = c2;
		}
	}
	return s;


}

int main(){
	// ifstream fin("input.in");
	int n, m;
	string s;
	cin >> n >> m >> s;
	for(int i = 0; i < m; i++){
		int l, r;
		char c1, c2;
		cin >> l >> r >> c1 >> c2;
		s = Sreplace(s, l, r, c1, c2);
	}
	cout << s << endl;
}