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
 
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
const int mx = 1e5;
int pre[mx], nex[mx], res[mx];
vpi sf;
multiv b;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("snowboots.in"); ofstream fout("snowboots.out");
	int N, B; fin >> N >> B;
	for(int i = 0; i < N; i++){
		pre[i] = i-1; nex[i] = i+1;
		int x; fin >> x; sf.pb({x,i});
	}
	for(int i = 0; i < B; i++){
		int w, st; fin >> w >> st;
		b.pb({w,st,i});
	}
	sort(sf.rbegin(), sf.rend()); sort(b.rbegin(),b.rend());
	int j = 0, mxd = 1;
	for(int i = 0; i < B; i++){
		while(j < sf.size()-1 && b[i][0] < sf[j].f){
			int k = sf[j].s;
			nex[pre[k]] = nex[k];
			pre[nex[k]] = pre[k];
			mxd = max(mxd, (nex[k]-pre[k]));
			j++;
		}
		if(mxd <= b[i][1]) res[b[i][2]] = 1;
	}
	for(int i = 0; i < B; i++) fout << res[i] << endl;


}