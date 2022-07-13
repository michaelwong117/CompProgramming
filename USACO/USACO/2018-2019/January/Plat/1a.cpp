//g++-7 filename.cpp -std=c++14
//Michael Wong, USACO 2019 January Platinum
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

int n, k;

int a[3*100000+1];

// 0 indexed queries, 1-idxed array seg
// seg size n+1 always!!
template<class T>
class segtree {
public:
    bool sum = false; //true for sum queries
    int len;
    vector<T> seg, arr, delta;

    segtree(int l) {
        len = l;
        seg.resize(l * 4);
        delta.resize(l * 4);
    }

    segtree(vector<T> a) {
        len = a.size();
        seg.resize(len * 4);
        delta.resize(len * 4);
        arr = a;
        build(1, 0, len - 1);
    }

    T query(int a, int b) {
        return query(1, 0, len-1, a, b);
    }

    void inc(int a, int b, int diff) {
        inc(1, 0, len - 1, a, b, diff);
    }
    void inc2(int a, int b, int diff){
    		inc2(1, 0, len - 1, a, b, diff);
    }

private:
    T f(T a, T b) { //change for different problems
        return min(a, b);
    }
    T f2(T a, T b){
    	if(a.s == b.s) return min(a,b);
    	if(a.s < b.s) return a;
    	else return b;
    }

    void build(int node, int l, int r) {
        if (l > r) return;
        if (l == r) {
            seg[node] = arr[l]; return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        seg[node] = f(seg[node * 2], seg[node * 2 + 1]);
    }

    T query(int node, int l, int r, int a, int b) {
        down(node, l, r);
        if (l > b || r < a)  return {1e9, 1e9};

        if (l >= a && r <= b) return seg[node];
        
        
        int mid = (l + r) / 2;
        T n1 = query(node * 2, l, mid, a, b);
        T n2 = query(node * 2 + 1, mid + 1, r, a, b);
        return f(n1, n2);
    }

    void down(int node, int l, int r) {
        if(!delta[node].f) return;
        seg[node].f += delta[node].f;
        if(l != r) {
            delta[node * 2].f += delta[node].f;
            delta[node * 2 + 1].f += delta[node].f;
        }
        delta[node].f = 0;
    }

    void inc(int node, int l, int r, int a, int b, int diff) {
        down(node, l, r);
        if(l > b || r < a) return;
        if(l >= a && r <= b) {
            delta[node].f += diff;
            down(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        inc(node * 2, l, mid, a, b, diff);
        inc(node * 2 + 1, mid + 1, r, a, b, diff);
        seg[node] = f(seg[node*2], seg[node*2+1]);
    }
    void down2(int node, int l, int r) {
        if(!delta[node].s) return;
        seg[node].s += delta[node].s;
        if(l != r) {
            delta[node * 2].s += delta[node].s;
            delta[node * 2 + 1].s += delta[node].s;
        }
        delta[node].s = 0;
    }
    void inc2(int node, int l, int r, int a, int b, int diff) {
        down2(node, l, r);
        if(l > b || r < a) return;
        if(l >= a && r <= b) {
            delta[node].s += diff;
            down2(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        inc2(node * 2, l, mid, a, b, diff);
        inc2(node * 2 + 1, mid + 1, r, a, b, diff);
        seg[node] = f2(seg[node*2], seg[node*2+1]);
    }
};






int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("redistricting.in","r",stdin); freopen("redistricting.out","w",stdout);	
	//before you start coding, think it through
	cin >> n >> k;
	char c;
	for(int i = 0; i < n; i++){
		cin >> c;
		a[i] = ('G' == c ? 1: -1);
		// cout << c << " " << a[i] << endl;
	}
	vpi v(n+1), dp(n+1, {1e9, 1e9});

	dp[0] = {0,0};
	segtree<pi> S (v);

	for(int i = 0; i < n; i++){

		// cout << dp[i].f << " " << a[i] << endl << endl;

		S.inc(i,i, dp[i].f);
		// S.inc2(i,i, dp[i].s);

		
		//when you move forward a step, add it to all previous segments
		//so you can calculate majority (stored in second of pair)
		S.inc2(max(0,i-k+1), i, a[i]);

		//take the min of dp[i-k+1] + majority [i-k+1, i] for all k
		pi res = S.query(max(0,i-k+1), i); 

		dp[i+1] = {res.f + (res.s >= 0), 0};

		// for(int j = n; j <= 2*n; j++){
		// 	cout << j << " " << S.seg[j].f << " " << S.seg[j].s << endl;
		// 	cout << dp[j-n].f << " " << dp[j-n].s << endl;
		// 	cout << endl;
		// }
		// cout << endl << endl;

	}
	cout << dp[n].f << endl;
	// cout << dp[n].f << " " << dp[n].s << endl;


	// for(int i = 0; i < n; i++){
	// 	S.inc(i,i, -S.query(i,i).f); //eliminate both existings
	// 	S.inc2(i,i, -S.query(i,i).s);
	// 	S.inc2(i,i,i+1); //actually increment
	// 	//cout << S.query(i,i).s << endl;
	// }

	// for(int i = 1; i <= 2*n+2; i++){ // 1, 2 3, 4 5 6 7, ...
	// 	auto a = S.seg[i];
	// 	//cout << i << " " << a.s << " " << endl;
	// }


}
