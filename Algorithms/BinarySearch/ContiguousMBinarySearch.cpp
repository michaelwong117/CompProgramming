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
	ll N, M;
	cin >> N >> M;
	vector<ll> v (N);
	vector<ll> sums (N+1);
	for(ll i = 0; i < N; i++){
		cin >> v[i];
	}
	sums[1] = v[0];
	for(ll i = 1; i < v.size(); i++){
		sums[i+1] = sums[i] + v[i];
	}
	ll maxSum = 0;
	for(ll i = 1; i < sums.size(); i++){
		// sums[endIndex] - sums[startIndex-1] <= M and sums[endIndex+1] - sums[startIndex-1] > M
		ll startIndex = i;
		ll bs = upper_bound(sums.begin(), sums.end(), M+sums[startIndex-1])-sums.begin()-1;
		// cout << bs << " " << sums[bs] << endl;
		if(bs == -1) continue;
		maxSum = max(maxSum, sums[bs] - sums[startIndex-1]);
	}
	cout << maxSum << endl;
	
}