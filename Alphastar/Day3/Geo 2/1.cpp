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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	int n; cin >> n;
	vector<array<int,4>> info (n);
	multiv H, V;
	rep(i, n){
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

		H.pb({y1,x1,i}); V.pb({x1,y1,i});
		H.pb({y2,x2,i}); V.pb({x2,y2,i});

		info[i] = {x1, y1, x2, y2};

	}
	ll total = 0;

	sort(all(H)); sort(all(V));

	vector<bool> rect (n);

	int overlapV = 1, prev;
	rect[V[0][2]] = 1;
	for(int i = 1; i < V.size(); i++){
		int cur, len = 0;
		int idxV = V[i][2];
		if(rect[idxV]){
			rect[idxV] = 0; overlapV--;
			//cur is endpoint of rectangle idxV
			cur = info[idxV][2];
		}
		else{
			rect[idxV] = 1; overlapV++; 
			//cur is startpoint of rectangle idxV
			cur = V[i][0];
		}
		//if i == 0, there is no len and cutlen doesn't matter
		if(overlapV > 0 && i != 0) len = cur - prev;
		prev = cur;

		if(i == 0) continue;
		//cout << len << endl;
		vector<bool> rectH (n);
		int overlapH = 0, cutlen = 0, prevE = -1e9;
		for(int j = 0; j < H.size(); j++){
			int curH, idxH = H[j][2], diff = 0;
			if(!rect[idxH] && idxH != i) continue;
			if(rectH[idxH]){
				rectH[idxH] = 0; diff--;
				//curH is endpoint of rectangle idxH
				curH = info[idxH][1];
			}
			else{
				rectH[idxH] = 1; diff++; 
				//curH is startpoint of rectangle idxH
				curH = info[idxH][3];
			}
			if(overlapH > 0 && prevE != -1e9) cutlen += curH - prevE;

			overlapH += diff;
			prevE = curH;
		}
		total += (ll) cutlen * (ll) len;

	}
	// vector<bool> rectH (n);
	// int overlapH = 0, cutlen = 0, prevE;
	// for(int j = 0; j < H.size(); j++){
	// 	int curH, idxH = H[j][2];
	// 	//if(!rect[idxH] && idxH != i) continue;
	// 	if(rectH[idxH]){
	// 		rectH[idxH] = 0; overlapH--;
	// 		//curH is endpoint of rectangle idxH
	// 		curH = info[idxH][1];
	// 	}
	// 	else{
	// 		rectH[idxH] = 1; overlapH++; 
	// 		//curH is startpoint of rectangle idxH
	// 		curH = info[idxH][3];
	// 	}
	// 	if(overlapH > 0 && j != 0){
	// 		cutlen += curH - prevE;
	// 		cout << cutlen << endl;
	// 	}
	// 	prevE = curH;
	// }
	out(total);


}