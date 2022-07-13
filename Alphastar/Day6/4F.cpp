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
	return (abs(p1.f - p2.f) + abs(p1.s - p2.s));
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("marathon.in","r",stdin); freopen("marathon.out","w",stdout);	
    //ifstream fin("10.in");

	ll n, q; cin >> n >> q;

    vl dist (n+10); //dist[1] is dist from 1 to 2
    vl skip (n+10); //skip[1] is amount saved from skipping 2
    vector<pl> points (n+10); //points[1] is point 1

    for(int i = 1; i <= n; i++){
        ll x, y; cin >> x >> y; 
        points[i] = {x,y};
    }
    for(int i = 1; i < n; i++){
        dist[i] = d(points[i], points[i+1]);
    }
    for(int i = 1; i < n-1; i++){
        skip[i] = dist[i]+dist[i+1]-d(points[i],points[i+2]);
    }

    // for(int i = 1; i < points.size(); i++){
    //     cout << points[i].f << " " << points[i].s << endl;
    // }
    // for(int i = 0; i < dist.size(); i++){
    //     cout << dist[i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < skip.size(); i++){
    //     cout << skip[i] << " ";
    // }
    // cout << endl;

	segtree1<ll> sums (dist);
	segtree2<ll> saved (skip);

	for(int j = 0; j < q; j++){

		char c; cin >> c; 
		
		if(c == 'U'){
			ll i, x, y; cin >> i >> x >> y; 

            ll dist1, dist2;
            // if(i == 1 && i+1 <= n){
            //     ll ndist = d({x,y},points[i+1]);
            //     ll cdist = sums.query(1,1);
            //     sums.inc(1,1,-cdist+ndist); 
            // }
            // if(i == n && i-1 >= 1){
            //     ll ndist = d(points[i-1],{x,y});
            //     ll cdist = sums.query(n-1,n-1);
            //     sums.inc(n-1,n-1,-cdist+ndist); 
            // }
            //changed i -> i+1
            if(i+1 <= n){
                dist1 = d({x,y}, points[i+1]);
                ll cdist = sums.query(i,i);
                sums.inc(i,i,-cdist+dist1);
            }
            //i-1 -> changed i
            if(i-1 >= 1){
                dist2 = d(points[i-1], {x,y});
                ll cdist = sums.query(i-1,i-1);
                sums.inc(i-1,i-1,-cdist+dist2);
            }

            ll s1, s2, s3;

            // i-1 -> changed i -> i+1
            if(i+1 <= n && i-1 >= 1){
                s1 = dist1 + dist2 - d(points[i-1], points[i+1]);
                ll csave = saved.query(i-1,i-1);
                saved.inc(i-1,i-1,-csave+s1);
            }
            // i-2 -> i-1 -> changed i
            if(i-2 >= 1){
                s2 = d(points[i-2], points[i-1]) + dist2 - d(points[i-2], {x,y});
                ll csave = saved.query(i-2,i-2);
                saved.inc(i-2,i-2,-csave+s2);
            }
            //changed i -> i+1 -> i+2
            if(i+2 <= n){
                s3 = dist1 + d(points[i+1], points[i+2]) - d({x,y}, points[i+2]);
                ll csave = saved.query(i,i);
                saved.inc(i,i,-csave+s3);
            }
            points[i] = {x,y};
        }
        else{
            ll u, v; cin >> u >> v;
            // cout << sums.query(u,v-1) << " " << saved.query(u,v-2) << endl;
           // ll res; fin >> res;
            // if(res == sums.query(u,v-1) - saved.query(u,v-2)){
            //     cout << res << " " << sums.query(u,v-1) - saved.query(u,v-2) << endl;
            // }
            out(sums.query(u,v-1) - saved.query(u,v-2));
        }

        
	}
    // for(int u = 1; u <= 3; u++){
    //     for(int v = 1; v <= 3; v++){
    //         cout << u << " " << v << " " << saved.query(u,v) << endl;
    //     }
    // }




}



