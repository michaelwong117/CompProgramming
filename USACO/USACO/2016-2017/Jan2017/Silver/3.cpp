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
#define MOD 1000000007
#define pq priority_queue

typedef long long ll;
typedef pair<int, string> pis;
typedef pair<int,int> pii;

string shift(string &s){
	string copy = "";
	copy += s[s.size()-1];
	for(int i = 0; i < s.size()-1; i++){
		copy += s[i];
	}
	return copy;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("cowcode.in");
	ofstream fout("cowcode.out");
	ll N;
	string s;
	string big = "";
	fin >> s >> N;
	big += s;
	if(N <= s.size()){
		fout << s[N-1] << endl;
		return 0;
	}
	while(N > p)
	while(big.size() < N){
		big += shift(big);
	}
	
	fout << big[N-1] << endl;


	
	
}