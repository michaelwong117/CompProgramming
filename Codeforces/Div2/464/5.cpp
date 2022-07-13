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
	int q;
	fin >> q;
	multiset<int> s;
	for(int i = 0; i < q; i++){
		int t;
		fin >> t;
		if(t == 1){
			int a;
			fin >> a;
			s.insert(a);
		}
		else{
			int a;
		}
	}
	
	
	
}