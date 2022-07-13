#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <numeric>
#include <cmath>

#define ll long long
#define fir first
#define sec second
#define MOD 1e9 + 7

using namespace std;

typedef pair<int, string> pis;
typedef pair<int,int> pii;

//set tab size to 3

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	vector<int> v = {1, 1, 1, 1, 1, 1, 1, 2, 3};
	int minR = 100000000, k = 3;
	for(int i = 0; i < v.size(); i++){
		if(i+k > v.size()) break;
		int r = i;
		set<int> s;
		while(s.size() < k && r < v.size()){
			s.insert(v[r]);
			r++;
		}
		minR = min(minR, r-i);
		if(r == v.size()) cout << -1 << endl; return 0;
	}

	cout << minR << endl;
	

	
	
}