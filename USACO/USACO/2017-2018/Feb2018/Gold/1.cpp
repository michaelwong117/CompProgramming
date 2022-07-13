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
 
typedef long long ll; typedef vector<int> vi;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

const int maxN = 1e5;

int N, B, SF[maxN];

bool traverse(pi cur){
	int b = cur.f, step = cur.s, pos = 0;
	while(pos < N-1){
		bool stuck = 1;
		for(int i = pos+step; i >= pos+1; i--){
			if(i >= N-1) return true;
			if(b >= SF[i]){
				pos = i;
				stuck = 0;
				break;
			}
		}
		if(stuck) return false;
	}
	return true;

}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("snowboots.in"); ofstream fout("snowboots.out");
	fin >> N >> B;
	for(int i = 0; i < N; i++){
		fin >> SF[i];
	}
	for(int i = 0; i < B; i++){
		pi cur;
		fin >> cur.f >> cur.s;
		fout << traverse(cur) << endl;
	}	
}