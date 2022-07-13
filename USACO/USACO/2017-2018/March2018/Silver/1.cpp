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
#define mpq priority_queue<int>
 
typedef long long ll; typedef vector<int> vi;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
int N, c = 0;
vi v;
vpi temp;
int main(){
	ifstream fin("sort.in"); ofstream fout("sort.out");
	fin >> N; v.resize(N); temp.resize(N);
	for(int i = 0; i < N; i++) fin >> v[i];
	for(int i = 0; i < N; i++){
		temp[i].f = v[i]; temp[i].s = i;
	}
	sort(all(temp));
	for(int i = 0; i < N; i++) c = max(c, abs(temp[i].s-i));
	fout << c+1 << endl;

} 