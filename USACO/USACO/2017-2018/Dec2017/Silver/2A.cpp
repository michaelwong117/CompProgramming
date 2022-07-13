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
#define fir first
#define sec second


using namespace std;

typedef pair<int, string> pis;
typedef pair<int,int> pii;

struct cow {
	int day;
	int id;
	int change;
};

//set tab size to 3

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("measurement.in");
	ofstream fout("measurement.out");
	int N, G;
	fin >> N >> G;
	vector<cow> v (N); 
	for(int i = 0; i < N; i++){
		fin >> v[i].day >> v[i].id >> v[i].change;

	}
	sort(v.begin(), v.end(), [](cow a, cow b) {
		return a.day < b.day;
	});
	map<int, int, greater<int> > cnts;
	cnts[0] = N + 1;

	int result = 0;
	map<int, int> mp;
	for (auto& m : v) {
	 int& ref = mp[m.id];
	 // cout << ref << " " << cnts.begin()->first << endl;
	 bool wastop = ref == cnts.begin()->first;
	 int wascnt = cnts[ref]--;
	 if (wascnt == 1) {
	   cnts.erase(ref);
	 }

	 ref += m.change;

	 int iscnt = ++cnts[ref];
	 bool istop = ref == cnts.begin()->first;
	 if (wastop) {
	   if (!istop || wascnt != 1 || iscnt != 1) {
	     ++result;
	   }
	 } else if (istop) {
	   ++result;
	 }
	}
	fout << result << endl;

	return 0;
}


	
