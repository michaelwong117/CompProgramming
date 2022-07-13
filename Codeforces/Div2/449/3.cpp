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

string out;
string f = "What are you doing at the end of the world? Are you busy? Will you save us?";
string a = "What are you doing while sending "; // add ? to this
string b = " Are you busy? Will you send ";
ll k;

vector<int> v;

string findK(ll n){
	if(n == 0){
		return f;
	}
	string r = "\"" + findK(n-1) + "\"" + '?';
	out =  a + r + b + r;
	return out;

}

ll findKlen(ll n){
	if(n == 0){
		v.push_back(f.length());
	}
	v.push_back(l + 3 + findKlen(n-1) + b.length() + 3 + findKlen(n-1));
}


int main(){
	ifstream fin("input.in");
	int q;
	fin >> q;
	for(int i = 0; i < q; i++){
		ll n;
		fin >> n >> k;
		out = findK(n);
		// cout << out << endl;
		if(out.length() <= k){
			cout << ".";
		}
		else{
			cout << out[k-1];
		}
		
	}
	cout << endl;
	cout << f.length() << " " << a.length() << " " << b.length() << endl;
	// cout << findK(1) << endl;

	
}