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

// 0 indexed
template<class T>
class segtree1 {
public:
    bool sum = true; //true for sum queries
    int len;
    vector<T> seg, arr, delta;

    segtree1(int l) {
        len = l;
        seg.resize(l * 4);
        delta.resize(l * 4);
    }

    segtree1(vector<T> a) {
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

private:
    T f(T a, T b) { //change for different problems
        return a + b;
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
        if (l > b || r < a)  return numeric_limits<T>::min();

        if (l >= a && r <= b) return seg[node];
        
        
        int mid = (l + r) / 2;
        T n1 = query(node * 2, l, mid, a, b);
        T n2 = query(node * 2 + 1, mid + 1, r, a, b);
        if (n1 == numeric_limits<T>::min()) return n2;
        if (n2 == numeric_limits<T>::min()) return n1;
        return f(n1, n2);
    }

    void down(int node, int l, int r) {
        if(!delta[node]) return;
        if(sum) seg[node] += (r - l + 1) * delta[node];
        else seg[node] += delta[node];
        if(l != r) {
            delta[node * 2] += delta[node];
            delta[node * 2 + 1] += delta[node];
        }
        delta[node] = 0;
    }

    void inc(int node, int l, int r, int a, int b, int diff) {
        down(node, l, r);
        if(l > b || r < a) return;
        if(l >= a && r <= b) {
            delta[node] += diff;
            down(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        inc(node * 2, l, mid, a, b, diff);
        inc(node * 2 + 1, mid + 1, r, a, b, diff);
        seg[node] = f(seg[node*2], seg[node*2+1]);
    }
};

// 0 indexed
template<class T>
class segtree2 {
public:
    bool sum = false; //true for sum queries
    int len;
    vector<T> seg, arr, delta;

    segtree2(int l) {
        len = l;
        seg.resize(l * 4);
        delta.resize(l * 4);
    }

    segtree2(vector<T> a) {
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

private:
    T f(T a, T b) { //change for different problems
        return max(a,b);
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
        if (l > b || r < a)  return numeric_limits<T>::min();

        if (l >= a && r <= b) return seg[node];
        
        
        int mid = (l + r) / 2;
        T n1 = query(node * 2, l, mid, a, b);
        T n2 = query(node * 2 + 1, mid + 1, r, a, b);
        if (n1 == numeric_limits<T>::min()) return n2;
        if (n2 == numeric_limits<T>::min()) return n1;
        return f(n1, n2);
    }

    void down(int node, int l, int r) {
        if(!delta[node]) return;
        if(sum) seg[node] += (r - l + 1) * delta[node];
        else seg[node] += delta[node];
        if(l != r) {
            delta[node * 2] += delta[node];
            delta[node * 2 + 1] += delta[node];
        }
        delta[node] = 0;
    }

    void inc(int node, int l, int r, int a, int b, int diff) {
        down(node, l, r);
        if(l > b || r < a) return;
        if(l >= a && r <= b) {
            delta[node] += diff;
            down(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        inc(node * 2, l, mid, a, b, diff);
        inc(node * 2 + 1, mid + 1, r, a, b, diff);
        seg[node] = f(seg[node*2], seg[node*2+1]);
    }
};

ll d (pi p1, pi p2){
	return (abs(p1.f - p2.f) + abs(p1.s - p2.s))
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	// vi v = {1, 4, -1, 8, 3, 2, 4, 6};
	// segtree2<int> S(v); 
	// for(int i = 8; i <= 15; i++){
	// 	out(S.seg[i]);
	// }
	// out(S.query(0, 3));
	// S.inc(0, 2, 5);
	// out(S.query(0, 3));
	
	int n, q; cin >> n >> q;

	vi dist (n-1);
	vpi points;


	int x, y; cin >> x >> y;
	pi prev = {x,y};
	
	points.pb(prev);

	for(int i = 0; i < n-1; i++){
		cin >> x >> y; points.pb({x,y});
		dist[i] = abs(prev.f - x) + abs(prev.s - y);
		prev = {x,y};
	}
	segtree1<ll> sumDist(dist);
	dist[0] = 0; dist[n-2] = 0;
	segtree2<ll> maxDist(dist);

	for(int j = 0 ; j < q; j++){

		char c; cin >> c; 
		
		if(c == 'U'){
			int i; cin >> i >> x >> y; i--;
			
			points[i] = {x,y};
			
		}
		else{
			int u, v; cin >> u >> v;

			out(sumDist.query(u, v) - maxDist.query(u, v));
		}

	}




}



