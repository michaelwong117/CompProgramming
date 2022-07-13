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
#define pq priority_queue<int, vector<int>, greater<int>> //min pq
#define endl '\n'
#define out(x) cout << x << endl
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

int n, k, x, y, a, b;

map<int, int> H;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		cin >> x >> y >> a >> b;
		int cur = 0;
		for(int j = 0; j < y; j++){
			cur = (cur + a) % n;
			H[(cur + b) % n] += x;
			// cout << (cur+b) % n << " " << x << endl;
		}
	}
	deque<pi> vacant;
	auto beg =  *H.begin();
	vacant.pb({0, beg.f});
	int last = beg.f+beg.s;
	int idx = 0;
	bool over = 0;
	for(auto next: H){

		if(beg == next) continue;

		if(over){ // can only use first vacant
			for(int i = idx; i < vacant.size(); i++){
				if(vacant[i].f )
			}
		}



		else if(next.f > last){
			vacant.pb({last, next.f});
			last = next.f + next.s;
		}
		else if(next.f <= last){
			last += next.s;
		}
		if(last >= n){ //crossing over to next set of stalls (n-1 -> 0)
			over = 1;
			int diff = last % n + 1;
			while(!vacant.empty() && vacant[0].s - vacant[0].f <= diff){
				vacant.pop_front();
				diff -= (vacant[0].s - vacant[0].f);
			}
			assert(!vacant.empty());
			vacant[0].f += diff; 

		}
		

	}
	// cout << vacant[0].f << endl;
	// cout << last.f << " " << last.s << endl;
	// for(auto elem: H){
	// 	cout << elem.f << " " << elem.s << endl;
	// }
}
