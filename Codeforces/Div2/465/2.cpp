//g++ filename.cpp -std=c++14 -DH
#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define endl '\n'
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1e9 + 7
#define pq priority_queue

typedef long long ll;
typedef pair<int, string> pis;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
 	int n, count = 0;
	string s;
	cin >> n >> s;
	pii pos = {0, 0}, past, check, othercheck;
	bool ready = 0;
	for(int i = 0; i < s.length(); i++){
		pii org = pos;
		if(s[i] == 'R'){
			pos.f++;
		}
		else{
			pos.s++;
		}
		if(ready){
			if(pos != check && pos != othercheck && pos != past){
				count++;
			}
		}
		ready = 0;
		if(pos.f == pos.s){
			ready = 1;
			past = org;
			check.f = past.f+1;
			check.s = past.s+1;
			othercheck.f = past.f-1;
			othercheck.f = past.s-1;
		}
	}
	cout << count << endl;
	
}