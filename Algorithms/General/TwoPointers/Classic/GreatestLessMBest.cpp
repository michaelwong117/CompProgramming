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
	for(int i = 0; i < N; i++){
		cin >> v[i];
	}
	int start = 0, end = 0, curSum = 0, maxSum = 0;
	while(start < N){
		while(end < N && curSum + v[end] <= M){
			curSum += v[end];
			end++;
		}
		maxSum = max(maxSum, curSum);
		curSum -= v[start];
		start++;
	}
	cout << maxSum << endl;
	
}