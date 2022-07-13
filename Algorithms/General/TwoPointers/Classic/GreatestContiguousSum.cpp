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
	vector<int> v = {-1001,5,-10,11,-8,8,-1,2,-20,4};
	int maxSum = -999999999;
	// for(int i = 0; i < v.size(); i++){
	// 	for(int j = i+1; j < v.size(); j++){
	// 		int cur = 0;
	// 		for(int k = i; k <= j; k++){
	// 			cur += v[k];
	// 		}
	// 		maxSum = max(maxSum, cur);
	// 	}
	// }
	int cur = 0;
	for(int i = 0; i < v.size(); i++){
		cur = max(cur + v[i], 0);
		maxSum = max(maxSum, cur);
	}	
	cout << maxSum << endl;

	
}