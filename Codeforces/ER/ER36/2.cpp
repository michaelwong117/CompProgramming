#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cmath>

#define ll long long
#define fir first
#define sec second


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
	int n, pos, l, r, ans = 0, cl = 1, cr = 1;
	cin >> n >> pos >> l >> r;
	//if the left is closer
	if(l == 1){
		cl = 0;
	}
	if(r == n){
		cr = 0;
	}
	if(cl == 0 && cr == 0){
		cout << 0 << endl;
		return 0;
	}
	else if(cr == 0){
		ans += abs(pos - l) + 1;
	}
	else if(cl == 0){
		ans += abs(pos - r) + 1;
	}
	else if(l == r){
		ans += abs(pos - l) + 2;
	}
	else if(pos - l <= abs(pos - r)){
		ans += abs(pos - l) + 1;
		ans += abs(r - l) + 1;
	}
	else{
		ans += abs(pos - r) + 1;
		ans += abs(l - r) + 1;
	}
	cout << ans << endl;

	
}