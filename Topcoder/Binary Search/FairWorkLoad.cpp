//g++-7 filename.cpp -std=c++14
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define pq priority_queue<int, vector<int>, greater<int>>
#define mpq priority_queue<int>
#define endl '\n'
#define out(x) cout << x << endl
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

class FairWorkload {
	public:
		int getMostWork(vi &fold, int w);         
};
int work(int mx, vi &fold){
	int w = 0, pos = 0;
	while(pos < fold.size()){
		int cur = 0;
		while(cur <= mx-fold[pos] && pos < fold.size()){
			cur += fold[pos]; pos++;
		}
		w++;
	}
	return w;
}

int FairWorkload::getMostWork(vi &fold, int w) {
	int hi = 0, lo = 0;
	rep(i, fold.size()){ hi+=fold[i]; lo = max(lo, fold[i]);}
	if(w >= fold.size()) return lo;
	while(lo < hi){
		int mid = lo+(hi-lo)/2;
		if(work(mid, fold) <= w) hi = mid;
		else lo=mid+1;
	}
   return lo;
}

// int main(){
// 	ios_base::sync_with_stdio(false); cin.tie(0);
// 	freopen("filename.in","r",stdin); //freopen("filename.out","w",stdout);
	// vi v = { 568, 712, 412, 231, 241, 393, 865, 287, 128, 457, 238, 98, 980, 23, 782 };
	// int in = 4;
	// FairWorkload F;
	// int res = F.getMostWork(v, in); out(res);

// }