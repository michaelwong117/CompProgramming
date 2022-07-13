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
#define pq priority_queue<int, vector<int>, greater<int>>
#define heap priority_queue<int>
#define vi vector<int>



typedef long long ll;
typedef pair<int, string> pis;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	int n;
	cin >> n;
	vector<int> d;
	set<int> s;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(a != 0 && s.find(a) == s.end()){
			d.pb(a);
			s.insert(a);
		}
	}
	sort(all(d));
	int count = 0;
	for(int i = 0; i < d.size(); i++){

		count++;
	}
	cout << count << endl;
	
}