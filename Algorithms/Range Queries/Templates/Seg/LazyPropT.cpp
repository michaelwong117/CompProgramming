// 0 indexed queries, 1-idxed array seg
// seg size n+1 always!!
template<class T>
class segtree {
public:
    bool sum = true; //true for sum queries
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
