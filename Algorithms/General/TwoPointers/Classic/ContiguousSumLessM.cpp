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
	int N, M;
	cin >> N >> M;
	vector<int> v (N);
	vector<int> sums (N+1);
	for(int i = 0; i < N; i++){
		cin >> v[i];
	}
	sums[1] = v[0];
	for(int i = 1; i < v.size(); i++){
		sums[i+1] = sums[i] + v[i];
	}
	// for(auto a: sums){
	// 	cout << a << endl;
	// }
	int start = 1, end = 1, curSum = 0, maxSA = 0;
	while(start < sums.size() && end < sums.size()){
		while(sums[end] - sums[start-1] > M && start < sums.size()){
			start++;
		}
		maxSA = max(maxSA, sums[end] - sums[start-1]);
		// cout << start << endl;
		// cout << end << " " << start << endl;
		if(end < start){
			end = start;
		}
		else{
			end++;
		}
		// cout << sums.size() << " " << start << " " << end << endl;
			
	}
	cout << maxSA << endl;
	
}