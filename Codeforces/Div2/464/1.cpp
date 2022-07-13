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

int n;

vector<int> v;

bool get(int org, int going, int recur){
	// cout << org << " " << going << " " << recur << endl;
	if(org == going && recur == 2) return true;
	if(org == going && recur == 1) return false;
	if(recur == 2) return false;
	else return get(org, v[going], recur+1);
	return false;
}
//set tab size to 3

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	cin >> n;
	v.resize(n+1);
	for(int i = 1; i <= n; i++){
		int a;
		cin >> a;
		v[i] = a;
	}
	for(int i = 1; i < v.size(); i++){
		if(get(i, v[i], 0)){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	
}