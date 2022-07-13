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

int N, B;

int move(pii curBoot, vector<int> &snowfall, int cur){
	int snowMax = curBoot.f, stepSize = curBoot.s, maxc = cur;
	if(cur+stepSize >= N) return N;
	for(int j = 1; j <= stepSize; j++){
		// cout << snowfall[cur+j-1] << " " << snowMax << endl;
		if(snowMax >= snowfall[cur+j-1]){
			maxc = cur+j;
		}

	}
	return maxc;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("snowboots.in");
	ofstream fout("snowboots.out");
	fin >> N >> B;
	queue<pii> boots;
	vector<int> snowfall (N);
	for(int i = 0; i < N; i++){
		fin >> snowfall[i];
	}
	for(int i = 0; i < B; i++){
		int maxSnow, maxStep;
		fin >> maxSnow >> maxStep;
		boots.push({maxSnow, maxStep});
	}
	int cur = 1, discard = 0;
	while(cur < N){
		pii curBoot = boots.front();
		int m = move(curBoot, snowfall, cur);
		if(m > cur){
			cur = m;
		}
		else{
			discard++;
			boots.pop();
		}
	}
	fout << discard << endl;

	
}