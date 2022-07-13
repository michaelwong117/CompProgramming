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
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<ll,ll> pl;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("taming.in");
	ofstream fout("taming.out");
	int N;
	fin >> N;
	int breaks[N];
	for(int i = 0; i < N; i++){
		fin >> breaks[i];
	}
	if(breaks[0] > 0)
	{
		cout << -1 << endl;
		return 0;
	}
	breaks[0] = 0;
 	int past = -1, req = 0, pos = 0;
	for(int i = N-1; i >= 0; i--){
		if(past != -1 && breaks[i] != past && breaks[i] != -1){
			fout << -1 << endl;
			return 0;
		}
		if(past == -1){
			past = breaks[i];
		}
		if(breaks[i] == -1){
			breaks[i] = past;
		}
		if(breaks[i] == -1){
			pos++;
		}
		if(breaks[i] == 0){
			req++;
		}
		if(past > -1) past--;


	}
	fout << req << " " << req+pos << endl;

	
}
