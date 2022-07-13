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
	cin >> n;
	vector<int> v(n);
	int s = 1, end = 1000000, count = 0;
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int i = 0, j = v.size()-1;
	while(i <= j){
		while(s >= v[i] && i < v.size()){
			// cout << "s " << s << " " << v[i] << endl;
			i++;
		}
		while(end <= v[j] && j >= 0){
			// cout << "end " << end << " " << v[j] << endl;
			j--;
		}
		if(i > j) break;
		// cout << "s " << s << " " << v[i] << endl;
		// cout << "end " << end << " " << v[j] << endl;

		if(v[i] - s < end - v[j]){
			count += abs(v[i] - s);
			end -= abs(v[i] - s);
			s = v[i];
		}
		else{
			count += abs(end - v[j]);
			s += abs(end - v[j]);
			end = v[j];
		}
		// cout << "afters " << s << " " << i << endl;
		// cout << "afterend " << end << " " << j <<endl;
	
	}
	cout << count << endl;
	
}