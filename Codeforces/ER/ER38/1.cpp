//g++ filename.cpp -std=c++14 -DH

#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1e9 + 7

typedef long long ll;
typedef pair<int, string> pis;
typedef pair<int,int> pii;

//set tab size to 3

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	int n;
	string s;
	cin >> n;
	cin >> s;
	while(1){
		bool lc = 0, cons = 0;
		for(int i = 0; i < s.length(); i++){
			char c = s[i];
			if(lc){
				lc = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
				if(lc){
					s.erase(s.begin()+i);
					i--;
					cons = 1;
				}
			}
			else{
				lc = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
			}

		}
		if(!cons) break;
	}
	cout << s << endl; 
	
}