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

// 0 indexed
template<class T>
class segtree1 {
public:
    bool sum = false; //true for sum queries
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

    void inc(int a, int b, ll diff) {
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

    void inc(int node, int l, int r, int a, int b, ll diff) {
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

    void inc(int a, int b, ll diff) {
        inc(1, 0, len - 1, a, b, diff);
    }

private:
    T f(T a, T b) { //change for different problems
        return min(a,b);
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
        if (l > b || r < a)  return numeric_limits<T>::max();

        if (l >= a && r <= b) return seg[node];
        
        
        int mid = (l + r) / 2;
        T n1 = query(node * 2, l, mid, a, b);
        T n2 = query(node * 2 + 1, mid + 1, r, a, b);
        if (n1 == numeric_limits<T>::max()) return n2;
        if (n2 == numeric_limits<T>::max()) return n1;
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

    void inc(int node, int l, int r, int a, int b, ll diff) {
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

int n;
vl l, r;
ll x, y;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		l.pb(x); r.pb(y);
	}
	segtree1<ll> MX(l);
	segtree2<ll> MN(r);
	ll mx = 0;
	for(int i = 0; i < n; i++){
		MX.inc(i,i,-10000000000LL); MN.inc(i,i,10000000000LL);
		mx = max(mx, MN.query(0, n) - MX.query(0, n));
		MX.inc(i,i,10000000000LL); MN.inc(i,i,-10000000000LL);
	}
	cout << mx << endl;
}
