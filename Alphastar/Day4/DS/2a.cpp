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
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n >> k;
	for(int i = 0; i < k; i++){
		cin >> x >> y >> a >> b;
		int cur = 0;
		for(int j = 1; j <= y; j++){
			cur = (cur + a) % n;
			H[(cur + b) % n] += x;

		}
	}
	deque<pi> vacant;
	auto beg = *H.begin();
	if(beg.f > 0) vacant.pb({0, beg.f});
	int last = beg.f + beg.s - 1;
	bool Over = 1;
	for(auto next: H){

		if(beg == next) continue;

		if(next.f > last){
			//0-2 are filled and you are 4:5
			vacant.pb({last+1, next.f}); //3 is now vacant, represented by {3, 4}
			last = next.f + next.s - 1; //4-8 are filled; last becomes 8
		}
		else if(next.f <= last){
			last += next.s;
		}
		if(last >= n){
			int diff = next.s;
			if(Over){
				Over = 0; 
				diff -= (n - 1 - (last - next.s));
			}
			//don't have to worry about diff = 0 cases or vacant is empty bc
			//there has to be at least one stall unoccupied
			while(!vacant.empty() && vacant[0].s - vacant[0].f <= diff){
				diff -= (vacant[0].s - vacant[0].f); vacant.pop_front();
			}
			assert(!vacant.empty()); //if vac is empty, you messed up
			vacant[0].f += diff;

		}
		// 	int diff = next.s;
		// 	if(last < n && last+next.s >= n) diff -= (n - 1 - last);
		// 	last += next.s; //if 0-5 are filled and you are 2:3, you will fill 6-8
		// 	if(last >= n){ //once condition is true, will always be true for rest of program
		// 		//no preferred stall can be >= n
		// 		while(!vacant.empty() && vacant[0].s - vacant[0].f <= diff){
		// 			diff -= (vacant[0].s - vacant[0].f);
		// 			vacant.pop_front();
		// 		}
		// 		// cout << diff << " " << vacant[0].f << " " << vacant[0].s << endl;
		// 		assert(!vacant.empty());
		// 		// cout << vacant[0].f << " " << diff << endl;
		// 		vacant[0].f += diff;

		// 	}
		// }


	}
	cout << vacant[0].f << endl;
	// for(int i = 0; i < vacant.size(); i++){
	// 	cout << vacant[i].f << " " << vacant[i].s << endl;
	// }
	// cout << vacant[0].f << " " << vacant[0].s << endl;
	// cout << last.f << " " << last.s << endl;
	// for(auto elem: H){
	// 	cout << elem.f << " " << elem.s << endl;
	// }
}
