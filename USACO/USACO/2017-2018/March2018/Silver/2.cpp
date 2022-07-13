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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("lemonade.in"); ofstream fout("lemonade.out");
	fin >> N; v.resize(N);
	for(int i = 0; i < N; i++) fin >> v[i];
	sort(all(v),greater<int>());
	for(int i = 0; i < N; i++){	
		if(v[i] >= i) c++;
	}
	fout << c << endl;
}