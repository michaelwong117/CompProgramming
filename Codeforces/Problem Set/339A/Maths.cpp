
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main(){ 

	string s, output = "";
	vector<int> v;
	cin >> s;
	for(auto ch: s){
		if(ch != '+'){
			v.push_back(ch - '0');
		}
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++){
		output +=  to_string(v[i]);
		if(i != v.size()-1){
			output += '+';
		}
		
	}

	cout << output << endl;

}