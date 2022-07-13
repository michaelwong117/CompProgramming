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

typedef long long ll;
typedef pair<int, string> pis;
typedef pair<int,int> pii;

int N, Tmax;
vector<int> d; 

bool possible(int K){
	pq q;
	int maxTime = 0, lastTime = 0;
	for(int i = 0; i < N; i++){
		if(q.size() == K){
			lastTime = q.top();
			q.pop();
		}
		if(lastTime + d[i] > Tmax) return false;
		q.push(lastTime+d[i]);
	}
	return true;
}

int bsearch(int Tmax) {
	if (!possible(N-1)){
		return N;
	}
	int lo = 1, hi = N;
	while(lo < hi) {
		int mid = (lo + hi) / 2;
		if (possible(mid)){
			hi = mid;
		}
		else{
			lo = mid+1;
		}
	}
	return lo;
}
int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("cowdance.in");
	ofstream fout("cowdance.out");
	fin >> N >> Tmax;
	d.resize(N);
	for(int i = 0; i <= N; i++){
		fin >> d[i];
	}
	fout << bsearch(Tmax) << endl;

	
}