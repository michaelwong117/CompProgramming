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
const int N = 2*1e5;

int n;
struct PT {
	int x, y, r;
	bool operator < (const PT &e) const {
		return this->x < e.x;
	}
};

vpi rect1 (N), rect2 (N);
vector<PT> points;




int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> rect1[i].f >> rect1[i].s >> rect2[i].f >> rect2[i].s;

		points.pb({rect1[i].f, rect1[i].s, i}); 

	}
	sort(all(points));
	pi curX = {points[0].x, points[0].y}, curY = rect2[points[0].r];

	for(int i = 1; i < n; i++){
		int X = {points[i].x, points[i].y}, Y = rect2[points[i].r];

		if(!intersect(curX, curY, X, Y)){

		}
	}

}
