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
int N, a[mx];
vpi v;
template<class T, int SZ> struct BIT {
    T bit[SZ+1];
    BIT() { memset(bit,0,sizeof bit); }
    void upd(int k, T val) { // add val to index k
        while(k <= SZ){
            bit[k] += val; k += k&-k;
        }
    }
    T query(int k) {
        T sum = 0;
        while(k >= 1){
            sum += bit[k];
            k -= k&-k;
        }
        return sum;
    }
    T query(int l, int r) { return query(r)-query(l-1); } // range query [l,r]
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("bphoto.in"); ofstream fout("bphoto.out");
	fin >> N;
	BIT<int,mx> b;
	for(int i = 0; i < N; i++){
		fin >> a[i]; v.pb({a[i],i+1});
	}
	sort(v.rbegin(),v.rend());
	int res = 0;
	for(int i = 0; i < N; i++){
		int l = b.query(v[i].s), r = i-l;
		if(max(l,r) > min(l,r)*2) res++;
		b.upd(v[i].s,1);
	}
	fout << res << endl;




	
}